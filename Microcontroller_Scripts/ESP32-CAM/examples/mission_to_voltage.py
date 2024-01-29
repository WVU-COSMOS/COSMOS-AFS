"""
Development Information:
COSMOS-AFS

Call functions from 'COSMOS-AFS.py' package for debugging and to develop an acquisition and tracking closed-loop.


Primary Developer Contact Information:
    - Jacob P. Krell (JPK)
        - Aerospace Engineering Undergraduate Student
        - Statler College of Engineering & Mineral Resources
        - Dept. Mechanical and Aerospace Engineering
        - West Virginia University (WVU)
        - jpk0024@mix.wvu.edu

Development History:
Date              Developer        Comments
---------------   -------------    --------------------------------
Jan. 11, 2024     JPK              v1 (video and correct length of bytes) finalized and uploaded to GitHub.
                                   FPS: ~4s for protocol, ~6s for analysis.
Jan. 24, 2024     VDF              images from wifi

"""

from src.COSMOS_AFS import image_via_wifi
from src.COSMOS_AFS import image_to_pixel
import time
import cv2


esp32_ip = "192.168.4.2"

def main():

    debug = 1
    video = 1
    video_contour = 1

    buffer = 0.05
    fps = 20
    Fs = 1 / fps
    fps0 = fps

    img_arrays = []
    pixels = []
    img_contours = []
    Frame = 0
    count = 0
    while True:  # acquisition and tracking closed-loop
        if debug:
            Frame = Frame + 1
            if Frame < 10:
                print()
                print(f'==================== Frame 0{Frame} ====================')
            else:
                print(f'==================== Frame {Frame} ====================')

        t_start = time.time()

        img_array = image_via_wifi(esp32_ip)
        img_arrays.append(img_array)

        if debug:
            print(f'Lag for Camera Protocol:      {time.time() - t_start} s')

        t_start_pixel = time.time()

        pixel, img_contour = image_to_pixel(img_array, mission=1, debug=1, video=1, circle=1, ReturnContour=1)
        pixels.append(pixel)
        img_contours.append(img_contour)

        if debug:
            print(f'Lag for Camera Data Analysis: {time.time() - t_start_pixel} s')

        if video:
            t_start_video = time.time()

            # cv2.imshow(f'Raw Video', cv2.cvtColor(img_array, cv2.COLOR_RGB2BGR))
            cv2.imshow(f'Raw Video', img_array)
            cv2.waitKey(1)

            if debug:
                print(f'Lag for Raw Video:            {time.time() - t_start_video} s')

        if video_contour:
            t_start_video_contour = time.time()

            cv2.imshow(f'Processed Video', img_contour)
            cv2.waitKey(1)

            if debug:
                print(f'Lag for Processed Video:      {time.time() - t_start_video_contour} s')

            count = count+1
        # if count > 100:
        #     breakpoint()

        if debug:
            print(f'Lag for Overall:              {time.time() - t_start} s')


        # NEEDS DEVELOPMENT:

        # pixel_to_attitude()
        # attitude_to_voltage()


        # NEEDS TROUBLESHOOTING BECAUSE t_wait IS NOT CORRECT:

        # t_wait = Fs - (time.time() - t_start)
        # print(f't_wait = {t_wait}')
        # if t_wait >= 0:
        #     if fps < fps0:
        #         Fs = Fs - t_wait
        #         fps = 1 / Fs
        #         if fps > fps0:
        #             fps = fps0
        #             Fs = 1 / fps
        #         if debug:
        #             print(f"Rise: {fps} FPS.")
        #     time.sleep(t_wait)
        # else:
        #     Fs = Fs - t_wait
        #     fps = 1 / Fs - buffer
        #     Fs = 1 / fps
        #     if debug:
        #         print(f"Drop: {fps} FPS.")


if __name__ == "__main__":
    main()

