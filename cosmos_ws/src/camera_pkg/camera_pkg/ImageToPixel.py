#!/usr/bin/env python3
import rclpy
import numpy as np
import cv2
from rclpy.node import Node
from sensor_msgs.msg import Image

class ImageToPixel(Node):
    def __init__(self):
        super().__init__("ImageToPixel")
        self.get_logger().info("ImageToPixel Node has been started!")

        self.image = Image()
        self.img_sub_ = self.create_subscription(Image, "Image_Captured", self.img_callback, 10)

    def img_callback(self, msg):
        img_height = msg.height
        img_width = msg.width
        img_data = np.frombuffer(msg.data, dtype=np.uint8).reshape((img_height, img_width, -1))

        # Example processing: display the image using OpenCV
        cv2.imshow('Received Image', img_data)
        cv2.waitKey(1)


def main(args=None):
    rclpy.init(args=args)
    node = ImageToPixel()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()