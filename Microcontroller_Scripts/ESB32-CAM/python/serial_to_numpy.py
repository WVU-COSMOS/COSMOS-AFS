import serial
import time

# Define the serial port and baud rate:
serial_port = "COM14"
baud_rate = 115200

# ======================================================================================================================

ser = serial.Serial(serial_port, baud_rate)

# Listen to serial port:
while True:

    # Send the capture command to ESP32-CAM:
    ser.write(b'C')

    image_raw = b'\x00'
    while image_raw == b'\x00':
        image_raw = ser.read()

    time.sleep(10) # wait 5 seconds








# # ======================================================================================================================
# # OUT OF DATE AS OF 20231030
#
#
# ser = serial.Serial(serial_port, baud_rate, timeout=1)
#
# def capture_image_and_receive():
#     try:
#         while True:
#             # Send the capture command to ESP32-CAM
#             ser.write(b'C')
#             print("1) command sent")
#
#             # Read the image data from the ESP32-CAM
#             image_started = False
#             image_data = bytearray()
#             image_length = 0
#
#             time_start = time.time()
#             while True:
#                 chunk = ser.read(1)
#                 print("2) chunk read")
#                 if chunk:
#                     print("3a) yes chunk")
#                     if image_started:
#                         print("3a.a) image started")
#                         image_data.extend(chunk)
#                         if b'IMAGE_END' in image_data:
#                             print("3a.a2) image ended")
#                             break
#                     else:
#                         print("3a.b) image continuing")
#                         image_data.extend(chunk)
#                         if b'IMAGE_START' in image_data:
#                             print("3a.b2) image starting")
#                             image_started = True
#                             length_header = image_data.split(b'IMAGE_START')[1]
#                             image_length = int.from_bytes(length_header, byteorder='big', signed=False)
#                 else:
#                     print("3b) no chunk")
#                     time_current = time.time()
#                     if time_current - time_start > time_tolerance:
#                         print("4a) breaking")
#                         break
#                     else:
#                         print("4b) waiting")
#                         time.sleep(0.01)  # Wait for data to arrive
#
#             if image_length > 0:
#                 print("5) image length")
#                 with open(f'captured_image_{int(time.time())}.jpg', 'wb') as img_file:
#                     img_file.write(image_data)
#                 print(f"Image saved as 'captured_image_{int(time.time())}.jpg'")
#                 time.sleep(10)  # Capture an image every 10 seconds
#
#     except KeyboardInterrupt:
#         pass
#     finally:
#         ser.close()
#
# if __name__ == "__main__":
#     capture_image_and_receive()
