#!/usr/bin/env python3
import rclpy
import numpy as np
import cv2
from rclpy.node import Node
from sensor_msgs.msg import Image
from cosmos_interfaces.msg import Camera

class ImageToPixel(Node):
    def __init__(self):
        super().__init__("ImageToPixel")
        self.get_logger().info("ImageToPixel Node has been started!")

        # Subscribers
        self.img_sub_ = self.create_subscription(Image, "Image_Captured", self.img_callback, 10)

        # Publishers
        self.uv_pub_ = self.create_publisher(Camera, "uv_coordinates", 10)

        # Variables
        self.image = Image()
        self.images = []
        self.missions_params = {1: (np.array([100, 0, 0], dtype=np.uint8), np.array([255, 75, 75], dtype=np.uint8))}
        self.uu = 240
        self.vv = 240
        self.uu_2 = self.uu / 2
        self.vv_2 = self.vv / 2        
        self.format = 'med'
            
        # field of view divided by two (i.e., half-angle), ordered as [v, u]:
        self.fov_2 = {'med': [np.arctan(41/108), np.arctan(41/108)],
                      'UXGA': [np.arctan(5.5 / 12.75), np.arctan(5 / 12.75)]}

        # radians per pixel:
        self.rad_u = self.fov_2[self.format][1] / self.uu_2
        self.rad_v = self.fov_2[self.format][0] / self.vv_2

    def img_callback(self, msg):
        if msg is not None:
            img_height = msg.height
            img_width = msg.width
            self.uu = img_height
            self.vv = img_width
            img = np.frombuffer(msg.data, dtype=np.uint8).reshape((img_height, img_width, -1))
            #self.get_logger().info("Image Received!")

            self.images.append(img)

            [u, v] = self.image_to_pixel(img, 1)

            if(u != -50 and v != -50):
                uv_msg = Camera()
                uv_msg.is_target = True
                uv_msg.u = u
                uv_msg.v = v
                self.uv_pub_.publish(uv_msg)
            else:
               uv_msg = Camera()
               uv_msg.is_target = False
               self.uv_pub_.publish(uv_msg)

        else:
            self.get_logger().warning("Received empty image message!")

        
    def image_to_pixel(self, img, mission, **kwargs):
        kwargs_default = {'circle': 0, 'ReturnImage': 0}
        kwargs_expected = kwargs_default.keys()
        for kwarg in kwargs.keys():
            if kwarg not in kwargs_expected:
                raise ValueError(f"Unexpected keyword argument: {kwarg}")
            else:
                kwargs_default[kwarg] = kwargs.get(kwarg, kwargs_default.get(kwarg))
        circle = kwargs_default.get('circle')

        try:
            mission_params = self.missions_params.get(mission)
            rgb_lb = mission_params[0]
            rgb_ub = mission_params[1]
        except:
            raise ValueError(f"Mission {mission} is not currently supported.")

        # process the image:
        uu = self.uu  # = img.shape[0]
        vv = self.vv  # = img.shape[1]
        bw = np.zeros([uu, vv], dtype=bool)
        for u in range(uu):
            for v in range(vv):
                if all(rgb_lb <= img[u, v, :]) and all(img[u, v, :] <= rgb_ub):
                    bw[u, v] = True

        con_rgb = np.zeros_like(img, dtype=np.uint8) + 255
        try:
            # convert b/w image to contours
            con, _ = cv2.findContours(bw.astype(np.uint8), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
            con_max = max(con, key=cv2.contourArea)

            # maybe smooth contour (https://stackoverflow.com/questions/66753026/opencv-smoother-contour)

            # calculate the center of mass (centroid) of the largest contour
            m = cv2.moments(con_max)
            u = int(m['m10'] / m['m00'])
            v = int(m['m01'] / m['m00'])

            if circle:  # then draw a circle at the center of the largest contour (i.e., the target)
                con_rgb[bw] = img[bw]
                #cv2.circle(con_rgb, (u, v), 6, (0, 255, 0), -1)

        except:
            u = -50
            v = -50

        return [u, v]

def main(args=None):
    rclpy.init(args=args)
    node = ImageToPixel()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()