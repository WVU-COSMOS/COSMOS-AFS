## Development Information
# COSMOS-AFS
#
# R-Pi code to prompt and receive images from ESP32 via serial.
#
#
# Primary Developer Contact Information:
# Jacob P. Krell (JPK)
# Aerospace Engineering Undergraduate Student
# Statler College of Engineering & Mineral Resources
# Dept. Mechanical and Aerospace Engineering
# West Virginia University (WVU)
# jpk0024@mix.wvu.edu
#
#
#
# Development History
# Date              Developer        Comments
# ---------------   -------------    --------------------------------
# Nov. 27, 2023     JPK              some exceptions not handled
#
##


import serial
import time
from PIL import Image
import io
import numpy as np
import cv2


port = 'COM14'
FPS = 0.1
FPS_buffer = 0.05 # extra (not only) drop in FPS when experiencing lag

FPS0 = FPS
Fs = 1/FPS
ser = serial.Serial(port, 115200, timeout=0.5)
img_array = []
while True:
    t_out = time.time()
    ser.write(b'C')
    try:
        img_length = ser.read(2) # esp32 coded to send length of jpeg bytes as first 2 bytes
        img_length = int.from_bytes(img_length[:2], byteorder='big')

        img_data = ser.read(img_length)

        # handle case of incorrect img_length (but, ideally, troubleshoot why img_length is incorrect)
        while img_data[-2:] != b'\xff\xd9':
            img_data_i = ser.read(1)
            img_data = img_data + img_data_i

        # still need to handle case of image not starting with b'\xff\xd8\...', e.g., if date and time are displayed


        img = Image.open(io.BytesIO(img_data))
        img_array_i = np.array(img)
        img_array.append(img_array_i)


        t_in = time.time()
        t_len = t_in - t_out
        print(f'Lag: {t_len} s')


        cv2.imshow('Video Stream', cv2.cvtColor(img_array_i, cv2.COLOR_RGB2BGR))
        cv2.waitKey(1)

    except Exception as e:
        print(f"Error: {str(e)}")

    t_wait = Fs - (time.time() - t_out)
    if t_wait >= 0:
        if FPS < FPS0:
            Fs = Fs - t_wait
            FPS = 1 / Fs
            if FPS > FPS0:
                FPS = FPS0
                Fs = 1 / FPS
            print(f"Rise: {FPS} FPS.")
        time.sleep(t_wait)
    else:
        Fs = Fs - t_wait
        FPS = 1 / Fs - FPS_buffer
        Fs = 1 / FPS
        print(f"Drop: {FPS} FPS.")

