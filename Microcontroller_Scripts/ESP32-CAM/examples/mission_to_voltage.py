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

from src.COSMOS_AFS import COSMOS_AFS
import time
import cv2
import numpy as np


def main():
    # ------------------------------------------------------------------------------------------------------------------
    # User Parameters:

    url = "http://192.168.4.2/capture"  # see Arduino IDE console of ESP32 router for IP address
    mission = 1  # integer of mission (for image processing)
    video = 1
    video_info = 1  # display FPS, quaternion, line to target, and timestamp on processed image
    debug = 1
    frames = 500  # frames to process before ending example
    dec = 4  # decimals to round to

    if video:
        scale = 1  # scale factor of display window size

    if video_info:
        font = cv2.FONT_HERSHEY_SIMPLEX
        fontclr = (0, 0, 255)
        ratio = np.array([0.33, 14]) / 240  # good size for 240x240
        sizing = {'min': list(ratio*96), 'med': [0.33, 14], 'QVGA': [0.4, 14], 'SVGA': [0.4, 14], 'UXGA': [0.8, 20]}

    # ------------------------------------------------------------------------------------------------------------------

    afs = COSMOS_AFS(url)  # initialize COSMOS_AFS class
    imgs = []  # raw images
    timestamps = []  # timestamps of images
    uvs = []  # pixels indices of target
    raws = []  # raw images
    cons = []  # processed images (i.e., contours)
    frame = 0

    if video:
        w = scale * afs.uu
        h = scale * afs.vv

        for title in ['Raw Video', 'Processed Video']:
            cv2.namedWindow(title, cv2.WINDOW_NORMAL)
            cv2.resizeWindow(title, w, h)

    if video_info:
        fontsize = sizing.get(afs.format)[0] / scale
        offset = int(sizing.get(afs.format)[1] / scale)
        offset_x2 = 2 * offset

    while frame < frames:  # acquisition and tracking closed-loop
        t0 = time.time()

        img, timestamp = afs.image_via_wifi()
        imgs.append(img)
        timestamps.append(timestamp)

        t1 = time.time()

        uv, raw, con = afs.image_to_pixel(img, mission, circle=1, ReturnImage=1)
        uvs.append(uv)
        raws.append(raw)
        cons.append(con)

        t2 = time.time()

        uv_log = (uv != [[], []])
        if uv_log:
            phi = afs.pixel_to_aa(uv)
            q, dcm = afs.aa_to_q_and_dcm(phi)
            q_txt = list(np.transpose(np.round(q, dec))[0])

        t3 = time.time()
        fps = round(1 / (t3 - t1), dec)

        frame = frame + 1

        if video:
            cv2.imshow('Raw Video', cv2.cvtColor(raw, cv2.COLOR_BGR2RGB))
            cv2.waitKey(1)

            if video_info:
                # ("https://stackoverflow.com/questions/16615662/how-to-write-text-on-a-image-in-windows-using-python-
                # opencv2")

                cv2.putText(con, f'FPS: {fps}', (offset, offset), font, fontsize, fontclr, 1, 2)
                if uv_log:
                    cv2.putText(con, f'q = {q_txt}', (offset, offset_x2), font, fontsize, fontclr, 1, 2)
                    cv2.line(con, (afs.vv_2, afs.uu_2), (uv[0], uv[1]), fontclr, thickness=1)
                cv2.putText(con, f'{timestamp}', (offset, afs.uu - offset), font, fontsize, fontclr, 1, 2)

            cv2.imshow('Processed Video', cv2.cvtColor(con, cv2.COLOR_BGR2RGB))
            cv2.waitKey(1)

        t4 = time.time()

        if debug:
            print()
            print()
            if frame < 10:
                print(f'==================== Frame 0{frame} ====================')
            else:
                print(f'==================== Frame {frame} ====================')
            print(f'Method         | Time (s)')
            print(f'---------------|----------------------------------')
            print(f'image_via_wifi | {t1 - t0}')
            print(f'image_to_pixel | {t2 - t1}')
            if uv_log:
                print(f'    pixel_to_q | {t3 - t2}')
            print(f'           FPS | {fps}')
            if video:
                print()
                print(f'image_to_video | {t4 - t3}')
                print(f'           FPS | {round(1/(t4 - t1), dec)}')
            if uv_log:
                print()
                print(f'             q | {q_txt}')


        # NEEDS DEVELOPMENT:

        # q_to_torque()
        # torque_to_v()


if __name__ == "__main__":
    main()

