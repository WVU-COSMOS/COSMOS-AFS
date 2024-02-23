import serial
import time


comm = b"C" # command to capture image
FPS = 5

# ======================================================================================================================

ser = serial.Serial('COM15', 115200, timeout=100)
SPF = 1/FPS

comm_id = 0
data = []
while True:
    time_start = time.time()

    ser.write(comm)
    comm_id = comm_id + 1
    print('Command sent.')

    try:
        print('Reading serial port.')
        im_size = ser.read(1)
        print(im_size)
        # data_length_bytes = ser.read(im_size*2)
        print('Serial port read.')
        # if len(data_length_bytes) == 2:
        #     data_length = int.from_bytes(data_length_bytes, byteorder='big')
        #     data_raw = ser.read(data_length)
        #
        #     print(data_raw)
        #
        #     data.append(data_raw)
        #
        # else:
        #     print("Error: Invalid data length")

    except Exception as e:
        print(f"Error: {str(e)}")

    time.sleep(SPF)

