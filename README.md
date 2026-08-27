# Picture Slideshow on an ESP32 LilyGo T-display  

The code provided is an implementation of both portrait and landscape photos, choose whichever orientation suits your project best.  

# Image Conversions & Code Integration  

There are multiple ways to get your ESP32 to read and display your images, I chose to convert my images to .c files and pushing them to the screen using the TFT_eSPI.h library in the Arduino IDE.  

**Create Your Own Slideshow**  
- Resize your images accordingly.
  - I used the [Microsoft PowerToys](https://apps.microsoft.com/detail/xp89dcgq3k6vld?hl=en-US&gl=US) app and resized my portrait images to 135x180 and landscapes to 180x135.
- Convert to .c files.
  - Make your way to the [Rinky Dink Electronics website](http://www.rinkydinkelectronics.com/t_imageconverter565.php) and upload your resized image.
<img width="740" height="544" alt="Screenshot 2026-08-26 203819" src="https://github.com/user-attachments/assets/37130011-5d7d-43f6-8fa1-85e090d85f5c" />
  
- Click on Make File and download it when available.
  - You may get a warning like the one shown below, proceed by clicking on 'Keep'. An example of what the file should look like is provided: [LilyGo.h](https://github.com/Alex-F26/LilyGo-Arduino-Slideshow/blob/main/LilyGo.h)
<img width="307" height="63" alt="Screenshot 2026-08-26 204016" src="https://github.com/user-attachments/assets/c5e1d8c1-6c78-4cab-b4b2-0c77421edf22" />
  
- Change your file extension from imageName.c to imageName.h to allow the program to compile it.
  - You may change the extension from your IDE by renaming the file or in File explorer by going to 'View' -> Show -> File name extensions and change them there.
- Configure your directory files. Once your have all of your images downloaded and extensions changed, I recommend changing all of their names to something easy to sort through. For my portrait images I renamed them all to imagePT0, imagePT1... and so on.
- **DON'T PANIC** -> You can change them in bulk by using a command in your terminal.
  - First, place all your portrait or landscape images in their own isolated folder
  - Then, go into that folder and right-click on an empty space inside the folder. Click on 'Open in Terminal'.
  - Run the following command: $i=0; Get-ChildItem | ForEach-Object { Rename-Item $_ -NewName "imagePT$i$($_.Extension)"; $i++}
  - *You can change the imagePT part to whatever name you want, the command will handle the numbering from 0 to n*
- Once all this is done, move all of your image.h files directly into the same directory as your slideshow.ino program file. No subfolder or anything required.
- Now depending on what you named your files and how many you added, you may need to change the code slightly.

# Code adjustments and Logic Explanation

