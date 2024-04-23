- https://physics.stackexchange.com/questions/578359/possible-to-convert-accelerometer-x-y-z-measurements-into-quaternion
- https://ahrs.readthedocs.io/en/latest/filters/aqua.html
- https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing
- https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/

Decompose 3 accelerations into Euler angles.



![COSMOS-Body-Frame](/docs/_static/body_frame.png)

Defining accelerometer axes to align with body frame such that gravity is in $-\hat{b}_3$ direction when satellite is at rest,

$\mathbf{R}^A_B {}^A\mathbf{a} = {}^B\mathbf{a} = \begin{bmatrix} 0 \\ 0 \\ -g \end{bmatrix}$

Then, 321 Euler sequence without yaw yields

$\mathbf{R}_1(-\phi) \mathbf{R}_2(-\theta) {}^B\mathbf{a} = \begin{bmatrix} 1 & 0 & 0 \\ 0 & \cos(-\phi) & -\sin(-\phi) \\ 0 & \sin(-\phi) & \cos(-\phi) \end{bmatrix} \begin{bmatrix} \cos(-\theta) & 0 & \sin(-\theta) \\ 0 & 1 & 0 \\ -\sin(-\theta) & 0 & \cos(-\theta) \end{bmatrix} \begin{bmatrix} 0 \\ 0 \\ -g \end{bmatrix} = \begin{bmatrix} g \sin(\theta) \\ -g \sin(\phi) \cos(\theta) \\ -g \cos(\phi) \cos(\theta) \end{bmatrix}$

Roll $\phi$ and pitch $\theta$ are then

$\begin{cases}
\phi = \tan^{-1}(\frac{\sin(\phi)}{\cos(\phi)}) = \tan^{-1}(\frac{-g \sin(\phi) \cos(\theta)}{-g \cos(\phi) \cos(\theta)}) = \tan^{-1}(\frac{a_y}{a_z}) \implies \text{np.arctan2}(a_y,\ a_z) 
\\
\theta = \tan^{-1}(\frac{\sin(\theta)}{\cos(\theta)}) = \tan^{-1}(\frac{g \sin(\theta)}{\sqrt{(-g \sin(\phi) \cos(\theta))^2 + (-g \cos(\phi) \cos(\theta))^2}}) = \tan^{-1}(\frac{a_x}{\sqrt{a_y^2 + a_z^2}}) \implies \text{np.arctan2}(a_x,\ \sqrt{a_y^2 + a_z^2}) 
\end{cases}$

Examining the lowest point of the cubic satellite with side length $L$,

$\mathbf{R}_1(|\phi|) \mathbf{R}_2(|\theta|) \begin{bmatrix} L/2 \\ -L/2 \\ -L/2 \end{bmatrix}
= \frac{L}{2} \begin{bmatrix} \cos(|\theta|) - \sin(|\theta|) \\ \sin(|\phi|) (\sin(|\theta|)+\cos(|\theta|)) - \cos(|\phi|) \\ -\cos(|\phi|) (\sin(|\theta|)+\cos(|\theta|)) - \sin(|\phi|) \end{bmatrix} 
= \begin{bmatrix} \dots \\ \dots \\ -\frac{L}{2}(\cos(|\phi|) (\sin(|\theta|)+\cos(|\theta|)) + \sin(|\phi|)) \end{bmatrix}$

Defining $T$ as the maximum allowed $z$-offset of any satellite corner $C$ in the $\hat{b}_3$ direction,

$T \ge C_0 - C_{\phi,\theta} = -\frac{L}{2} + \frac{L}{2}(\cos(|\phi|) (\sin(|\theta|)+\cos(|\theta|)) + \sin(|\phi|)) 
\implies
2 \frac{T}{L} + 1 \ge \sin(|\phi|) + \cos(|\phi|)(\sin(|\theta|)+\cos(|\theta|))$




