# Accelerometer

## Overview

The IMU sensor for COSMOS is GY-521 MPU6050. This connects to the ESP32 DAQ via [*ESP32_DAQ.ino*](Microcontroller_Scripts/ESP32_DAQ/ESP32_DAQ.ino) which was based upon the Adafruit MPU6050 [*basis_readings.ino*](https://github.com/adafruit/Adafruit_MPU6050/blob/master/examples/basic_readings/basic_readings.ino) stock example. As of April 24th, 2024, the IMU does not interface with ROS and instead the Kinematics node is written to calculate angular velocity from $\dot{\mathbf{R}} = \mathbf{R} [^B\vec{\mathbf{\omega}}_{B/N} \times]$ using a backwards difference approximation of $\dot{\mathbf{R}}$. Attitude is then thresholded above the SAB table by decomposing $\overline{\mathbf{q}}^N_B$ from the new proposed state vector into Euler angles, thresholding pitch and roll, then reconstructing a new DCM to re-propagate the state vector if pitch or roll were thresholded. The below wiring diagram was taken from https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/.

![GY-521_MPU6050_wiring_diagram_for_ESP32](/docs/_static/GY-521_MPU6050_wiring_diagram_for_ESP32.png)

---

## Resources for Mathematics

- https://physics.stackexchange.com/questions/578359/possible-to-convert-accelerometer-x-y-z-measurements-into-quaternion
- https://ahrs.readthedocs.io/en/latest/filters/aqua.html
- https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing

---

## Dynamics Derivation

The IMU measures linear acceleration and angular velocity. The goal is to decompose the three measured accelerations into Euler angles pitch $\theta$ and roll $\phi$. Angular velocity may be used as is.

First, defining accelerometer axes to align with body frame such that gravity is in $-\hat{b}_3$ direction when satellite is at rest,

![COSMOS-Body-Frame](/docs/_static/body_frame.png)

```math
\mathbf{R}^A_B {}^A\mathbf{a} = {}^B\mathbf{a} = \begin{bmatrix} 0 \\ 0 \\ -g \end{bmatrix}
```

Then, 321 Euler sequence without yaw yields

```math
\mathbf{R}_1(-\phi) \mathbf{R}_2(-\theta) {}^B\mathbf{a} = \begin{bmatrix} 1 & 0 & 0 \\ 0 & \cos(-\phi) & -\sin(-\phi) \\ 0 & \sin(-\phi) & \cos(-\phi) \end{bmatrix} \begin{bmatrix} \cos(-\theta) & 0 & \sin(-\theta) \\ 0 & 1 & 0 \\ -\sin(-\theta) & 0 & \cos(-\theta) \end{bmatrix} \begin{bmatrix} 0 \\ 0 \\ -g \end{bmatrix} = \begin{bmatrix} g \sin(\theta) \\ -g \sin(\phi) \cos(\theta) \\ -g \cos(\phi) \cos(\theta) \end{bmatrix}
```

Roll $\phi$ and pitch $\theta$ are then

```math
\begin{cases}
\phi = \tan^{-1}(\frac{\sin(\phi)}{\cos(\phi)}) = \tan^{-1}(\frac{-g \sin(\phi) \cos(\theta)}{-g \cos(\phi) \cos(\theta)}) = \tan^{-1}(\frac{a_y}{a_z}) \implies \text{np.arctan2}(a_y,\ a_z) 
\\
\theta = \tan^{-1}(\frac{\sin(\theta)}{\cos(\theta)}) = \tan^{-1}(\frac{g \sin(\theta)}{\sqrt{(-g \sin(\phi) \cos(\theta))^2 + (-g \cos(\phi) \cos(\theta))^2}}) = \tan^{-1}(\frac{a_x}{\sqrt{a_y^2 + a_z^2}}) \implies \text{np.arctan2}(a_x,\ \sqrt{a_y^2 + a_z^2}) 
\end{cases}
```

Examining the lowest point of the cubic satellite with side length $L$,

```math
\mathbf{R}_1(|\phi|) \mathbf{R}_2(|\theta|) \begin{bmatrix} L/2 \\ -L/2 \\ -L/2 \end{bmatrix}
= \frac{L}{2} \begin{bmatrix} \cos(|\theta|) - \sin(|\theta|) \\ \sin(|\phi|) (\sin(|\theta|)+\cos(|\theta|)) - \cos(|\phi|) \\ -\cos(|\phi|) (\sin(|\theta|)+\cos(|\theta|)) - \sin(|\phi|) \end{bmatrix} 
= \begin{bmatrix} \dots \\ \dots \\ -\frac{L}{2}(\cos(|\phi|) (\sin(|\theta|)+\cos(|\theta|)) + \sin(|\phi|)) \end{bmatrix}
```

Defining $T$ as the maximum allowed $z$-offset of any satellite corner $C$ in the $\hat{b}_3$ direction,

```math
T \ge C_0 - C_{\phi,\theta} = -\frac{L}{2} + \frac{L}{2}(\cos(|\phi|) (\sin(|\theta|)+\cos(|\theta|)) + \sin(|\phi|)) 
\implies
2 \frac{T}{L} + 1 \ge \sin(|\phi|) + \cos(|\phi|)(\sin(|\theta|)+\cos(|\theta|))
```






