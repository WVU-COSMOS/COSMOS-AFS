#!/usr/bin/env python3
import rclpy
from rclpy.node import Node


class DataAcquisition(Node):
    def __init__(self):
        super().__init__("Data_Acquisition")
        self.create_timer(0.5, self.timer_callback)

    def timer_callback(self):
        self.get_logger().info("Hello from DAQ")


def main(args=None):
    rclpy.init(args=args)
    node = DataAcquisition()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
