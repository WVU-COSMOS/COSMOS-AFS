#!/usr/bin/env python3
import rclpy
import serial
from rclpy.node import Node
from example_interfaces.msg import String
from cosmos_interfaces.msg import ReactionWheels
from std_msgs.msg import Int32

class SerialCommunication(Node):
    def __init__(self):
        super().__init__("SerialCommunication")
        self.serial_port = '/dev/ttyUSB0' # Update with the correct serial port
        self.baud_rate = 115200
        self.serial = serial.Serial(self.serial_port, self.baud_rate)

        # Creating the publisher
        self.publisher_ = self.create_publisher(Int32, "gStation_Command", 10)
        self.sm_subscriber = self.create_subscription(ReactionWheels, "esp32_command", self.sm_command, 10)
        self.timer_ = self.create_timer(0.5, self.publish_command)
        self.get_logger().info("Serial Communication has been started!")
        

    def publish_command(self):
        msg = int(self.serial.readline().decode().strip())
        if msg:
            self.get_logger().info(f"Publishing Mission: {msg}")
            self.publisher_.publish(Int32(data=msg))

    def sm_command(self, msg):
        self.get_logger().info(f"Received: {msg.motor_x}, {msg.speed_x}, {msg.time_x}")
        command_string = f"{msg.motor_x},{msg.speed_x},{msg.time_x}\n"
        # Send the command via serial to ESP32
        self.serial.write(command_string.encode())
        self.get_logger().info(f"Sent command to ESP32: {command_string}")


def main(args=None):
    rclpy.init(args=args)
    node = SerialCommunication()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
