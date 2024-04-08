# ROS commands for developing COSMOS-AFS

## Environment

Clone main GitHub branch, create new branch, and set new branch as current:
```cmd
git clone https://github.com/WVU-COSMOS/COSMOS-AFS.git
git branch branch_name
git checkout branch_name
```

Add to the ```.bashrc``` file if not already done:
```cmd
source /opt/ros/humble/setup.bash
source ~/COSMOS-AFS/cosmos_ws/install/local_setup.sh
```

Then, each time after opening VS Code:
```cmd
source .bashrc
```

## Building

Navigate to the ```cosmos_ws``` directory:
```cmd
cd COSMOS-AFS/cosmos_ws
```

Build (without override):
```cmd
colcon build
```

Build (with override):
```cmd
colcon build --allow-overriding cosmos_interfaces
```

After building and before starting nodes:
```cmd
source install/setup.bash
```

## Nodes

Open parallel terminals, one per node:
```cmd
terminator
```

Or, if not debugging and launching all nodes at once:
```cmd
ros2 launch cosmos_bringup cosmos.launch.py
```

Start the nodes as follows:

<!-- GCS (Ground Control Station):
```cmd
ros2 run ground_control_pkg GCS
``` -->

SM (State Machine):
```cmd
ros2 run state_machine_pkg SM
```

ANT (Acquisition and Tracking, i.e., state machine for camera-related nodes)
```cmd
ros2 run acquisition_and_tracking_pkg ANT
```

GetImg
```cmd
ros2 run acquisition_and_tracking_pkg GetImg
```

ImgToDCM
```cmd
ros2 run acquisition_and_tracking_pkg ImgToDCM
```

X (Dynamics / integration of state vector)
```cmd
ros2 run dynamics_pkg X
```

more
```cmd

```



## Sending messages

Simulate user-selected GCS mission:
```cmd
ros2 topic pub --once /gcs cosmos_interfaces/msg/GCS "{mission: 1111}"
```

## Other considerations for building on R-Pi

The ODE solver, ```scipy.integrate.solve_ivp```, requires older numpy versions so ensure the R-Pi environment prior to building has:
```cmd
pip install 'numpy>=1.17.3,<1.25.0'
```

If the most current numpy is already installed and the version needs to be changed,
```cmd
pip install 'numpy>=1.17.3,<1.25.0' --force-reinstall
```
