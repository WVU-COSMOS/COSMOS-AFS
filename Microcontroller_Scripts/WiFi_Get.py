import requests
import time
from io import BytesIO
from PIL import Image

esp32_ip = "10.0.0.19"
url = f"http://{esp32_ip}/capture"

def get_image():
    try:
        response = requests.get(url)
        if response.status_code == 200:
            return Image.open(BytesIO(response.content))
        else:
            print(f"Failed to fetch image. Status code: {response.status_code}")
    except Exception as e:
        print(f"Error: {e}")

def main():
    while True:
        image = get_image()
        if image:
            image.show()

        time.sleep(1)

if __name__ == "__main__":
    main()
