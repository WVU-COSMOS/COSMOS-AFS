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
    elif mission == "4":
        message = "4*"
        ser.write(message.encode())
        print(f"Mission Selected: {mission}")
        # Wait for response from serial communication
        response = ser.readline().decode().strip()
        print(f"Response from Serial: {response}")
    elif mission == "5":
        message = "5*"
        ser.write(message.encode())
        print(f"Mission Selected: {mission}")
        # Wait for response from serial communication
        response = ser.readline().decode().strip()
        print(f"Response from Serial: {response}")
    elif mission == "6":
        s = input("Enter the command: ")
        command = "0,150,2000\n"
        s = s + "\n"
        ser.write(s.encode())
        print(f"Sent command: {s}")
    elif mission == "0":
        print("Exiting COSMOS.")
        sys.exit()

def mission_selection():
    print("|----------------------------------------------------------------|")
    print("|                           COSMOS                               |")
    print("|----------------------------------------------------------------|")
    print("|  1 - Mission 1 (Test Reaction Wheels)                          |")
    print("|  2 - Mission 2 (Orbit)                                         |")
    print("|  3 - Mission 3 (Follow)                                        |")
    print("|  4 - Mission 4 (Track)                                         |")
    print("|  5 - Mission 5 (Move by Target)                                |")
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