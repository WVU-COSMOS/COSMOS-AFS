# Accelerometer

The IMU sensor for COSMOS is GY-521 MPU6050. This connects to the ESP32 DAQ via 'Microcontroller_Scripts/ESP32_DAQ', which was modified from the Adafruit MPU6050 'basis_readings.ino' stock example. As of 2024/04/24, the IMU does not interface with the ROS2 code and instead the Kinematics node is written to calculate the angular velocity from $[\omega \cross] = \dot{\mathbf{R}}$.
- Example: https://github.com/adafruit/Adafruit_MPU6050/blob/master/examples/basic_readings/basic_readings.ino
- Walkthrough of example, with wiring diagram: https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/

Resources for mathematics:
- https://physics.stackexchange.com/questions/578359/possible-to-convert-accelerometer-x-y-z-measurements-into-quaternion
- https://ahrs.readthedocs.io/en/latest/filters/aqua.html
- https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing

Stock example running GY-521 MPU6050 accelerometer:
- https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/

---

Goal is to decompose 3 accelerations into Euler angles.

Defining accelerometer axes to align with body frame such that gravity is in $-\hat{b}_3$ direction when satellite is at rest,

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





