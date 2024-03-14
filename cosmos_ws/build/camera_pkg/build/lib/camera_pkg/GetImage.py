#!/usr/bin/env python3
import rclpy
import numpy as np
import io
import requests
from rclpy.node import Node
from sensor_msgs.msg import Image
from PIL import Image as PILImage

class GetImage(Node): 
    def __init__(self):
        super().__init__("GetImage")
        self.get_logger().info("GetImage Node has been started!")
        # Defining Camera IP
        self.ip = "10.0.0.18"
        # Creating Publisher and Timer for publishing captured imaged
        # Note, image is being published in the topic called 'Image_Captured'
        self.publisher_ = self.create_publisher(Image, "Image_Captured", 10)
        self.timer_ = self.create_timer(3.0, self.publish_image)

    # Function that gets a reponse from camera, converts it into array and publishes every 3 seconds
    def publish_image(self):
        try:
            response = requests.get(f"http://{self.ip}/capture")
            img = np.array(PILImage.open(io.BytesIO(response.content)))
        except Exception as e:
            self.get_logger().info(f"Could not capture image. Exception: {str(e)}")
        
        msg = Image()
        msg.height = img.shape[0]
        msg.width = img.shape[1]
        msg.encoding = 'rgb8'
        msg.data = img.tobytes()

        self.publisher_.publish(msg)
        self.get_logger().info('Publishing image with shape: %s' % (img.shape,))



def main(args=None):
    rclpy.init(args=args)
    node = GetImage()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()