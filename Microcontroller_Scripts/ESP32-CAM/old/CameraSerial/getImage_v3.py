import serial
import time
# import io


ser = serial.Serial('COM14', 115200)

while True:
    t_out = time.time()
    ser.write(b'C')
    try:
        data_length_bytes = ser.read(30)
        # handle case here of image not starting with b'\xff\xd8\...', e.g., if date and time are displayed

        t_in = time.time()
        t_len = t_in - t_out
        print(t_len)
        # if len(data_length_bytes) == 2:
        #     data_length = int.from_bytes(data_length_bytes, byteorder='big')
        #
        #     im_raw = ser.read(data_length)
        #
        #     im_np = np.frombuffer(im_raw,dtype=np.uint8)
        #
        #
        #
        # else:
        #     print("Error: Invalid data length")

    except Exception as e:
        print(f"Error: {str(e)}")

    time.sleep(6)




# NOTES FOR FUTURE OPTIMIZATION

#   - why are the hex values being sent as bytes ?
#       - typically, 2 hex digits per byte, but some bytes have 6 hex (e.g., '...\xe0\x00\10JFIF\...'
#       - if the hex values can be packed into less bytes, then faster data transfer



# NOTE FOR JPEG STRUCTURE

#   - marker / length
#   - FFD8
#   - FFE0 / 16
#   - FFDB / 67
#   - FFDB / 67
#   - FFC0 / 17
#   - FFC4 / 21
#   - FFC4 / 25
#   - FFC4 / 21
#   - FFC4 / 28
#   - FFDA / 12




