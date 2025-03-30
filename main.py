import cv2
import numpy as np
import time


template = cv2.imread('Cherry.png', cv2.IMREAD_GRAYSCALE)

if template is None:
    print("Reference image not found.")
    exit()

camera = cv2.VideoCapture(0)


if not camera.isOpened():
    print("Failed to open USB camera.")
    exit()

template_height, template_width = template.shape

print("Camera is now live. Press 'q' to quit.")

while True:
    ret, frame = camera.read()
    if not ret:
        print("Failed to grab frame.")
        break

    gray_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    result = cv2.matchTemplate(gray_frame, template, cv2.TM_CCOEFF_NORMED)

    threshold = 0.8
    locations = np.where(result >= threshold)

    for pt in zip(*locations[::-1]):
        cv2.rectangle(frame, pt, (pt[0] + template_width, pt[1] + template_height), (0, 255, 0), 2)

    cv2.imshow("Object Detection", frame)

    # Exit if 'q' is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

print("Exiting program.")

camera.release()
cv2.destroyAllWindows()
