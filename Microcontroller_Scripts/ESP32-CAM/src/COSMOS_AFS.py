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
Feb. 19, 2024     JPK              Need to get DCM from frame blocks, not axis-angles (see iPhone pics);
Feb. 26, 2024     JPK              Successful tests of 'acquisition' method; May be inaccurate but has functionality;
                                   Outer loop checks for target @ stable FPS, returns RPM's if target, performs
                                   'nontracking_mode' operation if no target for specified number of frames; Need ode45;
"""

import time
from PIL import Image
import io
import numpy as np
import cv2
import requests


# OUTDATED BECAUSE USES AXIS-ANGLES:
def aa_to_q(ehat, phimag):
    """Convert axis-angle to quaternion."""
    phimag_2 = phimag / 2
    q = np.zeros([4, 1])
    q[0] = np.sin(phimag_2)
    q[1::] = ehat * np.cos(phimag_2)
    if q[0] < 0:  # short rotation
        q = -q
    return q


class COSMOS_AFS:
    def __init__(self, url):
        """
        Inputs:
            - url (string) == f"http://{ip}/capture" where 'ip' is IP address of other ESP32 router connected to R-Pi
        """
        # webcam and analysis options:
        self.url = url
        self.missions_params = {1: (np.array([100, 0, 0], dtype=np.uint8), np.array([255, 75, 75], dtype=np.uint8))}

        # initial setup:
        img, _ = self.image_via_wifi()
        self.uu = img.shape[0]  # vertical axis
        self.vv = img.shape[1]  # horizontal axis
        self.uu_2 = int(self.uu / 2)
        self.vv_2 = int(self.vv / 2)

        # ordered as [v, u]:
        self.format_options = {'min': [96, 96], 'med': [240, 240], 'QVGA': [320, 240], 'SVGA': [800, 600],
                               'UXGA': [1600, 1200]}
        for key, value in self.format_options.items():
            if value == [self.vv, self.uu]:
                self.format = key
                break

        # field of view divided by two (i.e., half-angle), ordered as [v, u]:
        self.fov_2 = {'med': [np.arctan(41/108), np.arctan(41/108)],
                      'UXGA': [np.arctan(5.5 / 12.75), np.arctan(5 / 12.75)]}

        # radians per pixel:
        self.rad_u = self.fov_2[self.format][1] / self.uu_2
        self.rad_v = self.fov_2[self.format][0] / self.vv_2

        # reaction wheels torque control:
        self.eye33 = np.eye(3)  # meant to aid optimization by not requiring repeat function calls
        self.I_body_as_B = np.array([[0.4, 0, 0], [0, 0.3, 0], [0, 0, 0.6]])
        self.Is = [5, 5, 5]  # inertia of reaction wheels
        self.Kp = 1  # scalar
        self.Kd = np.ones([3, 3])  # 3x3 matrix, needs to be solved as function of other control gains
        self.Ki = np.ones([3, 3])  # 3x3 matrix, needs to be solved as function of other control gains
        self.gs1 = np.array([-1, 0, 0])[:, np.newaxis]
        self.gs2 = np.array([0, 1, 0])[:, np.newaxis]
        self.gs3 = np.array([0, 0, -1])[:, np.newaxis]
        self.Gs = np.squeeze([self.gs1, self.gs2, self.gs3]).T  # projection to spin axis
        self.GsT = self.Gs.T
        self.GsT_iGsGsT = np.matmul(self.GsT, np.linalg.inv(np.matmul(self.Gs, self.GsT)))
        self.n = len(self.Gs)  # = 3, number of reaction wheels
        self.IsGs = np.zeros_like(self.Gs)
        for i in range(self.n):
            self.IsGs[:, i] = self.Is[i] * self.Gs[:, i]
        self.A = np.concatenate([np.concatenate([np.eye(4), np.zeros([4, 3]), np.zeros([4, self.n])], axis=1),
                                 np.concatenate([np.zeros([3, 4]), self.I_body_as_B, self.IsGs], axis=1),
                                 np.concatenate([np.zeros([self.n, 4]), self.IsGs.T, np.diag(self.Is)], axis=1)])
        self.N = np.linalg.inv(self.Gs) * np.zeros([3, self.n])  # null space vector N such that Gs*N=0_3xn

        # defaults for 'self.acquisition':
        self.nontracking_modes = {0: 'maintain', 1: 'shutdown', 2: 'spindown'}
        self.nontracking_funcs = {'maintain': self.nontracking_maintain, 'shutdown': self.nontracking_shutdown,
                                  'spindown': self.nontracking_spindown}
        self.fs_cam = 10
        self.fs_ode = 100
        self.mission = 1
        self.nontracking_count = 20
        self.nontracking_mode = 0

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
            timestamp = time.time()  # = time.asctime()
            img = np.array(Image.open(io.BytesIO(response.content)))
        except Exception as e:
            raise ValueError(f"Could not capture image. Exception: {str(e)}")

        return img, timestamp

    # NEEDS UPDATING TO ALLOW ARUCO CODES (which may be more like 'image_to_dcm'):
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

    # OUTDATED BECAUSE USES AXIS-ANGLES (but needed for pixel_to_dcm for now):
    def aa_to_dcm(self, ehat, phimag):
        """Convert axis-angle to DCM."""
        cp = np.cos(phimag)
        return cp * np.eye(3) + (1 - cp) * (ehat * np.transpose(ehat)) - np.sin(phimag) * self.skew(ehat)

    # NEEDS UPDATING BECAUSE USES AXIS-ANGLES:
    def pixel_to_dcm(self, uv):  # for acquisition
    # def pixel_to_angle(self, uv):  # original
        """
        [IN DEVELOPMENT ... CURRENT VERSION USES AXIS-ANGLES TO DERIVE DCM, BUT FRAME BLOCKS SHOULD BE USED TO AVOID
        BLOWING UP WHEN TARGET IS NEAR CENTER]

        Convert pixel indices to axis-angle (angular displacement with-respect-to center).

        Inputs:
            - uv == [u, v] == pixel indices of target

        Output:
            - q   == quaternion to center target
            - dcm == direction-cosine-matrix (DCM) to center target

        Primary Developer(s):
            - Jacob P. Krell (JPK)

        Development History:
        Date              Developer        Comments
        ---------------   -------------    -----------------------------------------------------------------------------
        Jan. 30, 2024     JPK              Created for initial testing of closed-loop tracking and acquisition;
        Feb. 15, 2024     JPK              Conversion from axis-angle to quaternion and DCM included;
        """
        phi_u = (uv[0] - self.uu_2) * self.rad_u
        phi_v = (uv[1] - self.vv_2) * self.rad_v

        phi = [phi_u, phi_v, 0]
        phimag = (phi[0] ** 2 + phi[1] ** 2 + phi[2] ** 2) ** 0.5
        ehat = np.divide(phi, phimag)

        # q = aa_to_q(ehat, phimag)
        dcm = self.aa_to_dcm(ehat[:, np.newaxis], phimag)

        return dcm  # for acquisition
        # return q, dcm

    def skew(self, u):
        """Return skew matrix of a 3x1 vector."""
        return np.array([[0, 0, u[1, 0]], [0, 0, -u[0, 0]], [-u[1, 0], u[0, 0], 0]])

    def dcm_to_q(self, dcm):
        """Convert DCM to quaternion using Shepherd's method."""
        tr = dcm[0, 0] + dcm[1, 1] + dcm[2, 2]  # trace

        qi2 = np.array([[(1 + tr) / 4], [0], [0], [0]])
        for i in range(3):
            qi2[i + 1] = (1 + 2 * dcm[i, i] - tr) / 4
        qi2_abs = abs(qi2)
        qmax2 = np.max(qi2_abs)
        imax = np.argmax(qi2_abs)

        q = np.zeros([4, 1])
        q[imax] = np.sqrt(qmax2)
        if imax == 0:  # qs is max
            q[1::] = np.array([self.dcm_to_q__sv(dcm, 1, 2, q[imax]),
                               self.dcm_to_q__sv(dcm, 2, 0, q[imax]),
                               self.dcm_to_q__sv(dcm, 0, 1, q[imax])])
        elif imax == 1:  # q1 is max
            q[[0, 2, 3]] = np.array([self.dcm_to_q__sv(dcm, 1, 2, q[imax]),
                                     self.dcm_to_q__vv(dcm, 0, 1, q[imax]),
                                     self.dcm_to_q__vv(dcm, 2, 0, q[imax])])
        elif imax == 2:  # q2 is max
            q[[0, 1, 3]] = np.array([self.dcm_to_q__sv(dcm, 2, 0, q[imax]),
                                     self.dcm_to_q__vv(dcm, 0, 1, q[imax]),
                                     self.dcm_to_q__vv(dcm, 1, 2, q[imax])])
        else:  # imax == 3:  # q3 is max
            q[:3] = np.array([self.dcm_to_q__sv(dcm, 0, 1, q[imax]),
                              self.dcm_to_q__vv(dcm, 2, 0, q[imax]),
                              self.dcm_to_q__vv(dcm, 1, 2, q[imax])])

        return self.q_norm_and_short(q)

    def dcm_to_q__sv(self, dcm, n, m, qmax):
        """For 'dcm_to_q' but defined here to avoid defining on every iteration."""
        return (dcm[n, m] - dcm[m, n]) / 4 / qmax

    def dcm_to_q__vv(self, dcm, n, m, qmax):
        """For 'dcm_to_q' but defined here to avoid defining on every iteration."""
        return (dcm[n, m] + dcm[m, n]) / 4 / qmax

    def q_norm_and_short(self, q):
        """Apply quaternion constraint (i.e., normalize) and enforce short rotation."""
        q = q / np.linalg.norm(q)
        if q[0] < 0:
            q = -q  # short rotation
        q[np.abs(q) < 1e-10] = 0
        return q

    def B(self, q):
        """B(q) from quaternion kinematics. (4x1 numpy array input, 4x4 numpy array output)."""
        return np.concatenate([np.concatenate([q[0], -q[1::].T[0]])[np.newaxis],
                               np.concatenate([q[1::], q[0] * self.eye33 + self.skew(q[1::])], axis=1)])

    def acquisition(self, fs_cam=None, fs_ode=None, mission=None, nontracking_count=None, nontracking_mode=None):
        """
        Call this method once if State Machine's mode is Acquisition.

        When this method is called,
            1) Camera on @ stable FPS 'fs_cam';
            2) If first target exists, count subsequent consecutive non-target frames; Else, reset;
            3) If second target exists before count exceeds SM-defined limit 'count', kinematics; Else, reset;
            4) Calculate kinematics to get time derivative of state vector;
            5) Integrate state vector using ode45 @ stable rate 'fs_ode';
            5) Store second target as first, reset count, and return to Step 3;

        """
        # Process inputs and define as local variables:

        params = {'fs_cam': fs_cam, 'fs_ode': fs_ode, 'mission': mission, 'nontracking_count': nontracking_count,
                  'nontracking_mode': nontracking_mode}
        for param in params.keys():
            if params[param] is None:
                params[param] = getattr(self, param)
        fs_cam = params['fs_cam']
        fs_ode = params['fs_ode']
        mission = params['mission']
        nontracking_count = params['nontracking_count'] + 1  # +1 such that '<' is used instead of '<='
        nontracking_mode = params['nontracking_mode']
        if isinstance(nontracking_mode, int):
            nontracking_mode = self.nontracking_modes[nontracking_mode]
        nontracking_func = self.nontracking_funcs[nontracking_mode]

        # Initialization prior to Acquisition and Tracking/Non-Tracking:

        frame = 0
        x0 = np.concatenate([[[1]], np.zeros([6, 1]), self.rw_read()])  # = np.array([[q], [w], [rw]]), state vector
        count = nontracking_count  # initialize to be in non-tracking mode until first target appears
        dt_cam = 1 / fs_cam
        dt_ode = 1 / fs_ode

        def acquire_target(mission):
            img, t = self.image_via_wifi()  # capture image
            uv = self.image_to_pixel(img, mission)  # process image
            if uv != [[], []]:  # if target
                return uv, t
            else:  # no target
                return False, t

        def sync_iter(t_iter, dt_loop):
            """Delay time to sync up with next time interval. 't_iter' is previous time, and 'dt_loop' is interval."""
            for i in range(1, 1000):  # align next iteration with next available timestamp set by Fs intervals
                try:
                    time.sleep(t_iter + i * dt_loop - time.time())
                    return  # now synced on next interval
                except Exception:
                    pass

        # Begin Acquisition:

        while True:
            t_iter = time.time()
            target, t = acquire_target(mission)  # constantly check @ fs_cam if target (i.e., Acquisition)
            frame += 1  # for printing to console when debugging

            # Tracking (if target spotted now or at least once within 'nontracking_count' limit):

            if target is not False:  # first target
                count = 0
                t0 = t
                dcm0 = self.pixel_to_dcm(target)
                z = np.zeros([3, 1])  # reset error propagation
                sync_iter(t_iter, dt_cam)
            while count < nontracking_count:  # not first target
                t_iter = time.time()
                target, t = acquire_target(mission)
                frame += 1  # for printing to console when debugging
                if target is not False:  # if target
                    dcm = self.pixel_to_dcm(target)
                    wx = -np.matmul(dcm.T, (dcm - dcm0) / (t - t0))  # [omega x]
                    w = np.array([[wx[2, 1]], [-wx[2, 0]], [wx[1, 0]]])  # omega
                    q = self.dcm_to_q(dcm)  # error quaternion
                    z += q[1::]  # not sure if qv but assuming because Ki is 3x3
                    u_c_as_b = self.Kp * q[1::] + np.matmul(self.Kd, w) + \
                               self.Kp * np.matmul(self.Kd, np.matmul(self.Ki, z))  # control torque in body frame
                    u_s_as_g = np.matmul(self.GsT_iGsGsT, u_c_as_b)  # projected spin torque in rw frames
                    rw = x0[7::]  # reaction wheels rpm
                    t_ext = np.zeros([3, 1])  # external torque
                    b = np.concatenate([0.5 * np.matmul(self.B(q), np.concatenate([[[0]], w])),
                                        -np.matmul(self.skew(w), (np.matmul(self.I_body_as_B, w) + t_ext +
                                                         sum(rw[i] * self.IsGs[:, i][:, np.newaxis]
                                                             for i in range(self.n)))),
                                        u_s_as_g])
                    xdot = np.matmul(np.linalg.inv(self.A), b)  # time derivative of state vector
                    # x = self.ode45(xdot, x0)  # state vector
                    x = x0 + xdot * dt_cam
                    x[:4] = self.q_norm_and_short(x[:4])  # quaternion normalization constraint and short rotation
                    self.rw_update(x[7::], frame, '+')  # send spin rates to reaction wheels
                    x0 = x
                    t0 = t
                    dcm0 = dcm
                else:  # no target
                    count += 1  # count consecutive non-target frames to break while loop
                    # x = nontracking_maintain(x0)
                    self.rw_update(x[7::], frame, count)
                    # x0 = x
                sync_iter(t_iter, dt_cam)

            # Non-Tracking (because target has not been spotted nor has been within 'nontracking_count' limit):

            x = nontracking_func(x0)
            x[:4] = self.q_norm_and_short(x[:4])  # quaternion normalization constraint and short rotation
            self.rw_update(x[7::], frame, 'n/a')  # send spin rates to reaction wheels
            x0 = x
            sync_iter(t_iter, dt_cam)

    def nontracking_maintain(self, x0):
        """Continue last known state vector."""
        return x0

    def nontracking_shutdown(self, x0):
        """Turn reaction wheels off."""
        return np.zeros_like(x0)

    def nontracking_spindown(self, x0):
        """Reset the reaction wheels."""
        self.rw_read()
        x = x0
        return x

    def rw_read(self):
        """Receive current RPM from reaction wheels."""
        rw = np.zeros([self.n, 1])
        return rw

    def rw_update(self, rw, frame=None, count=None):
        """Send RPM to reaction wheels. Note 'frame' is only for printing to the console when debugging."""
        self.rw_print(rw, frame, count)  # for debugging
        return

    def rw_print(self, rw, frame=None, count=None):
        """Print spin rate (i.e., RPM's) to console for debugging."""
        digits = 4
        len_str = 3 + digits  # +/-, one's place, decimal, digits
        rw_str = []
        for i in range(len(rw)):
            rw_str.append(str(np.round(rw[i][0], digits)))
            if rw_str[i][0] != '-':
                rw_str[i] = ' ' + rw_str[i]
            while len(rw_str[i]) < len_str:
                rw_str[i] += '0'

        if count is not None:
            count = str(count)
            while len(count) < 3:
                count = ' ' + count
        if frame is not None:
            frame = str(frame)
            while len(frame) < 4:
                frame = ' ' + frame
            if count is not None:
                print(f"{frame} | {count} |    {rw_str[0]}    |    {rw_str[1]}    |    {rw_str[2]}")
            else:
                print(f"{frame} |     |    {rw_str[0]}    |    {rw_str[1]}    |    {rw_str[2]}")
        elif count is not None:
            print(f"{count} |    {rw_str[0]}    |    {rw_str[1]}    |    {rw_str[2]}")
        else:
            print(f"{rw_str[0]}    |    {rw_str[1]}    |    {rw_str[2]}")

        return

