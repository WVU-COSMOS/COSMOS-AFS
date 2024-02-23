# For receiving RGB565 images via serial from ESP32-CAM.

import serial
import struct
import time

port = "COM15"
baudrate = 115200
bytes_per_pixel = 2  # RGB565 format (16 bits or 2 bytes per pixel)
breaktime = 5

# ================

ser = serial.Serial(port=port, baudrate=baudrate,
                    bytesize=serial.EIGHTBITS,
                    parity=serial.PARITY_NONE,
                    stopbits=serial.STOPBITS_ONE,
                    timeout=1.5, exclusive=1)

# starttime = time.time()
# data = []

data = b''
ser.write(b'C')  # send command to capture image
time.sleep(0.5)
while True:
    data = ser.read()
    if data:
        print(data)









# while not data:
#     raw_data = ser.read(bytes_per_pixel)
#     if time.time() - starttime > breaktime:
#         break
#     if raw_data:
#         data.append(raw_data)
#
# if len(raw_data) == bytes_per_pixel:
#     # Unpack the 16-bit RGB565 data into R, G, and B components
#     r5, g6, b5 = struct.unpack("<H", raw_data)
#
#     # Convert RGB565 values to 8-bit values (optional)
#     r8 = (r5 << 3) & 0xFF
#     g8 = ((g6 << 2) | (g6 >> 4)) & 0xFF
#     b8 = (b5 << 3) & 0xFF
#
#     # Process or display the RGB888 (8-bit) values as needed
#     print(f"R: {r8}, G: {g8}, B: {b8}")
#
# ser.close()

b=1
