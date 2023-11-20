
import serial

# Define the serial port and baud rate
ser = serial.Serial('COM14', 115200)
ser.timeout = 21  # seconds until timeout when reading ser




# try:
#     while True:
#         # Read a line of data from the serial port
#         data = ser.readline()
#         # test = data.decode('utf-8').strip()
#         print("Open.")  # Decode bytes to a string and remove whitespace
#
# except KeyboardInterrupt:
#     ser.close()
#     print("Serial connection closed.")






image_data = b''  # Initialize an empty bytes object

while True:
    line = ser.readline().strip()  # Read a line of data and remove leading/trailing whitespace
    if line == b'IMAGE_START':
        image_size = int.from_bytes(ser.read(4), byteorder='big')  # Read the 4-byte image size as a big-endian integer
        image_data = ser.read(image_size)  # Read the image data based on the size
        # Process the received image data here
        print(f"Received image of size {image_size} bytes")
    elif line == b'IMAGE_END':
        # Image transmission is complete; you can process the image data as needed
        # For example, save the image to a file or perform image processing
        with open('received_image.jpg', 'wb') as f:
            f.write(image_data)
        print("Image saved as 'received_image.jpg'")
        image_data = b''  # Reset the image data for the next image

