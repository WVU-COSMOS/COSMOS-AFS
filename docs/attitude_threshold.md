# Attitude Thresholding in Kinematics Node for SAB Table Limits

Power on satellite, at rest, with $\{ \hat{b}_1,\ \hat{b}_2 \}$ aligned to $\{ \hat{n}_1,\ \hat{n}_2 \}$ such that $x_0 = \overline{\mathbf{0}}$.

Propagate state vector.

$x = \begin{bmatrix} \overline{q}^N_B \\ ^B\vec{\omega}_{B/N} \\ \Omega \end{bmatrix} = x_0 + \int{\dot{x}\ dt} = f(x_0,\ \dot{R})$

Determine Euler angles for 321 sequence from attitude quaternion.

$\mathbf{R} \equiv \mathbf{R}^N_B = \text{q\_to\_dcm(} \overline{\mathbf{q}}^N_B \text{)} \implies R_{ij}$

$\mathbf{R_{321}}(\phi, \theta, \psi) = \mathbf{R_1}(\phi) \mathbf{R_2}(\theta) \mathbf{R_3}(\psi) = \begin{bmatrix} c_{\theta} c_{\psi} & c_{\theta} s_{\psi} & -s_{\theta} \\ -c_{\phi} s_{\psi} + s_{\phi} s_{\theta} c_{\psi} & c_{\phi} c_{\psi} + s_{\phi} s_{\theta} s_{\psi} & s_{\phi} c_{\theta} \\ s_{\phi} s_{\psi} + c_{\phi} s_{\theta} c_{\psi} & -s_{\phi} c_{\psi} + c_{\phi} s_{\theta} s_{\psi} & c_{\phi} c_{\theta} \end{bmatrix}$

$\implies \begin{cases} \theta = \sin^{-1}(-R_{13}) & \exist \ [-\frac{\pi}{2},\ \frac{\pi}{2}] \\ \phi = \sin^{-1}(\frac{R_{23}}{\cos(\theta)}) & \exist \ [-\frac{\pi}{2}, \ \frac{\pi}{2}] \\ \psi = \text{np.arctan2(} \frac{R_{12}}{\cos(\theta)},\ \frac{R_{11}}{\cos(\theta)} \text{)} & \exist \ [0, \ \pi) \end{cases}$

If $[\phi,\ \theta]$ exceeds threshold $\tau \equiv \frac{\text{max}}{\eta}\approx 40^{\circ}$,
- Limit angle(s).
    - $\begin{cases} \phi = \tau & \text{if}\ \phi \gt \tau \\ \phi = -\tau & \text{if}\ \phi \lt -\tau \\ \theta = \tau & \text{if}\ \theta \gt \tau \\ \theta = -\tau & \text{if}\ \theta \lt -\tau \end{cases}$
- Reconstruct DCM.
    - $\mathbf{R} \equiv \mathbf{R}^N_B = \mathbf{R_{321}}(\phi, \theta, \psi)$
- Re-propagate state vector using new $\mathbf{R}$ for $\dot{\mathbf{R}}$. The previously used $\mathbf{R}_0$ remains the same.

Publish state vector.

