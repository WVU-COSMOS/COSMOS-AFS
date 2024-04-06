#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from cosmos_interfaces.msg import StateMachine
from cosmos_interfaces.msg import Camera


class CameraSM(Node):
    def __init__(self):
        super().__init__("CameraSM") 
        self.get_logger().info("CameraSM Node has been started!")

        # Subscribers
        self.sm_subscriber = self.create_subscription(StateMachine, "sm_command", self.sm_command_callback, 10)
        #self.sm_cam_subscriber = self.create_subscription(Camera, "cam_sm_command", self.sm_cam_command_callback, 10)
        self.uv_coord_subscriber = self.create_subscription(Camera, "uv_coordinates", self.uv_coord_callback, 10)

        # Publishers
        self.sm_cam_publisher_ = self.create_publisher(Camera, "cam_sm_command", 10)
        self.sm_publisher_ = self.create_publisher(StateMachine, "sm_command", 10)

        # Variables
        self.mission_start = False
        self.current_mission = 0
        self.img_num = 1
        self.move_by_target = 5
        self.is_target = False

    def sm_command_callback(self, msg):
        if(msg.to_node == "Camera" and self.mission_start == False and msg.is_abort == False):
            if(msg.mission == self.move_by_target):
                self.current_mission = msg.mission
                self.mission_start = True
                self.get_logger().info("Camera Mission starting!")
                self.find_target()
        elif msg.is_abort:
            self.get_logger().info("Mission Aborted")
            self.publish_msg(3)

    # def sm_cam_command_callback(self, msg):
    #     if(msg.to_node == "CameraSM" and msg.is_done == True):
    #         if(msg.from_node == "GetImage"):
    #             self.get_logger().info("Image Captured!")
    #             self.img_num = msg.img_num
    #             self.publish_msg(2)

    def uv_coord_callback(self, msg):
        if(self.current_mission == self.move_by_target and msg.is_target):
            self.get_logger().info("Camera Mission Done!")
            command = StateMachine()
            command.from_node = "Camera"
            command.to_node = "StateMachine"
            command.is_done = True
            command.mission = self.current_mission
            command.is_abort = False
            self.sm_publisher_.publish(command)

            command = Camera()
            command.is_start = False
            command.to_node = "GetImage"
            command.img_num = self.img_num
            command.next_img = False
            command.is_abort = False
            command.is_target = True
            self.sm_cam_publisher_.publish(command)
        elif(self.current_mission == self.move_by_target and not msg.is_target):
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
            self.sm_cam_publisher_.publish(command)

        elif(self.mission_start == True and num == 2):
            command = Camera()
            command.is_start = True
            command.to_node = "GetImage"
            command.img_num = self.img_num
            command.next_img = True
            command.is_abort = False
            command.is_target = False
            self.sm_cam_publisher_.publish(command)

    def find_target(self):
        if not self.is_target:
            command = Camera()
            command.is_start = True
            command.to_node = "GetImage"
            command.img_num = self.img_num
            command.next_img = True
            command.is_abort = False
            command.is_target = False
            self.sm_cam_publisher_.publish(command)

def main(args=None):
    rclpy.init(args=args)
    node = CameraSM() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()