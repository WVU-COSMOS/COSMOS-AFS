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
---------------   -------------    --------------------------------
Jan. 11, 2024     JPK              'image_via_serial' is limited by ESP32's ~10,000 bytes/second output;
                                   'image_to_pixel' needs to have RGB range fine-tuned as currently does not detect red;

"""

import time
from PIL import Image
import io
import numpy as np
import cv2
import requests


def image_via_serial(ser,**kwargs):
    """
    Prompt ESP32-CAM to capture and send single image (via USB), then return a numpy array.

    Inputs:
    - ser (object) == serial.Serial(port, baudrate, timeout=timeout)

    Optional Inputs:
    - debug    == boolean for printing to console                    == 0 (default)
    - array    == maximum number of bytes if image is not compressed == 5760000 = 1200x1600x3 (default)

    Output:
    - img_array == numpy array of an RGB representation of the image (e.g., 1200x1600x3)

    Primary Developer Contact Information:
    - Jacob P. Krell (JPK)
        - Aerospace Engineering Undergraduate Student
        - Statler College of Engineering & Mineral Resources
        - Dept. Mechanical and Aerospace Engineering
        - West Virginia University (WVU)
        - jpk0024@mix.wvu.edu
    """
    kwargs_default = {'debug': 0, 'array': 5760000}
    kwargs_expected = kwargs_default.keys()
    for kwarg in kwargs.keys():
        if kwarg not in kwargs_expected:
            raise ValueError(f"Unexpected keyword argument: {kwarg}")
        else:
            kwargs_default[kwarg] = kwargs.get(kwarg, kwargs_default.get(kwarg))
    debug = kwargs_default.get('debug')
    array = kwargs_default.get('array')

    ser.reset_input_buffer()  # clear serial input
    ser.reset_output_buffer()  # clear serial output
    ser.write(b'C')
    try:
        img_length0 = 0
        img_length = -1  # != img_length0
        start = time.time()
        while img_length != img_length0:
            time.sleep(0.005)
            img_length0 = img_length
            img_length = ser.inWaiting()
        time_inWaiting = time.time() - start
        if debug:
            print(f'Lag for Single Image:         {time_inWaiting} s')
            print(f'Inferred Bit Rate:            {img_length * 8 / time_inWaiting}')
        img_data = ser.read(img_length)

        # Handle incorrect img_length if less than actual length, otherwise infinite ser.read() may be occurring:
        img_length_actual = img_length
        while img_data[-2:] != b'\xff\xd9':
            img_length_actual = img_length_actual + 1
            img_data_i = ser.read(1)
            img_data = img_data + img_data_i
        if debug:
            print(f'Bytes (Assumed): {img_length}\nBytes (Actual):  {img_length_actual}')

        # still need to handle case of image not starting with b'\xff\xd8\...', e.g., if date and time are displayed
        #   - format ... common exception == meaning:
        #       - (1) ... b'et' == unknown
        #       - (2) ...

        img = Image.open(io.BytesIO(img_data))
        img_array = np.array(img)

    except Exception as e:
        raise ValueError(f"Could not capture image. Exception: {str(e)}")

    return img_array


def image_via_wifi(esp32_ip, **kwargs):
    """
    Prompt ESP32-CAM to capture and send single image (via WiFi), then return a numpy array.

    Inputs:
    - esp32_ip (string) == IP address of other ESP32 router, to be connected to R-Pi

    Optional Inputs:
    - debug    == boolean for printing to console                    == 0 (default)

    Output:
    - img_array == numpy array of an RGB representation of the image (e.g., 1200x1600x3)

    Primary Developer Contact Information:
    - Jacob P. Krell (JPK)
        - Aerospace Engineering Undergraduate Student
        - Statler College of Engineering & Mineral Resources
        - Dept. Mechanical and Aerospace Engineering
        - West Virginia University (WVU)
        - jpk0024@mix.wvu.edu
    """
    time_start = time.time()

    kwargs_default = {'debug': 0}
    kwargs_expected = kwargs_default.keys()
    for kwarg in kwargs.keys():
        if kwarg not in kwargs_expected:
            raise ValueError(f"Unexpected keyword argument: {kwarg}")
        else:
            kwargs_default[kwarg] = kwargs.get(kwarg, kwargs_default.get(kwarg))
    debug = kwargs_default.get('debug')

    url = f"http://{esp32_ip}/capture"
    try:
        response = requests.get(url)
        if response.status_code == 200:
            img = Image.open(io.BytesIO(response.content))
            img_array = np.array(img)
        else:
            raise ValueError(f"Failed to fetch image. Status code: {response.status_code}")
    except Exception as e:
        raise ValueError(f"Could not capture image. Exception: {str(e)}")

    if debug:
        t_img = time.time() - time_start
        print(f'Lag for Single Image:         {t_img} s')
        print(f'Inferred Bit Rate:            {len(response.content) * 8 / t_img}')

    return img_array


# From Dr. Rhodes (2024/01/08):
#   - Use ArUco to get DCM for tracking (per Rhodes).
#   - Propagate R_N_to_B as q_N_to_B, then measure R_B_to_A, then calculate R_N_to_A.
def image_to_pixel(RGB,**kwargs):
    """
    Process RGB image array to return a single pixel location as the target to aim at.

    Inputs:
    - RGB (numpy array) == RGB image array (e.g., 1200x1600x3)

    Optional Inputs:
    - mission (integer) == index of which mission to use for processing the image                 == 1 (default)
    - debug (boolean)   == boolean for printing target to console and displaying plot with circle == 0 (default)
    - video (boolean)   == boolean for displaying video                                           == 0 (default)
    - circle (boolean)  == boolean for drawing circle on video                                    == 0 (default)

    Output:
    - pixel == list of u,v pixel location (e.g., [1021,1392])

    Primary Developer Contact Information:
    - Dominic K. Amato (DKA)
        - Aerospace Engineering Undergraduate Student
        - Statler College of Engineering & Mineral Resources
        - Dept. Mechanical and Aerospace Engineering
        - West Virginia University (WVU)
        - dka00004@mix.wvu.edu

    Development History:
        Date              Developer        Comments
        ---------------   -------------    -------------------------------------------------------------------------
        Prior             DKA              Function created in MATLAB and ported to Python primarily via ChatGPT;
        Nov. 29, 2023     JPK              Added to COSMOS_AFS module and integrated with 'image_via_serial';
    """
    kwargs_default = {'mission': 1, 'debug': 0, 'video': 0, 'circle': 0, 'ReturnContour': 0}
    kwargs_expected = kwargs_default.keys()
    for kwarg in kwargs.keys():
        if kwarg not in kwargs_expected:
            raise ValueError(f"Unexpected keyword argument: {kwarg}")
        else:
            kwargs_default[kwarg] = kwargs.get(kwarg, kwargs_default.get(kwarg))
    mission = kwargs_default.get('mission')
    debug = kwargs_default.get('debug')
    video = kwargs_default.get('video')
    circle = kwargs_default.get('circle')
    ReturnContour = kwargs_default.get('ReturnContour')

    missions = {
        # 1: {'R_tol': [150,255], 'G_tol': [0,50], 'B_tol': [0,50]},
        # 1: {'R_tol': [20, 255], 'G_tol': [0, 150], 'B_tol': [0, 150]},
        1: {'R_tol': [100, 255], 'G_tol': [0, 75], 'B_tol': [0, 75]},
        2: {'R_tol': [0,100], 'G_tol': [150,255], 'B_tol': [0,100]},
        3: {'R_tol': [0,150], 'G_tol': [0,150], 'B_tol': [150,255]}
    }

    mission_vars = missions.get(mission)

    try:
        R_tol = mission_vars.get('R_tol')
        G_tol = mission_vars.get('G_tol')
        B_tol = mission_vars.get('B_tol')
    except:
        raise ValueError("The selected mission is not currently supported within this function.")
    R_tol[0] = R_tol[0] - 1
    R_tol[1] = R_tol[1] + 1
    G_tol[0] = G_tol[0] - 1
    G_tol[1] = G_tol[1] + 1
    B_tol[0] = B_tol[0] - 1
    B_tol[1] = B_tol[1] + 1

    # Split channels assuming indices are ordered Blue, Green, Red
    R = np.copy(RGB[:, :, 0])
    G = np.copy(RGB[:, :, 1])
    B = np.copy(RGB[:, :, 2])

    # -------------------------------------
    # NOTES FOR DEVELOPMENT:
    # - R, G, B, and BW variables could be 2D logical instead of 3D (3rd dim is redundant; and R, G, B just needs 1 var)

    # Process the image
    for i in range(RGB.shape[0]):
        for j in range(RGB.shape[1]):
            if R_tol[0] < R[i, j] < R_tol[1] and G_tol[0] < G[i, j] < G_tol[1] and B_tol[0] < B[i, j] < B_tol[1]:
                R[i, j] = 255
                G[i, j] = 255
                B[i, j] = 255
            else:
                R[i, j] = 0
                G[i, j] = 0
                B[i, j] = 0

    # Create a new image (that is a black/white 'logical' where '1' falls in mission range)
    BW = np.zeros_like(RGB)
    BW[:, :, 0] = B
    BW[:, :, 1] = G
    BW[:, :, 2] = R

    try:
        # Convert to grayscale
        I = cv2.cvtColor(BW, cv2.COLOR_BGR2GRAY)

        # Threshold the image to create a binary mask for the white part
        _, binary_mask = cv2.threshold(I, 200, 255, cv2.THRESH_BINARY)

        # Find contours in the binary mask
        contours, _ = cv2.findContours(binary_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        # END NOTES FOR DEVELOPMENT:
        # -------------------------------------

        # Find the largest contour (assuming it corresponds to the object of interest)
        largest_contour = max(contours, key=cv2.contourArea)

        # Calculate the center of mass (centroid) of the largest contour
        M = cv2.moments(largest_contour)
        u = int(M['m10'] / M['m00'])
        v = int(M['m01'] / M['m00'])

        if video:
            if circle: # then draw a circle at the center
                cv2.circle(BW, (u, v), 25, (0, 255, 0), -1)

            cv2.imshow('Processed Video', cv2.cvtColor(BW, cv2.COLOR_BGR2RGB))
            cv2.waitKey(1)

    except:
        print("No contours found.")
        u = []
        v = []

    if ReturnContour:
        return [u, v], BW
    else:
        return [u, v]


# def pixel_to_dq():
#
#
# def angles_to_dq():
#
#
# def dq_to_RW():

