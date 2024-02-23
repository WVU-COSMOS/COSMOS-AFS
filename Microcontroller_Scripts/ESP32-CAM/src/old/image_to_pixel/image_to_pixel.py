import cv2
import numpy as np
import matplotlib.pyplot as plt

# Load the image
RGB = cv2.imread('Dots.jpg')

# Split the channels
B = RGB[:, :, 0]
G = RGB[:, :, 1]
R = RGB[:, :, 2]

# Process the image
for i in range(RGB.shape[0]):
    for j in range(RGB.shape[1]):
        if R[i, j] > 150 and G[i, j] < 50 and B[i, j] < 50:
            R[i, j] = 255
            G[i, j] = 255
            B[i, j] = 255
        else:
            R[i, j] = 0
            G[i, j] = 0
            B[i, j] = 0

# Create a new RGB image
RGB_new = np.zeros_like(RGB)
RGB_new[:, :, 0] = B
RGB_new[:, :, 1] = G
RGB_new[:, :, 2] = R

# Convert to grayscale
I = cv2.cvtColor(RGB_new, cv2.COLOR_BGR2GRAY)

# Threshold the image to create a binary mask for the white part
_, binary_mask = cv2.threshold(I, 200, 255, cv2.THRESH_BINARY)

# Find contours in the binary mask
contours, _ = cv2.findContours(binary_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Check if contours are found
if contours:
    # Find the largest contour (assuming it corresponds to the object of interest)
    largest_contour = max(contours, key=cv2.contourArea)

    # Calculate the center of mass (centroid) of the largest contour
    M = cv2.moments(largest_contour)
    cx = int(M['m10'] / M['m00'])
    cy = int(M['m01'] / M['m00'])

    print(f"Center of the white object: ({cx}, {cy})")

    # Draw a circle at the center
    cv2.circle(RGB_new, (cx, cy), 25, (0, 255, 0), -1)

    # Display the result
    plt.imshow(cv2.cvtColor(RGB_new, cv2.COLOR_BGR2RGB))
    plt.title('Processed Image with Center of White Object')
    plt.show()
else:
    print("No contours found.")