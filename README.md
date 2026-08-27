# Picture Slideshow on an ESP32 LilyGo T-display  

The code provided is an implementation of both portrait and landscape photos, choose whichever orientation suits your project best.  

# Image Conversions & Code Integration  

There are multiple ways to get your ESP32 to read and display your images, I chose to convert my images to .c files and pushing them to the screen using the TFT_eSPI.h library in the Arduino IDE.  

Steps to follow:
- Resize your images accordingly. I used the [Microsoft PowerToys](https://apps.microsoft.com/detail/xp89dcgq3k6vld?hl=en-US&gl=US) app and resized my portrait images to 135x180 and landscapes to 180x135.
- Convert to .c files. Make your way to the [Rinky Dink Electronics website](http://www.rinkydinkelectronics.com/t_imageconverter565.php) and upload your resized image.
<img width="740" height="544" alt="Screenshot 2026-08-26 203819" src="https://github.com/user-attachments/assets/37130011-5d7d-43f6-8fa1-85e090d85f5c" />

