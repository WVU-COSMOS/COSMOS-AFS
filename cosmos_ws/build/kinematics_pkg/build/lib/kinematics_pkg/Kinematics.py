#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
import numpy as np
import copy
from scipy.integrate import solve_ivp
from cosmos_interfaces.msg import DCM

class Kinematics(Node):
    def __init__(self):
        super().__init__("Kinematics")
        self.get_logger().info("Kinematics Node has been started!") 

        # Subscribers (_s_topic):
        self.dcm_sub_ = self.create_subscription(DCM, "DCM", self.dcm_callback, 10)

        # Initialize:
        self.R = np.zeros([3, 3])
        self.t = 0
        self.x = np.zeros([10, 1])
        self.z0 = np.zeros([3, 1])
        self.rw = np.zeros([3, 1])  # to be updated any time motors change

        # Further initialize of constants for reaction wheels torque control:
        #   - Measurements or calculations to optimize:
        self.I_body_as_B = np.array([[0.4, 0, 0], [0, 0.3, 0], [0, 0, 0.6]])
        self.Is = [5, 5, 5]  # inertia of reaction wheels
        self.Kp = 1  # scalar
        self.Kd = np.ones([3, 3])  # 3x3 matrix, needs to be solved as function of other control gains
        self.Ki = np.ones([3, 3])  # 3x3 matrix, needs to be solved as function of other control gains
        self.gs1 = np.array([-1, 0, 0])[:, np.newaxis]
        self.gs2 = np.array([0, 1, 0])[:, np.newaxis]
        self.gs3 = np.array([0, 0, -1])[:, np.newaxis]
        #   - Constants:
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
        self.t_span = [0, 0.1]  # time invterval to integrate over ... likely 'dt_cam' from camera's FPS setting
    
        self.ode45_args = [self.z0, self.Kp, self.Kd, self.Ki, self.GsT_iGsGsT, self.I_body_as_B, self.IsGs, self.n, self.A]

    def dcm_callback(self, msg):
        """
        Dynamics 'X" node is likely only node listening to this topic. Else, in future development, add a 'to_node' and 'from_node' parameter in DCM.msg.
        
        Store current DCM and t as previous, and store incoming DCM and t as current. Calculations occur elsewhere.
        """
        self.R0 = copy.copy(self.R)
        self.t0 = copy.copy(self.t)
        
        self.R = np.reshape(msg.dcm, (3, 3))

        self.get_logger().info("Incoming DCM saved.")


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
    
    def ode45_stuff(self, x0):
        """
        Imitation of MATLAB's ode45 function.
        
        See: https://www.delftstack.com/howto/python/ode45-function-in-python/

        For reaction wheel application x = inv(A)*b, A is constant but b depends on x.

        x0 == ndarray (10,)
        """
        # Solve:
        sol = solve_ivp(self.dxdt, self.t_span, np.squeeze(x0), args=tuple(self.ode45_args))  # RK45 by default

        # Parse solution:
        x = sol.y[:, -1]  # state vector at end of integration

        x = x[:, np.newaxis]
        x[:4] = self.q_norm_and_short(x[:4])  # normalization constraint and short rotation

        return x  # new state vector from (R, t, R0, t0)
    
    def dcms_to_x(self):
        """
        Return x = f(R, t, R0, t0, z).

        Copied from within while loop of 'acquisition' of old 'COSMOS_AFS.py' (of which dev stopped around Feb. 2024).
        """
        self.get_logger().info(f"Trying 'dcms_to_x' with (t0, t) = ({self.t0}, {self.t}).")
        
        wx = -np.matmul(self.R.T, (self.R - self.R0) / (self.t - self.t0))  # [omega x]
        w = np.array([[wx[2, 1]], [-wx[2, 0]], [wx[1, 0]]])  # omega
        
        q = self.dcm_to_q(self.R)  # error quaternion
        x0 = np.concatenate([q, w, self.rw])
        
        self.x = self.ode45_stuff(x0)  # state vector, integration of (x0 + xdot*dt)

        self.z0 += q[1::]  # update after ode45 called; not sure if qv but assuming because Ki is 3x3
        self.ode45_args[0] = self.z0

        return self.x, self.z0

    def skew(self, u):
        """Return skew matrix of a 3x1 vector."""
        return np.array([[0, 0, u[1, 0]], [0, 0, -u[0, 0]], [-u[1, 0], u[0, 0], 0]])

    def B(self, q):
        """B(q) from quaternion kinematics. (4x1 numpy array input, 4x4 numpy array output)."""
        return np.concatenate([np.concatenate([q[0], -q[1::].T[0]])[np.newaxis],
                            np.concatenate([q[1::], q[0] * np.eye(3) + self.skew(q[1::])], axis=1)])
    
    def q_norm_and_short(self, q):
        """Apply quaternion constraint (i.e., normalize) and enforce short rotation."""
        q = q / np.linalg.norm(q)
        if q[0] < 0:
            q = -q  # short rotation
        q[np.abs(q) < 1e-10] = 0
        return q
    
    def dxdt(self, t, x, z0, Kp, Kd, Ki, GsT_iGsGsT, I_body_as_B, IsGs, n, A):
        """
        ODE function for 'ode45' solver 'solve_ivp'. Variables are also attributes of class but passed as local variables here for 'solve_ivp' functionality.
        
        xdot = inv(A) * b
        """
        x = x[:, np.newaxis]
        
        q = self.q_norm_and_short(x[:4])  # quaternion N to B with normalization constraint and short rotation
        w = x[4:7]  # omega B rel N as B
        rw = x[7::]  # RPM's of reaction wheels

        z = z0 + q[1::]  # error, but only up to current time in ode45
        u_c_as_b = Kp * q[1::] + np.matmul(Kd, w) + Kp * np.matmul(Kd, np.matmul(Ki, z))  # control torque in body frame
        u_s_as_g = np.matmul(GsT_iGsGsT, u_c_as_b)  # projected spin torque in rw frames
        
        b = np.concatenate([0.5 * np.matmul(self.B(q), np.concatenate([[[0]], w])),
                            -np.matmul(self.skew(w), (np.matmul(I_body_as_B, w) + sum(rw[i] * IsGs[:, i][:, np.newaxis] for i in range(n)))),  # assume external torque = 0
                            u_s_as_g])
        
        xdot = np.matmul(np.linalg.inv(A), b)

        return np.squeeze(xdot)  # time derivative of state vector
    
def main(args=None):
    rclpy.init(args=args)
    node = Kinematics()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()