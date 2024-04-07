#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from cosmos_interfaces.msg import StateMachine
from cosmos_interfaces.msg import Camera
from cosmos_interfaces.msg import DCM


class CameraSM(Node):
    def __init__(self):
        super().__init__("CameraSM") 
        self.get_logger().info("CameraSM Node has been started!")

        # Subscribers
        self.sm_sub_ = self.create_subscription(StateMachine, "sm_command", self.sm_command_callback, 10)
        #self.sm_cam_subscriber = self.create_subscription(Camera, "cam_sm_command", self.sm_cam_command_callback, 10)
        self.dcm_sub_ = self.create_subscription(DCM, "DCM", self.dcm_callback, 10)

        # Publishers
        self.sm_cam_pub_ = self.create_publisher(Camera, "cam_sm_command", 10)
        self.sm_pub_ = self.create_publisher(StateMachine, "sm_command", 10)

        # Variables
        self.mission_start = False
        self.current_mission = 0
        self.img_num = 1
        self.is_target = False

        # Initialize non-tunable parameters:
        self.t_fs = 1 / self.fs  # sampling period
        self.patience = int(self.fs * self.t_patience - 1)  # frames-1 (rounded) after target exits ..., prior to nontracking mode 
        self.miss = self.patience + 1  # count of consecutive frames with missing target, initialize miss > patience
        self.is_tracking = False  # true if in tracking mode (i.e., not first image in sequence)
        self.is_first = True  # true if image is first in sequence prior to nontracking
        self.is_second = False

        # Mission Numbers
        self.tracking_mode = 4
        self.move_by_target = 5
        

    def sm_command_callback(self, msg):
        if(msg.to_node == "Camera" and self.mission_start == False and msg.is_abort == False):
            if(msg.mission == self.tracking_mode):
                self.current_mission = msg.mission
                self.mission_start = True
                self.get_logger().info("Camera Mission starting!")
                self.find_target()

            elif(msg.mission == self.move_by_target):
                self.current_mission = msg.mission
                self.mission_start = True
                self.get_logger().info("Camera Mission starting!")
                self.find_target()

        elif msg.is_abort:
            self.get_logger().info("Mission Aborted")
            self.publish_msg(3)

    def dcm_callback(self, msg):
        if(self.current_mission == self.tracking_mode):
            if(msg.is_target):
                self.miss = 0  # reset count

                if self.is_first:                
                    self.is_first = False  # change for next target, if miss < patience then will propagate state vector
                    self.is_second = True  # true if image is second in sequence prior to nontracking (required to allow ANT to send first [(R0,t0),(R,t)] pair to Kinematics together)
                else:  # publish [(R0,t0), (R,t)] subsequently if second, or just (R,t), then give SM the command to propagate state vector    
                    # End nontracking mission and publish (R0, t0) if first pair in sequence:
                    if self.is_second:  # publish [(R0,t0), (R,t)] subsequently (to avoid first (R,t) interfering with nontracking mission)
                        self.is_second = False  # change for next target
                        self.get_logger().info("Camera Mission Done!")
                        command = StateMachine()
                        command.from_node = "Camera"
                        command.to_node = "StateMachine"
                        command.is_done = True
                        command.mission = self.current_mission
                        command.is_abort = False
                        self.sm_pub_.publish(command)

                        command = Camera()
                        command.is_start = False
                        command.to_node = "GetImage"
                        command.img_num = self.img_num
                        command.next_img = False
                        command.is_abort = False
                        command.is_target = True
                        self.sm_cam_pub_.publish(command)
            else:
                self.miss += 1

            if self.miss > self.patience:  # publish nontracking command to SM (which gets aborted above if R0 and R)
                self.is_first = True
        
        elif(self.current_mission == self.move_by_target):
            if(msg.is_target):
                self.get_logger().info("Camera Mission Done!")
                command = StateMachine()
                command.from_node = "Camera"
                command.to_node = "StateMachine"
                command.is_done = True
                command.mission = self.current_mission
                command.is_abort = False
                self.sm_pub_.publish(command)

                command = Camera()
                command.is_start = False
                command.to_node = "GetImage"
                command.img_num = self.img_num
                command.next_img = False
                command.is_abort = False
                command.is_target = True
                self.sm_cam_pub_.publish(command)
            else:
                self.find_target()


    def publish_msg(self, num):
        if(self.mission_start == True and num == 1):
            command = Camera()
            command.is_start = True
            command.to_node = "GetImage"
            command.img_num = self.img_num
            command.next_img = True
            command.is_abort = False
            command.is_target = False
            self.sm_cam_pub_.publish(command)

        elif(self.mission_start == True and num == 2):
            command = Camera()
            command.is_start = True
            command.to_node = "GetImage"
            command.img_num = self.img_num
            command.next_img = True
            command.is_abort = False
            command.is_target = False
            self.sm_cam_pub_.publish(command)

    def find_target(self):
        if not self.is_target:
            command = Camera()
            command.is_start = True
            command.to_node = "GetImage"
            command.img_num = self.img_num
            command.next_img = True
            command.is_abort = False
            command.is_target = False
            self.sm_cam_pub_.publish(command)

def main(args=None):
    rclpy.init(args=args)
    node = CameraSM() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()