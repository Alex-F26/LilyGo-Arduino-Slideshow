# Picture Slideshow on an ESP32 LilyGo T-display  

The code provided is an implementation of both portrait and landscape photos, choose whichever orientation suits your project best.  

# Image Conversions & Code Integration  

There are multiple ways to get your ESP32 to read and display your images, I chose to convert my images to .c files and pushing them to the screen using the TFT_eSPI.h library in the Arduino IDE.  

Steps to follow:
- Resize your images accordingly (I used the [Microsoft PowerToys](https://apps.microsoft.com/detail/xp89dcgq3k6vld?hl=en-US&gl=US) app)
