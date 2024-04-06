#!/usr/bin/env python3
import rclpy
import numpy as np
from rclpy.node import Node
from cosmos_interfaces.srv import AAToDCM, Skew

class AxisAngleToDCM(Node): 
    def __init__(self):
        super().__init__("AxisAngleToDCM")
        self.aaToDcm_serv_ = self.create_service(AAToDCM, 'axis_angle_to_dcm', self.convertAAtoDCM)
        self.skew_client_ = self.create_client(Skew, 'skew_service')

    def convertAAtoDCM(self, request, response):
        ehat = np.array(request.ehat)
        phimag = request.phimag

        cp = np.cos(phimag)

        dcm = cp * np.eye(3) + (1 - cp) * np.outer(ehat, ehat) - np.sin(phimag) * self.get_skew(ehat)

        response.dcm = dcm.flatten().tolist()
        return response
    
    def get_skew(self, vector):
        skew_matrix = np.zeros((3,3))
        if not self.skew_client_.wait_for_service(timeout_sec=1.0):
            self.get_logger().error('Skew service is not available.')
            return skew_matrix

        request = Skew.Request()
        request.vector = vector.tolist()

        future = self.skew_client_.call_async(request)
        rclpy.spin_until_future_complete(self, future)

        if future.result() is not None:
            skew_matrix = np.array(future.result().skew).reshape((3, 3))
        else:
            self.get_logger().error('Failed to call Skew service.')

        return skew_matrix

def main(args=None):
    rclpy.init(args=args)
    node = AxisAngleToDCM()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()