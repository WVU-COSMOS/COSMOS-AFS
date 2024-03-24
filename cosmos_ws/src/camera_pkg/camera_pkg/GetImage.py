#!/usr/bin/env python3
import rclpy
import numpy as np
import io
import requests
from rclpy.node import Node
from sensor_msgs.msg import Image
from PIL import Image as PILImage
from cosmos_interfaces.msg import Camera

class GetImage(Node): 
    def __init__(self):
        super().__init__("GetImage")
        self.get_logger().info("GetImage Node has been started!")
        # Defining Camera IP
        self.ip = "10.0.0.19"
        # Creating Publisher and Timer for publishing captured imaged
        # Note, image is being published in the topic called 'Image_Captured'
        self.publisher_ = self.create_publisher(Image, "Image_Captured", 10)
        self.sm_cam_publisher_ = self.create_publisher(Camera, "cam_sm_command", 10)

        # Subscriber
        self.cam_sm_subscriber = self.create_subscription(Camera, "cam_sm_command", self.cam_sm_command_callback, 10)

        #self.timer_ = self.create_timer(3.0, self.publish_image)

        self.img_num = 0

    def cam_sm_command_callback(self, msg):
        if(msg.to_node == "GetImage" and msg.next_img == True):
            self.img_num = msg.img_num
            self.get_logger().info(f"Getting Image number {msg.img_num}!")
            self.publish_image()

    # Function that gets a reponse from camera, converts it into array and publishes every 3 seconds
    def publish_image(self):

        response = requests.get(f"http://{self.ip}/capture")
        img = np.array(PILImage.open(io.BytesIO(response.content)))

        msg = Image()
        msg.height = img.shape[0]
        msg.width = img.shape[1]
        msg.encoding = 'rgb8'
        msg.data = img.tobytes()

        self.publisher_.publish(msg)

        command = Camera()
        command.from_node = "GetImage"
        command.to_node = "CameraSM"
        command.img_num = self.img_num + 1
        command.is_done = True
        self.sm_cam_publisher_.publish(command)



def main(args=None):
    rclpy.init(args=args)
    node = GetImage()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()