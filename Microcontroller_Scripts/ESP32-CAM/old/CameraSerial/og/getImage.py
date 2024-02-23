import serial
import io

ser = serial.Serial('COM15', 115200)

while True:
    try:
        data_length_bytes = ser.read(2)
        if len(data_length_bytes) == 2:
            data_length = int.from_bytes(data_length_bytes, byteorder='big')

            raw_data = ser.read(data_length)
            print(raw_data)

        else:
            print("Error: Invalid data length")

    except Exception as e:
        print(f"Error: {str(e)}")