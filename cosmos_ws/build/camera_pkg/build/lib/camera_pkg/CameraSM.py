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
        self.sm_cam_subscriber = self.create_subscription(Camera, "cam_sm_command", self.sm_cam_command_callback, 10)

        # Publishers
        self.sm_cam_publisher_ = self.create_publisher(Camera, "cam_sm_command", 10)

        # Variables
        self.mission_start = False
        self.img_num = 1

    def sm_command_callback(self, msg):
        if(msg.to_node == "Camera" and self.mission_start == False and msg.is_abort == False):
            self.mission_start = True
            self.get_logger().info("Camera Mission starting!")
            self.publish_msg(1)
        elif(msg.is_about == True):
            self.get_logger().info("Mission Aborted")
            self.publish_msg(3)

    def sm_cam_command_callback(self, msg):
        if(msg.to_node == "CameraSM" and msg.is_done == True):
            if(msg.from_node == "GetImage"):
                self.get_logger().info("Image Captured!")
                self.img_num = msg.img_num
                self.publish_msg(2)

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

def main(args=None):
    rclpy.init(args=args)
    node = CameraSM() 
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()