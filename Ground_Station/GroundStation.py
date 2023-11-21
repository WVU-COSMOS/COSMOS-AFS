import serial
import sys

serial_port = 'COM3'  
baud_rate = 115200

def switch(mission):
    if mission == "1":
        message = "1*"
        ser.write(message.encode())
        print(f"Mission Selected: {mission}")
        # Wait for response from serial communication
        response = ser.readline().decode().strip()
        print(f"Response from Serial: {response}")
    elif mission == "2":
        message = "2*"
        ser.write(message.encode())
        print(f"Mission Selected: {mission}")
        # Wait for response from serial communication
        response = ser.readline().decode().strip()
        print(f"Response from Serial: {response}")
    elif mission == "3":
        message = "3*"
        ser.write(message.encode())
        print(f"Mission Selected: {mission}")
        # Wait for response from serial communication
        response = ser.readline().decode().strip()
        print(f"Response from Serial: {response}")
    if mission == "0":
        print("Exiting COSMOS.")
        sys.exit()

def mission_selection():
    print("|----------------------------------------------------------------|")
    print("|                           COSMOS                               |")
    print("|----------------------------------------------------------------|")
    print("|  1 - Mission 1 (Move)                                          |")
    print("|  2 - Mission 2 (Picture)                                       |")
    print("|  3 - Mission 3 (Track)                                         |")
    print("|  0 - Exit                                                      |")
    print("|----------------------------------------------------------------|")

try:
    ser = serial.Serial(serial_port, baud_rate)
    print("|----------------------------------------------------------------|")
    print(f"|  Connected to {serial_port} at {baud_rate} baud                              |")

    while True:
        mission_selection()
        message = input("Enter the mission number: ")

        switch(message)

except serial.SerialException:
    print("Error: Could not open the serial port. Make sure it's available and the correct port name is specified.")
except KeyboardInterrupt:
    ser.close()
    print("Serial port closed.")
