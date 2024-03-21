"""
Development Information:
COSMOS-AFS


Primary Developers Contact Information:
    - Vinicius D. Ferreira (VDF)
        - vdf00001@mix.wvu.edu
    - Jacob P. Krell (JPK)
        - jpk0024@mix.wvu.edu

Development History:
Date                Developer       Comments
-------------       ------------    ------------------------------------------------------------------------------------
Mar. 20, 2024       JPK             Converted VDF's C++ code to Python using ChatGPT; Attempted to layout structure of 
                                    code from 'COSMOS_AFS.py';
"""
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
from std_msgs.msg import Float64
from cosmos_interfaces.msg import Position
from cosmos_interfaces.msg import Camera__capture_and_process
from cosmos_interfaces.msg import Attitude__kinematics_and_ode45
from cosmos_interfaces.msg import ReactionWheels
from cosmos_interfaces.msg import Attitude__nontracking
import numpy as np
import time
import copy


class StateMachine(Node):

    def __init__(self):
        super().__init__('state_machine')
        self.g_subscriber = self.create_subscription(
            Int32, 'gStation_Command', self.g_station_callback, 10)
        self.position_pub = self.create_publisher(
            Position, 'attitude_command', 10)
        self.get_logger().info('State Machine has been started!')
        self.curr_position = 0

        # [JPK] Parameters for missions in format {msg.data: {params}}:
        self.missions = {10: {'mission': 0}, 11: {'mission': 1}}

        # [JPK] For camera, attitude, motors publish/subscribe:

        self.pub_camera = self.create_publisher(Camera__capture_and_process, 'camera_topic', 10)
        self.sub_camera = self.create_subscription(
            [bool, Float64[10]], 'camera_topic', self.camera_callback, 10)
            # (target, t, R) returned by 'Camera.capture_and_process'

        self.pub_attitude = self.create_publisher(Attitude__kinematics_and_ode45, 'attitude_topic', 10)
        self.sub_attitude = self.create_subscription(
            Float64[13], 'attitude_topic', self.attitude_callback, 10)
            # (x, z) returned by 'Attitude.kinematics_and_ode45'

        self.pub_comms = self.create_publisher(ReactionWheels, 'comms_topic', 10)

        self.pub_nontracking = self.create_publisher(Attitude__nontracking, 'nontracking_topic', 10)

        # [JPK] For initialization:
        self.response_received = False  # for waiting for subscription immediately after publishing
        self.tracking = False
        self.patience = 10  # number of frames required to be considered "no target", and exit tracking mode
        self.miss = self.patience + 1  # initialize to non-tracking
        self.x0 = np.zeros([10, 1])  # state vector
        self.z0 = np.zeros([3, 1])  # error for kinematics

    # Callbacks:

    def g_station_callback(self, msg):
        """msg is limited to int indexing mission."""

        self.get_logger().info('Mission Selected: %d' % msg.data)

        # Position (test):

        if msg.data == 1:
            command = Position()
            command.mission = msg.data
            command.current_position = self.curr_position
            command.next_position = self.curr_position + 1
            command.is_running = True
            self.position_pub.publish(command)
            self.get_logger().info('Mission Published: %d' % msg.data)
            self.curr_position += 1

        # The below was added by JPK following 'pseudocode_ros__v2.pdf' and above syntax:

        # Acquisition and Tracking:

        if 9 < msg.data < 20:  # == # 'Acquisition and Tracking':
            """10's used for Acquisition and Tracking missions."""
            self.acquisition_and_tracking(msg.data)  # call mission

    def camera_callback(self, msg_camera):
        """Define R and t after 'self.pub_camera.publish(command)'."""
        self.target = msg_camera.data[0]  # boolean
        self.t = msg_camera.data[1]
        if self.target is True:
            self.R = np.array([msg_camera.data[2:5], msg_camera.data[5:8], msg_camera.data[8:11]])
        else:
            self.R = None  # no target detected
        self.response_received = True
        return

    def attitude_callback(self, msg_attitude):
        """Define x and z after 'self.pub_attitude.publish(command)'."""
        self.x = msg_attitude.data[:10]
        self.z = msg_attitude.data[10::]
        self.response_received = True
        return

    # The below are miscellaneous repeat operations:

    def update(self):
        self.R0 = copy.copy(self.R)
        self.t0 = copy.copy(self.t0)
        self.x0 = copy.copy(self.x)
        self.z0 = copy.copy(self.z)
        return

    def wait_for_response(self, lag):
        """Wait for 'lag' seconds to receive response after publishing. Note 'response_received=True' must be set in
        subscription callback functions."""
        t_start = time.time()
        while self.response_received is False:
            if time.time() - t_start > lag:
                self.error = True
                break  # error/glitch/lag in hardware/software, so break
            rclpy.spin_once(self)
        if self.response_received is True:
            self.error = False
            self.response_received = False  # reset
        return

    def update_x_and_rw(self):
        """Calculate kinematics and send new spin rates to RW's."""
        # Kinematics (i.e., Attitude):
        command = self.cmd_kinematics_and_ode45()
        self.pub_attitude.publish(command)
        self.wait_for_response(2.5)  # --> x, z
        if self.error is True:
            print("Kinematic calculations failed.")
        else:

            # Motors (i.e., Reaction Wheels):
            command = self.cmd_motors(self.x[7::])  # RW spin rates
            self.pub_comms.publish(command)

            # Update for next iteration:
            self.update()

    # The below methods are for defining commands to publish:

    def cmd_capture_and_process(self, msg_data):
        """Pseudocode: R, t = Camera.capture_and_process(msg.mission)"""
        command = Camera__capture_and_process()
        command.mission = self.missions[msg_data]['mission']
        return command

    def cmd_kinematics_and_ode45(self):
        """Pseudocode: x, z = Attitude.kinematics_and_ode45(R, t, R0, t0, x0, z0)"""
        command = Attitude__kinematics_and_ode45()
        command.R = self.R
        command.t = self.t
        command.R0 = self.R0
        command.t0 = self.t0
        command.x0 = self.x0
        command.z0 = self.z0
        return command

    def cmd_motors(self, rpms):
        """Pseudocode: Comms.publish(x[7::])"""
        command = ReactionWheels()

        # The following is outdated but shows the general idea:
        if rpms[0] > 0:
            command.motor_x = 1
            command.speed_x = rpms[0]
        else:
            command.motor_x = 0
            command.motor_x = np.abs(rpms[0])
        if rpms[1] > 0:
            command.motor_y = 1
            command.speed_y = rpms[1]
        else:
            command.motor_y = 0
            command.motor_y = np.abs(rpms[1])
        if rpms[2] > 0:
            command.motor_z = 1
            command.speed_z = rpms[2]
        else:
            command.motor_z = 0
            command.motor_z = np.abs(rpms[2])

        command.time_x = self.dt  # need to define based on acquisition and tracking closed-loop sampling rates
        command.time_y = self.dt
        command.time_z = self.dt

        return command

    def cmd_nontracking(self, mode):
        command = Attitude__nontracking()
        command.mode = mode
        return command

    # The below are missions called by 'g_station_callback':

    def acquisition_and_tracking(self, mission):
        """See 'doc/pseudocode_ros__v3.docx' for guidance."""

        command = self.cmd_capture_and_process(mission)
        self.pub_camera.publish(command)
        self.wait_for_response(5)  # --> R, t

        if self.error is True:
            print("Camera failed.")
        else:

            if self.target is True:  # target
                self.miss = 0
                if self.tracking is False:  # first target in series
                    self.tracking = True
                else:  # ‘Tracking’
                    self.update_x_and_rw()

            else:  # no target
                self.miss += 1  # count consecutive frames without target

            if self.miss > self.patience:  # Acquisition (i.e., non-Tracking)
                self.tracking = False

                command = self.cmd_nontracking(self.nontracking_mode)
                self.pub_nontracking.publish(command)
                self.wait_for_response(2.5)  # --> x, z

                if self.error is True:
                    print("Non-Tracking mode failed.")
                else:
                    self.update_x_and_rw()


def main(args=None):
    rclpy.init(args=args)
    state_machine = StateMachine()
    rclpy.spin(state_machine)
    rclpy.shutdown()


if __name__ == '__main__':
    main()

