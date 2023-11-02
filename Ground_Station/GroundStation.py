import serial

serial_port = 'COM5'  
# On Windows, this might be 'COMX', where X is the port number
# On Linux, it may be something like '/dev/ttyUSB0'

baud_rate = 9600

try:
    ser = serial.Serial(serial_port, baud_rate)
    print(f"Connected to {serial_port} at {baud_rate} baud")

    while True:
        message = input("Enter a message to send to Arduino: ")
        ser.write(message.encode())
        print(f"Sent: {message}")

except serial.SerialException:
    print("Error: Could not open the serial port. Make sure it's available and the correct port name is specified.")
except KeyboardInterrupt:
    ser.close()
    print("Serial port closed.")