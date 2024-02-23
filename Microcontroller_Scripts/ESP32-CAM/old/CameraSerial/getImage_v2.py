import serial
import time
import io

ser = serial.Serial('COM14', 115200)

while True:
    ser.write(b'C')
    try:
        data_length_bytes = ser.read(2)
        if len(data_length_bytes) == 2:
            data_length = int.from_bytes(data_length_bytes, byteorder='big')

            im_raw = ser.read(data_length)

            im_np = np.frombuffer(im_raw,dtype=np.uint8)



        else:
            print("Error: Invalid data length")

    except Exception as e:
        print(f"Error: {str(e)}")

    time.sleep(6)