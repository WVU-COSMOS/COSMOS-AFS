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

import serial
import time
from PIL import Image
import io
import numpy as np
import cv2
import warnings


def image_via_serial(ser,**kwargs):
    """
        Prompt ESP32-CAM to capture and send single image, then return a numpy array.

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
        # PROBLEM HERE IS LAG DEPENDS ON TIME IT TAKES TO GO THROUGH WHILE LOOP SINCE img_length CURRENTLY UNDERSHOOTS
        # img_length = ser.read(2)  # esp32 coded to send length of jpeg bytes as first 2 bytes
        # img_length = int.from_bytes(img_length, byteorder='big')

        img_length0 = 0
        img_length = -1  # != img_length0
        start = time.time()
        while img_length != img_length0:
            time.sleep(0.01)
            img_length0 = img_length
            img_length = ser.inWaiting()
        end = time.time()
        print(f'Lag for ser.inWaiting():      {end-start} s')

        # # PROBLEM HERE IS LAG DEPENDS ON TIME IT TAKES TO READ 1200*1600*3 BYTES
        # trash = ser.read(2) # esp32 currently coded to attempt sending length of jpeg bytes as first 2 bytes
        # img_length = 5760000 # max bytes per image, functional if ESP32 sends only one image until serial is read

        # img_data = ser.read(img_length)
        img_data = ser.read(img_length)

        # handle case of incorrect img_length (but, ideally, troubleshoot why img_length is incorrect)
        if img_length != array:
            img_length_actual = img_length
            while img_data[-2:] != b'\xff\xd9':
                img_length_actual = img_length_actual + 1
                img_data_i = ser.read(1)
                img_data = img_data + img_data_i
            if debug:
                print(f'ESP:    {img_length}\nActual: {img_length_actual}')

        # still need to handle case of image not starting with b'\xff\xd8\...', e.g., if date and time are displayed
        #   - common exception == meaning:
        #   - b'et' == unknown

        img = Image.open(io.BytesIO(img_data))
        img_array = np.array(img)

    except Exception as e:
        raise ValueError(f"Could not capture image. Exception: {str(e)}")

    return img_array


def image_via_serial__old(images,port,fps,buffer,**kwargs):
    """
        Outdated. See 'image_via_serial' for current implementation.
        ---------------------------------------------------------------------------------------------------------------

        Prompt ESP32-CAM to capture and send multiple images, then return a list of numpy arrays.

        Inputs:
        - images (scalar) == number of images to return (e.g., 3)
        - port (string)   == serial port that ESP32-CAM is plugged in to (e.g., 'COM14')
        - fps (scalar)    == maximum frames per second, which decreases if experiencing lag (e.g., 0.1)
        - buffer (scalar) == value to drop fps when experiencing lag in addition to the lag time itself (e.g., 0.05)

        Optional Inputs:
        - debug    == boolean for printing to console                       == 0 (default)
        - baudrate == baudrate of ESP32-CAM                                 == 115200 (default)
        - timeout  == time spent listening to serial port before timing out == 0.5 (default)
        - video    == boolean for displaying video stream                   == 0 (default)
        - array    == maximum number of bytes if image is not compressed    == 5760000 = 1200x1600x3 (default)

        Output:
        - img_arrays == list of numpy arrays where each array is an RGB representation of an image (e.g., 1200x1600x3)

        Primary Developer Contact Information:
        - Jacob P. Krell (JPK)
            - Aerospace Engineering Undergraduate Student
            - Statler College of Engineering & Mineral Resources
            - Dept. Mechanical and Aerospace Engineering
            - West Virginia University (WVU)
            - jpk0024@mix.wvu.edu
    """
    kwargs_default = {'time': 60, 'debug': 0, 'baudrate': 115200, 'timeout': 0.5, 'video': 0, 'array': 5760000}
    kwargs_expected = kwargs_default.keys()
    for kwarg in kwargs.keys():
        if kwarg not in kwargs_expected:
            raise ValueError(f"Unexpected keyword argument: {kwarg}")
        else:
            kwargs_default[kwarg] = kwargs.get(kwarg, kwargs_default.get(kwarg))
    debug = kwargs_default.get('debug')
    baudrate = kwargs_default.get('baudrate')
    timeout = kwargs_default.get('timeout')
    video = kwargs_default.get('video')
    array = kwargs_default.get('array')

    fps0 = fps
    Fs = 1 / fps
    ser = serial.Serial(port, baudrate, timeout=timeout)
    img_arrays = []
    images_count = 0
    while images_count < images:
        t_out = time.time()
        ser.reset_input_buffer()  # clear serial input
        ser.reset_output_buffer()  # clear serial output
        ser.write(b'C')
        try:
            # PROBLEM HERE IS LAG DEPENDS ON TIME IT TAKES TO GO THROUGH WHILE LOOP SINCE img_length CURRENTLY UNDERSHOOTS
            img_length = ser.read(2)  # esp32 coded to send length of jpeg bytes as first 2 bytes
            img_length = int.from_bytes(img_length, byteorder='big')

            # # PROBLEM HERE IS LAG DEPENDS ON TIME IT TAKES TO READ 1200*1600*3 BYTES
            # trash = ser.read(2) # esp32 currently coded to attempt sending length of jpeg bytes as first 2 bytes
            # img_length = 5760000 # max bytes per image, functional if ESP32 sends only one image until serial is read

            img_data = ser.read(img_length)

            # handle case of incorrect img_length (but, ideally, troubleshoot why img_length is incorrect)
            if img_length != array:
                while img_data[-2:] != b'\xff\xd9':
                    img_data_i = ser.read(1)
                    img_data = img_data + img_data_i

            # still need to handle case of image not starting with b'\xff\xd8\...', e.g., if date and time are displayed
            #   - common exception == meaning:
            #   - b'et' == unknown

            img = Image.open(io.BytesIO(img_data))
            img_array = np.array(img)
            img_arrays.append(img_array)
            images_count = images_count + 1

            t_in = time.time()
            t_len = t_in - t_out
            if debug:
                print(f'Lag: {t_len} s')

            if video:
                cv2.imshow('Video Stream', cv2.cvtColor(img_array, cv2.COLOR_RGB2BGR))
                cv2.waitKey(1)

        except Exception as e:
            raise ValueError(f"Could not capture image. Exception: {str(e)}")

        t_wait = Fs - (time.time() - t_out)
        if t_wait >= 0:
            if fps < fps0:
                Fs = Fs - t_wait
                fps = 1 / Fs
                if fps > fps0:
                    fps = fps0
                    Fs = 1 / fps
                if debug:
                    print(f"Rise: {fps} FPS.")
            time.sleep(t_wait)
        else:
            Fs = Fs - t_wait
            fps = 1 / Fs - buffer
            Fs = 1 / fps
            if debug:
                print(f"Drop: {fps} FPS.")
    return img_arrays


# Use ArUco to get DCM for tracking
# propagate R_N_to_B (as q_N_to_B), then measure R_B_to_A, calculate R_N_to_A
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
    kwargs_default = {'mission': 1, 'debug': 0, 'video': 0, 'circle': 0}
    kwargs_expected = kwargs_default.keys()
    for kwarg in kwargs.keys():
        if kwarg not in kwargs_expected:
            raise ValueError(f"Unexpected keyword argument: {kwarg}")
        else:
            kwargs_default[kwarg] = kwargs.get(kwarg, kwargs_default.get(kwarg))
    mission = kwargs_default.get('mission')

    missions = {
        1: {'R_tol': [150,255], 'G_tol': [0,50], 'B_tol': [0,50]},
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

    # Create a new RGB image
    RGB_new = np.zeros_like(RGB)
    RGB_new[:, :, 0] = B
    RGB_new[:, :, 1] = G
    RGB_new[:, :, 2] = R

    try:
        # Convert to grayscale
        I = cv2.cvtColor(RGB_new, cv2.COLOR_BGR2GRAY)

        # Threshold the image to create a binary mask for the white part
        _, binary_mask = cv2.threshold(I, 200, 255, cv2.THRESH_BINARY)

        # Find contours in the binary mask
        contours, _ = cv2.findContours(binary_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        # Find the largest contour (assuming it corresponds to the object of interest)
        largest_contour = max(contours, key=cv2.contourArea)

        # Calculate the center of mass (centroid) of the largest contour
        M = cv2.moments(largest_contour)
        u = int(M['m10'] / M['m00'])
        v = int(M['m01'] / M['m00'])

        if video:
            if circle: # then draw a circle at the center
                cv2.circle(RGB_new, (u, v), 25, (0, 255, 0), -1)

            cv2.imshow('Processed Video', cv2.cvtColor(RGB_new, cv2.COLOR_BGR2RGB))
            cv2.waitKey(1)

        return [u, v]

    except:
        print("No contours found.")


# def pixel_to_dq():
#
#
# def angles_to_dq():
#
#
# def dq_to_RW():

