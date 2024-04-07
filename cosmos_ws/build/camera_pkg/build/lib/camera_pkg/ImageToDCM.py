#!/usr/bin/env python3
import rclpy
import numpy as np
import cv2
from rclpy.node import Node
from sensor_msgs.msg import Image
from cosmos_interfaces.msg import Camera
from cosmos_interfaces.msg import DCM

class ImageToDCM(Node):
    def __init__(self):
        super().__init__("ImageToDCM")
        self.get_logger().info("ImageToDCM Node has been started!")

        # Subscribers
        self.img_sub_ = self.create_subscription(Image, "Image_Captured", self.img_callback, 10)

        # Publishers
        self.dcm_pub_ = self.create_publisher(DCM, "DCM", 10)

        # Variables
        self.image = Image()
        self.images = []
        self.mission_params = {1: (np.array([100, 0, 0], dtype=np.uint8), np.array([255, 75, 75], dtype=np.uint8))}
        self.uu = 240
        self.vv = 240
        self.uu_2 = self.uu / 2
        self.vv_2 = self.vv / 2        
        self.format = 'med'
        self.is_target = False

        self.mission = 1  # default to red light tracking
            
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

            self.images.append(img)

            dcm = self.image_to_dcm(img, 1)
            dcm_msg = DCM()

            if self.is_target:
                dcm_msg.is_target = True
                dcm_msg.dcm = dcm.flatten().tolist()
            else:
                dcm_msg.is_target = False

            self.dcm_pub_.publish(dcm_msg)  

        else:
            self.get_logger().warning("Received empty image message!")

        
    def image_to_dcm(self, img, mission):

        try:
            mission_params = self.mission_params.get(mission)
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

            dcm = self.pixel_to_dcm(u, v)
            self.is_target = True

        except Exception as exception:
            dcm = []  # value is ignored outside of function so 3x3 not needed here
            self.is_target = False

        return dcm
    
    def euler_to_dcm(self, theta):
        """"
        Convert Euler Angles to DCM assuming sequence is [u, v] for camera.
        
        theta == 3x1 ndarray (radians)

        Assuming Body Frame's x-axis is along u and y along v.
        """
        self.get_logger().info("Converting Euler to DCM...")

        c = np.cos(theta)
        s = np.sin(theta)

        dcm_u = np.array([[1, 0, 0], [0, c[0], s[0]], [0, -s[0], c[0]]])  # rotation about camera's u-axis (rightward horizontal), i.e., body's x-axis
        dcm_v = np.array([[c[0], 0, -s[0]], [0, 1, 0], [s[0], 0, c[0]]])  # rotation about camera's v-axis (downward vertical), i.e., body's y-axis

        return np.matmul(dcm_v, dcm_u)  # R = R2 * R1
    
    def pixel_to_dcm(self, u, v):
        """Calculate DCM from pixels. Currently this uses Euler Angles so may blow up near center of image."""
        self.get_logger().info("Converting pixels to Euler...")

        theta_u = (u - self.uu_2) * self.rad_u  # radians to rotate about v-axis (about downward vertical)
        theta_v = -(v - self.vv_2) * self.rad_v  # radians to rotate about u-axis (about rightward horizontal)

        # theta = np.array([[theta_v], [theta_u], [0]])  # Euler angles about (u, v, z) axes where z-axis rotation may be any
        return self.euler_to_dcm(np.array([theta_v, theta_u]))  # = dcm, where 'euler_to_dcm' assumes [u, v] axes

def main(args=None):
    rclpy.init(args=args)
    node = ImageToDCM()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()