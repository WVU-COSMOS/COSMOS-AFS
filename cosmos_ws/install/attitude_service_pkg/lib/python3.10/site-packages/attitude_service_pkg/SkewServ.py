#!/usr/bin/env python3
import rclpy
import numpy as np
from rclpy.node import Node
from cosmos_interfaces.srv import Skew

class SkewServ(Node):
    def __init__(self):
        super().__init__("SkewServ")
        self.skew_serv_ = self.create_service(Skew, 'skew_service', self.compute_skew)
    
    def compute_skew(self, request, response):
        vector = np.array(request.vector)
        skew_matrix = np.array([[0, -vector[2], vector[1]],
                                [vector[2], 0, -vector[0]],
                                [-vector[1], vector[0], 0]])

        response.skew = skew_matrix.flatten().tolist()
        return response

def main(args=None):
    rclpy.init(args=args)
    node = SkewServ()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()