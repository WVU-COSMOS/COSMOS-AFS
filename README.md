![COSMOS-AFS-logo](/docs/_static/cosmos_color_horizontal.png)

# Manual

## Contents

<!-- toc -->

- [About](#about)
- [Ground Control Station (GCS) Commands](#ground-control-station-gcs-commands)
- [Flow of CameraSM (i.e., Track Missions)](#flow-of-camerasm-ie-track-missions)
- [Flow of Kinematics](#flow-of-kinematics)
- [ROS Nodes, Topics, and Messages (in progress)](#ros-nodes-topics-and-messages-in-progress)
- [Documentation](#documentation)
- [Contact](#contact)

<!-- tocstop -->

## About

Manual for users and developers of the Avionics and Flight Software package for West Virginia University's 2023-24 Aerospace Senior Design Capstone, COSMOS, a Small Sat intended for classroom use in secondary-higher education.

## Ground Control Station (GCS) Commands

From a GUI, the user will select a mission corresponding to an integer which is published internally. The list of missions here is a template and brainstorm of how integers may be used to index missions. See [*GroundStation.py*](Ground_Station/GroundStation.py) for an actual list of missions, and ensure the missions listed there are supported in [*state_machine_node.cpp*](cosmos_ws/src/state_machine_pkg/src/state_machine_node.cpp). 

As an example for simulating a GCS command in ROS, tracking red light with the nontracking mission being to orbit is called like
```cmd
ros2 topic pub --once /gcs cosmos_interfaces/msg/GCS "{mission: 1120}"
```

The missions here are intended to be defined as ```enum class MISSION : uint16_t``` in *state_machine_node.hpp* and are again just a template and brainstorm.

| Index | Type | Mission | Description |
|---|---|---|---|
| 00 | Reset | RESET_ALL | power off all (i.e., motors and camera) |
| 01 | " | RESET_MOTORS | power off motors |
| 02 | " | RESET_CAMERA | power off camera |
| $\dots$ | " | - | - |
| 05 | Desaturate | DESATURATE_ALL | set RPMs near zero (i.e., desaturate reaction wheels) |
| 06 | " | DESATURATE_RW1 | [NOT FOR USER] set RPM of RW 1 near zero (i.e., desaturate reaction wheel 1); triggered internally |
| 07 | " | DESATURATE_RW2 | [NOT FOR USER] set RPM of RW 2 near zero (i.e., desaturate reaction wheel 2); triggered internally |
| 08 | " | DESATURATE_RW3 | [NOT FOR USER] set RPM of RW 3 near zero (i.e., desaturate reaction wheel 3); triggered internally |
| $\dots$ | " | - | - |
| 10 | Pause | PAUSE_RPMS | do nothing / maintain current RPMs (i.e., $\dot{R}=\mathbf{0}$) |
| 11 | " | PAUSE_ATTITUDE | settle at current attitude (i.e., $R=\mathbf{0}$) |
| $\dots$ | " | - | - |
| 20 | Orbit | ORBIT_1 | follow quaternions from first orbit file |
| $\dots$ | " | - | - |
| 30 | Solar | SOLAR_CHARGE | charge solar panels by pointing corner toward known stationary light source |
| $\dots$ | " | - | - |
| 40 | Spin | SPIN_MAX_CCW | max spin (CCW) |
| 41 | Spin | SPIN_MAX_CW | max spin (CW) |
| $\dots$ | " | - | - |
| 10*xx* | Track | TRACK_ARUCO__*XX* | ArUco code, with secondary *XX* command |
| 11*xx* | " | TRACK_RED__*XX* | red light, with secondary *XX* command |
| $\dots$ | " | - | - |
| 10000 | [INTERNAL] | [INTERNAL] | [NOT FOR USER] gives Kinematics green light to propagate state vector using its currently stored values of $(R, t, R_0, t_0)$ |
| $\dots$ | " | " | [NOT FOR USER] - |

The last two digits of the Track missions are the nontracking mission to perform when the target is not detected for so many frames. This is governed by CameraSM, such that StateMachine interprets 10*xx* or 11*xx* as a single mission. Supported nontracking missions are *xx* = [05, 10, 11, 20, 30, 40, 41].

## Flow of CameraSM (i.e., Track Missions)

This method is outdated as of April 24th, 2024, but one method to continuously search for a target while performing a nontracking mission (e.g., optimally charging solar panels) until a target is spotted is as follows. Ideally, the StateMachine node should not be driven by CameraSM or anything other than the single message sent from GCS, which is why this method is outdated.

1. User selects "Track/TRACK_ARUCO_*XX*" or "Track/TRACK_RED_*XX*" on GUI, then corresponding mission index is published.
    -   ```cmd
        ros2 topic pub --once /gcs cosmos_interfaces/msg/GCS "{mission: 1120}"
        ```
1. StateMachine receives message and enters the Track recipe. While there are specific recipes for other missions, the recipe for all Track missions is the same—publish the mission to CameraSM.
1. CameraSM parses the four-digit mission into the tracking mission (i.e., TRACK_ARUCO or TRACK_RED) and the nontracking mission. Both are stored as class attributes.
1. CameraSM requests image by publishing to GetImage.
1. GetImage publishes image to ImageToDCM if success, then returns the image timestamp $t$ and status (i.e., success or failure) to CameraSM. Timestamp is saved by CameraSM as a class attribute.
1. CameraSM gives green light to ImageToDCM if success, passing the target (i.e., TRACK_ARUCO or TRACK_RED) to search for.
1. ImageToDCM returns $R$ and ```is_target``` to CameraSM.
1. CameraSM, if receiving...
    - no target, increases miss count. If miss exceeds patience threshold, CameraSM informs StateMachine to start nontracking mission (which may already have been started, in which case StateMachine ignores).
    - target, resets miss count. Then CameraSM, if the target is...
        - first target in series, saves $R$ as class attribute $R_0$ (and sets $t_0=t$).
        - second target or beyond, if...
            - second target, informs StateMachine to abort nontracking mission (which may already have been aborted, in which case StateMachine ignores). The previously saved $(R_0, t_0)$ are then published to Kinematics. Immediately after, ...
                - the incoming $R$ (and $t$) are published. CameraSM requests StateMachine to give Kinematics green light to propagate state vector.
            - beyond second target, ...
                - "
1. CameraSM repeats Steps 4-8 until Track mission is aborted by StateMachine. (But now, Step 4 is within callback of ImageToDCM instead of callback for StateMachine).

## Flow of Kinematics

The following is outdated because Kinematics, as of April 24th, 2024, is intended to propagate the state vector without requiring a green light from StateMachine. To achieve this, it is thought that ImageToDCM will send *DCM.msg* but with an additional parameter *is_first*. That way, Kinematics receives (*is_first*, *R*, *t*). If *is_first* is false, then Kinematics should propagate the state vector.

1. Kinematics, when receiving a message from the "dcm" topic, updates its class attributes $(R_0, t_0)$ with the currently saved $(R, t)$ attributes. Then, the incoming $(R, t)$ are saved.
1. When receiving green light from StateMachine, the currently saved $(R, t, R_0, t_0)$ are used along with the saved $(x_0, z_0)$ attributes to propagate the state vector by calling the ODE solver. The updated state vector $x$ and error $z$ are published to Communications and the status of Kinematics (i.e., success or failure) is returned to StateMachine.
1. StateMachine, if success, gives green light to Communications to process the state vector it has just saved as a class attribute in order to write the new RPM's to the motors.
1. Communications, receiving the green light, grabs the last three values of the state vector (i.e., RPM's) and checks if they exceed the limits of the motors. If they exceed, Communications thresholds the RPM's to the motors' max speed. Communications then writes to the motors. The status (i.e., success, failure, or limited) is then returned to StateMachine.

## ROS Nodes, Topics, and Messages (in progress)

The following is outdated but provides a template for keeping track of nodes and topics.

| Node | Topics | Description |
|---|---|---|
| GCS | gcs | Ground Control Station |
| Communications | comms | |
| StateMachine | comms, gcs, sm | |
| CameraSM | cam, sm | |
| GetImage | cam, img | |
| ImageToDCM | cam, dcm, img | |
| Kinematics | dcm, sm, x | |

The following is outdated but provides a template for keeping track of messages.

| Message | Parameters | Description |
|---|---|---|
| Cam | uint16 command <br> string to_node <br> string from_node <br> bool is_start <br> bool is_abort <br> float64[9] dcm <br> float64 t | |
| Comms | | |
| DCM | float64[9] dcm <br> float64 t | 
| GCS | uint16 mission | |
| Image | [SEE ROS DOCS] | ```from sensor_msgs.msg import Image``` |
| SM | uint16 command <br> string to_node <br> string from_node <br> bool is_start <br> bool is_abort | |
| X | float64[10] x <br> float64[3] z | |

## Documentation

Some documentation is stored in the *docs* folder. Included, as of April 24th, 2024, are
- [ros_commands](/docs/ros_commands.md)
- [attitude_thresholding_without_IMU](/docs/attitude_thresholding_without_IMU.md)
- [attitude_thresholding_with_IMU](/docs/attitude_thresholding_with_IMU.md)

## Contact

West Virginia University, Morgantown, WV

jakepkrell@gmail.com

etc.

## Citations

If referencing this project, please consult Dr. Andrew Rhodes on how to cite. The preferred citation(s) may change over time.
