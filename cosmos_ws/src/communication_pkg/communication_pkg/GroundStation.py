#!/usr/bin/env python3
import rclpy
import serial
from rclpy.node import Node
from example_interfaces.msg import String
from std_msgs.msg import Int32


class GroundStation(Node):
    def __init__(self):
        super().__init__("Ground_Station")
        self.serial_port = '/dev/ttyUSB0' # Update with the correct serial port
        self.baud_rate = 115200
        self.serial = serial.Serial(self.serial_port, self.baud_rate)

        # Creating the publisher
        self.publisher_ = self.create_publisher(Int32, "gStation_Command", 10)
        self.sm_subscriber = self.create_subscription(String, "sm_Communication", self.sm_command, 10)
        self.timer_ = self.create_timer(0.5, self.publish_command)
        self.get_logger().info("Ground Station has been started!")
        

    def publish_command(self):
        msg = int(self.serial.readline().decode().strip())
        if msg:
            self.get_logger().info(f"Publishing Mission: {msg}")
            self.publisher_.publish(Int32(data=msg))

    def sm_command(self, msg):
        command = msg.data
        self.get_logger().info(f"Received Command from State Machine: {command}")

        # Send the command via serial to ESP32
        self.serial.write(command.encode())
        self.get_logger().info(f"Sent command to ESP32: {command}")


def main(args=None):
    rclpy.init(args=args)
    node = GroundStation()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
