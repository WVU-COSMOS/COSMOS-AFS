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
        self.gStationPub_ = self.create_publisher(Int32, "gStation_Command", 10)
        self.rWheelsPub_ = self.create_publisher(ReactionWheels, "esp32_command", 10)

        # Creating the subcribers
        self.rWheelsSub_ = self.create_subscription(ReactionWheels, "esp32_command", self.sm_command_callback, 10)

        self.last_serial_message = None

        self.timer_ = self.create_timer(0.1, self.check_serial)

        self.get_logger().info("Serial Communication has been started!")
        
    def check_serial(self):
        # Check for new messages from the serial port
        if self.serial.in_waiting > 0:
            serial_data = self.serial.readline().decode().strip()
            self.last_serial_message = int(serial_data)
            self.get_logger().info(f"Received from serial: {self.last_serial_message}")
            # Publish the received message to the "gStation_Command" topic
            self.gStationPub_.publish(Int32(data=self.last_serial_message))
            
    def publish_command(self):
        msg = int(self.serial.readline().decode().strip())
        if msg:
            self.get_logger().info(f"Publishing Mission: {msg}")
            self.gStationPub_.publish(Int32(data=msg))

    def sm_command_callback(self, msg):
        self.get_logger().info(f"Command Received!")
        command_string = f"{int(msg.motor_x)},{int(msg.motor_y)},{int(msg.motor_z)}, \
                               {msg.speed_x},{msg.speed_y},{msg.speed_z} \
                               {msg.time_x},{msg.time_y},{msg.time_z}\n"
        # Send the command via serial to ESP32
        self.serial.write(command_string.encode())
        self.get_logger().info(f"Sent command to ESP32: {command_string}")

        msg = ReactionWheels()
        msg.is_done = True
        self.rWheelsPub_.publish(msg)
        self.get_logger().info(f"Task Completed!")

def main(args=None):
    rclpy.init(args=args)
    node = SerialCommunication()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
