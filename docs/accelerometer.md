- https://physics.stackexchange.com/questions/578359/possible-to-convert-accelerometer-x-y-z-measurements-into-quaternion
- https://ahrs.readthedocs.io/en/latest/filters/aqua.html
- https://wiki.dfrobot.com/How_to_Use_a_Three-Axis_Accelerometer_for_Tilt_Sensing
- https://randomnerdtutorials.com/esp32-mpu-6050-accelerometer-gyroscope-arduino/

Decompose 3 accelerations into Euler angles.



![COSMOS-Body-Frame](/docs/_static/body_frame.png)

Accelerometer measures
$^L \mathbf{a} = [a_x,\ a_y,\ a_z]^T \equiv \text{measured accelerations}$
$^B \mathbf{a} = \mathbf{R}^L_B [a_x,\ a_y,\ a_z]^T$

For 123 (though 321 is what attitude_threshold uses) Euler sequence,
$\phi_{123} = \tan^{-1}(\frac{a_y}{a_z})$
$\theta_{123} = \tan^{-1}(\frac{-a_x}{\sqrt{a_y^2+a_z^2}})$

