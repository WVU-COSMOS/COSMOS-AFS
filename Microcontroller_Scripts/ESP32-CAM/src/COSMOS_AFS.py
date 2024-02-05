"""
Development Information:
COSMOS-AFS

Package of functions primarily for acquisition and tracking closed-loop.


Primary Developer(s) Contact Information:
    - Jacob P. Krell (JPK)
        - Aerospace Engineering Undergraduate Student
        - Statler College of Engineering & Mineral Resources
        - Dept. Mechanical and Aerospace Engineering
        - West Virginia University (WVU)
        - jpk0024@mix.wvu.edu

Development History:
Date              Developer        Comments
---------------   -------------    -------------------------------------------------------------------------------------
Jan. 11, 2024     JPK              'image_via_serial' is limited by ESP32's ~10,000 bytes/second output;
                                   'image_to_pixel' needs to have RGB range fine-tuned as currently does not detect red;
Jan. 29, 2024     JPK              Restructured into class, optimized functions, deleted 'image_via_serial';

"""

import time
from PIL import Image
import io
import numpy as np
import cv2
import requests


class COSMOS_AFS:

    def __init__(self, url):
        """
        Inputs:
            - url (string) == f"http://{ip}/capture" where 'ip' is IP address of other ESP32 router connected to R-Pi
        """
        self.url = url
        self.missions_params = {1: (np.array([100, 0, 0], dtype=np.uint8), np.array([255, 75, 75], dtype=np.uint8))}
        self.rad_u = np.arctan(10 / 12.75) / 1200
        self.rad_v = np.arctan(11 / 12.75) / 1600

        # initial setup
        img, _ = self.image_via_wifi()
        self.uu = img.shape[0]  # vertical axis
        self.vv = img.shape[1]  # horizontal axis
        self.uu_2 = int(self.uu / 2)
        self.vv_2 = int(self.vv / 2)

        self.format_options = {'min': [96, 96], 'med': [240, 240], 'QVGA': [320, 240], 'SVGA': [800, 600],
                               'UXGA': [1600, 1200]}
        for key, value in self.format_options.items():
            if value == [self.vv, self.uu]:
                self.format = key
                break

        return


    def image_via_wifi(self):
        """
        Prompt ESP32-CAM to capture and send single image (via WiFi), then return a numpy array.

        Output:
            - img (numpy array)  == RGB image array (e.g., 1200x1600x3)
            - timestamp (scalar) == timestamp of image

        Primary Developer(s):
            - Vinicius D. Ferreira (VDF)
                - Aerospace Engineering Undergraduate Student
                - Statler College of Engineering & Mineral Resources
                - Dept. Mechanical and Aerospace Engineering
                - West Virginia University (WVU)
                - vdf00001@mix.wvu.edu
            - Jacob P. Krell (JPK)

        Development History:
        Date              Developer        Comments
        ---------------   -------------    -----------------------------------------------------------------------------
        Prior             VDF              Created and tested with ESP32 router;
        Jan. 29, 2024     JPK              Optimized for 'mission_to_voltage' example;
        """
        try:
            response = requests.get(self.url)  # response.status_code == 200, if successful
            timestamp = time.asctime()
            img = np.array(Image.open(io.BytesIO(response.content)))
        except Exception as e:
            raise ValueError(f"Could not capture image. Exception: {str(e)}")

        return img, timestamp


    # From Dr. Rhodes (2024/01/08):
    #   - Use ArUco to get DCM for tracking (per Rhodes).
    #   - Propagate R_N_to_B as q_N_to_B, then measure R_B_to_A, then calculate R_N_to_A.
    def image_to_pixel(self, img, mission, **kwargs):
        """
        Process RGB image array to return a single pixel location as the target to aim at.

        Inputs:
            - img (numpy array) == RGB image array (e.g., 1200x1600x3)
            - mission (integer) == index of which mission to use for processing the image

        Optional Inputs:
            - circle (boolean)      == boolean for drawing circle at target         == 0 (default)
            - ReturnImage (boolean) == boolean for returning raw and contour images == 0 (default)

        Output:
            - [u, v] (list)         == pixel indices of target (e.g., [1021,1392])
            - con_rgb (numpy array) == RGB of target/non-target where non-target is black

        Primary Developer(s):
            - Dominic K. Amato (DKA)
                - Aerospace Engineering Undergraduate Student
                - Statler College of Engineering & Mineral Resources
                - Dept. Mechanical and Aerospace Engineering
                - West Virginia University (WVU)
                - dka00004@mix.wvu.edu
            - Jacob P. Krell (JPK)

        Development History:
        Date              Developer        Comments
        ---------------   -------------    -----------------------------------------------------------------------------
        Prior             DKA              Function created in MATLAB and ported to Python primarily via ChatGPT;
        Nov. 29, 2023     JPK              Added to COSMOS_AFS module and integrated with 'image_via_serial';
        Jan. 29, 2024     JPK              Optimized for 'mission_to_voltage' example;
        """
        kwargs_default = {'circle': 0, 'ReturnImage': 0}
        kwargs_expected = kwargs_default.keys()
        for kwarg in kwargs.keys():
            if kwarg not in kwargs_expected:
                raise ValueError(f"Unexpected keyword argument: {kwarg}")
            else:
                kwargs_default[kwarg] = kwargs.get(kwarg, kwargs_default.get(kwarg))
        circle = kwargs_default.get('circle')
        ReturnImage = kwargs_default.get('ReturnImage')

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
                cv2.circle(con_rgb, (u, v), 6, (0, 255, 0), -1)

        except:
            u = []
            v = []

        if ReturnImage:
            return [u, v], img, con_rgb
        else:
            return [u, v]


    def pixel_to_aa(self, uv):
        """
        Convert pixel indices to axis-angle (angular displacement with-respect-to center).

        Inputs:
            - uv == [u, v] == pixel indices of target

        Output:
            - [phi_u, phi_v] == axis-angles in radians

        Primary Developer(s):
            - Jacob P. Krell (JPK)

        Development History:
        Date              Developer        Comments
        ---------------   -------------    -----------------------------------------------------------------------------
        Jan. 30, 2024     JPK              Created for initial testing of closed-loop tracking and acquisition;
        """
        phi_u = uv[0] - self.uu_2 * self.rad_u
        phi_v = uv[1] - self.vv_2 * self.rad_v
        return [phi_u, phi_v]


    def aa_to_q_and_dcm(self, phi):
        """
        Convert axis-angle to quaternion and DCM.

        Inputs:
            - [phi_u, phi_v] == axis-angles in radians

        Output:
            - q   == quaternion to center target
            - dcm == direction-cosine-matrix (DCM) to center target

        Primary Developer(s):
            - Jacob P. Krell (JPK)

        Development History:
        Date              Developer        Comments
        ---------------   -------------    -----------------------------------------------------------------------------
        Jan. 30, 2024     JPK              Created for initial testing of closed-loop tracking and acquisition;
        """
        if np.shape(phi) != (3, 1):  # then assume phi is a list and less than a length of 3
            phi0 = np.zeros([3, 1])
            phi0[0:np.size(phi), 0] = phi
            phi = phi0
        phimag = (phi[0] ** 2 + phi[1] ** 2 + phi[2] ** 2) ** 0.5
        ehat = np.divide(phi, phimag)

        phimag_2 = phimag / 2
        q = np.zeros([4, 1])
        q[0] = np.sin(phimag_2)
        q[1::] = ehat * np.cos(phimag_2)
        if q[0] < 0:  # short rotation
            q = -q

        cp = np.cos(phimag)
        skew = np.array([[0, 0, ehat[1, 0]], [0, 0, -ehat[0, 0]], [-ehat[1, 0], ehat[0, 0], 0]])
        eye = np.eye(3)
        dcm = cp * eye + (1 - cp) * (ehat * np.transpose(ehat)) - np.sin(phimag) * skew

        return q, dcm


    # def angles_to_dq():
    #
    #
    # def dq_to_RW():

