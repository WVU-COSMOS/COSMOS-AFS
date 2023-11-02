#!/usr/bin/env python3
import rclpy
import serial
from rclpy.node import Node
from example_interfaces.msg import String


class GroundStation(Node):
    def __init__(self):
        super().__init__("Ground_Station")
        self.serial_port = '/dev/ttyACM0' # Update with the correct serial port
        self.baud_rate = 9600
        self.serial = serial.Serial(self.serial_port, self.baud_rate)

        # Creating the publisher
        self.publisher_ = self.create_publisher(String, "GStation_Command", 10)
        self.timer_ = self.create_timer(0.5, self.publish_command)
        self.get_logger().info("Ground Station has been started!")
        

    def publish_command(self):
        msg = String()
        while rclpy.ok():
            msg.data = self.serial.readline().decode().strip()
            self.get_logger().info(f'Received: {msg.data}')
            self.publisher_.publish(msg)


def main(args=None):
    rclpy.init(args=args)
    node = GroundStation()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
