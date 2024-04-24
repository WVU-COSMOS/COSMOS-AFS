# Attitude Thresholding With IMU

## Overview

The IMU sensor for COSMOS is GY-521 MPU6050. This connects to the ESP32 DAQ via [*ESP32_DAQ.ino*](Microcontroller_Scripts/ESP32_DAQ/ESP32_DAQ.ino) which was based upon the Adafruit MPU6050 [*basis_readings.ino*](https://github.com/adafruit/Adafruit_MPU6050/blob/master/examples/basic_readings/basic_readings.ino) stock example. As of April 24th, 2024, the IMU does not interface with ROS and instead the Kinematics node is written to calculate angular velocity from $\dot{\mathbf{R}} = \mathbf{R} [^B\vec{\mathbf{\omega}}_{B/N} \times]$ using a backwards difference approximation of $\dot{\mathbf{R}}$. Attitude is then thresholded above the SAB table by decomposing $\overline{\mathbf{q}}^N_B$ from the new proposed state vector into Euler angles, thresholding pitch and roll, then reconstructing a new DCM to re-propagate the state vector if pitch or roll were thresholded. In future development, this document can be implemented to measure angular velocity, pitch, and roll directly, instead of approximating with calculations. The below wiring diagram was taken from https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/.

![GY-521_MPU6050_wiring_diagram_for_ESP32](/docs/_static/GY-521_MPU6050_wiring_diagram_for_ESP32.png)

---

## Resources for Mathematics

- https://physics.stackexchange.com/questions/578359/possible-to-convert-accelerometer-x-y-z-measurements-into-quaternion
- https://ahrs.readthedocs.io/en/latest/filters/aqua.html
- https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing

---

## Dynamics Derivation

The IMU measures linear acceleration and angular velocity. The goal is to decompose the three measured accelerations into Euler angles pitch $\theta$ and roll $\phi$. Angular velocity may be used as is.

First, defining accelerometer axes rotated from accelerometer frame $A$ by fixed $\mathbf{R}^A_B$ to align with body frame $B$ such that gravity is in $-\hat{b}_3$ direction when satellite attitude is flat (i.e., $(\phi, \theta) = 0$),

![COSMOS-Body-Frame](/docs/_static/body_frame.png)

To be thorough, for a 321 Euler sequence,

```math
{}^B\mathbf{a} = \mathbf{R}^A_B {}^A\mathbf{a} = \begin{cases} [-g,\ 0,\ 0]^T \\ [0,\ -g,\ 0]^T \\ [0,\ 0,\ -g]^T \end{cases}\ \text{where}\ (\phi, \theta, \psi) \in \begin{cases} (\mathbb{R}, -90^{\circ}, \mathbb{R}) \\ (90^{\circ}, 0^{\circ}, \mathbb{R}) \\ (0^{\circ}, 0^{\circ}, \mathbb{R}) \end{cases}\ \text{and}\ {}^A\mathbf{a}\ \text{are measured accelerations.}
```

Then, the $(\phi, \theta, \psi)$ angles for a 321 Euler sequence that the accelerometer has undergone from ${}^B\mathbf{a} = [0,\ 0\, -g]^T$ are

```math
\mathbf{R}_1(-\phi) \mathbf{R}_2(-\theta) \mathbf{R}_3(-\psi) {}^B\mathbf{a} =
\mathbf{R}_1(-\phi) \mathbf{R}_2(-\theta) {}^B\mathbf{a} =
\begin{bmatrix} 1 & 0 & 0 \\ 0 & \cos(-\phi) & -\sin(-\phi) \\ 0 & \sin(-\phi) & \cos(-\phi) \end{bmatrix}
\begin{bmatrix} \cos(-\theta) & 0 & \sin(-\theta) \\ 0 & 1 & 0 \\ -\sin(-\theta) & 0 & \cos(-\theta) \end{bmatrix}
\begin{bmatrix} 0 \\ 0 \\ -g \end{bmatrix} =
\begin{bmatrix} g \sin(\theta) \\ -g \sin(\phi) \cos(\theta) \\ -g \cos(\phi) \cos(\theta) \end{bmatrix}
```

Note yaw $\psi$ cannot be determined because 

```math
\mathbf{R}_3(-\psi) {}^B\mathbf{a} =
\begin{bmatrix} \cos(-\psi) & -\sin(-\psi) & 0 \\ \sin(-\psi) & \cos(-\psi) & 0 \\ 0 & 0 & 1 \end{bmatrix}
\begin{bmatrix} 0 \\ 0 \\ -g \end{bmatrix} =
\begin{bmatrix} 0 \\ 0 \\ -g \end{bmatrix} = {}^B\mathbf{a}
```

Roll $\phi$ and pitch $\theta$ are then

```math
\begin{cases}
\phi = \tan^{-1}(\frac{\sin(\phi)}{\cos(\phi)}) = \tan^{-1}(\frac{-g \sin(\phi) \cos(\theta)}{-g \cos(\phi) \cos(\theta)}) = \tan^{-1}(\frac{a_y}{a_z}) \implies \text{np.arctan2}(a_y,\ a_z) 
\\
\theta = \tan^{-1}(\frac{\sin(\theta)}{\cos(\theta)}) = \tan^{-1}(\frac{g \sin(\theta)}{\sqrt{(-g \sin(\phi) \cos(\theta))^2 + (-g \cos(\phi) \cos(\theta))^2}}) = \tan^{-1}(\frac{a_x}{\sqrt{a_y^2 + a_z^2}}) \implies \text{np.arctan2}(a_x,\ \sqrt{a_y^2 + a_z^2}) 
\end{cases}
```

## Attitude Thresholding

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

It may be most practical to implement something simple like $(|\phi|, |\theta|) \lesssim 40^{\circ}$, but the above $2 \frac{T}{L} + 1$ is the true threshold.

After thresholding roll $\phi$ and pitch $\theta$ as needed, reconstruct $\mathbf{R}^N_B$ to re-propagate the state vector such that the rotation is within the bounds of the SAB table. Note yaw $\psi$ will likely need to be inferred from the attitude quaternion $\overline{\mathbf{q}}^N_B$ contained in the state vector by converting to a DCM and deconstructing into $(\phi, \theta, \psi)$ 321 Euler sequence. From [*attitude_thresholding_without_IMU.md*](\docs/attitude_thresholding_without_IMU.md), that is $\psi = \text{np.arctan2}(\frac{R_{12}}{\cos(\theta)},\ \frac{R_{11}}{\cos(\theta)})$ where $R_{12}$ and $R_{11}$ come from $\overline{\mathbf{q}}^N_B$ but $\theta$ comes from the IMU.

Then,

```math
\mathbf{R}^N_B = 
```

and this DCM replaces the current $\mathbf{R}$ so that a new $\dot{\mathbf{R}}$ may drive the re-propagation of the state vector in the Kinematics node. Be careful if the previous DCM was received from the ImageToDCM node, as that will be $\mathbf{R}^{Camera}_{Target}$ instead of $\mathbf{R}^N_B$.

