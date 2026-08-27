# Picture Slideshow on an ESP32 LilyGo T-display  

The code provided is an implementation of both portrait and landscape photos, choose whichever orientation suits your project best.   

# Library Dependencies
There are multiple ways to get your ESP32 to read and display your images, I chose to convert my images to .c files and pushing them to the screen using the TFT_eSPI.h library in the Arduino IDE.
- To install this, open your Arduino IDE and go to the Library Manager (It looks like four vertical books on the left side)
- Type in TFT_eSPI and download the one by Bodmer

# Create Your Own Slideshow - Tutorial #  
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

# Code adjustments
As stated above, some minor adjustments may need to take place in order for your program to work, nothing too crazy, I promise!  
- Below are some simple if-statements with instructions, I figure this format is fitting since if-statements are part of our nature as coders.
  
**If you changed your PORTRAIT image file names differently**  
- After line 4 (portraits) of the code, rename the files in quotes to whatever your file names are.
  - e.g if your filename is imagePortrait0.h, change the line that says *#include "imagePT0.h"* to *#include "imagePortrait0.h"*
- After line 20 (array portrait) of the code, rename the files in the list to whatever your file names are.
  - e.g if your filename is imagePortrait0.h, change the line that says *imagePT0,* to *imagePortrait0,*
  
**If you changed your LANDSCAPE image file names differently**  
- After line 11 (landscapes) of the code, rename the files in quotes to whatever your file names are.
  - e.g if your filename is imageLandscape0.h, change the line that says *#include "imageLS0.h"* to *#include "imageLandscape0.h"*
- After line 31 (array landscape) of the code, rename the files in the list to whatever your file names are.
  - e.g if your filename is imageLandscape0.h, change the line that says *imageLS0,* to *imageLandscape0,*
  
**If your have more or less image files**
- If your have less portrait/landscape pictures than from what I have in the code, follow the instructions above and simply delete any files from the *#include ...* lists and from the arrays (array landscape/array portrait) RESPECTIVELY.
- If your have more portrait/landscape pictures than from what I have in the code, follow the instructions above and simply add any files to the *#include ...* lists and to the arrays (array landscape/array portrait) RESPECTIVELY.
  
**If you resized your images differently**
- If you resized your PORTRAIT images differently, go down to the *int loopPortrait(int i)* function and change the numbers 135, and 180 in *tft.pushImage(0, 0, 135, 180, currentImage);* to whatever your sizes are.
  - e.g if your image size is 100x120, the code should look like *tft.pushImage(0, 0, 100, 120, currentImage);*
- If you resized your LANDSCAPE images differently, go down to the *int loopLandscape(int i)* function and change the numbers 135, and 180 in *tft.pushImage(0, 0, 135, 180, currentImage);* to whatever your sizes are.
  - e.g if your image size is 120x100, the code should look like *tft.pushImage(0, 0, 120, 100, currentImage);*
  - e.g if your image size is 200x150, the code should look like *tft.pushImage(0, 0, 200, 150, currentImage);*

# Change the TIMER
***WARNING**: If flashing images are an issue for you, I recommend keeping the value to no less than 5000, otherwise you will have images cycling like crazy on the display.*  
If you'd like to shorten or extend the amount time that each image is displayed for, simply go to the line that says *const unsigned long interval = 5000;* and change the 5000 to whatever you'd like
  - Note that 5000 is roughly equal to 5 seconds, so every 1000 is about a second.
  - e.g 10,000 is roughly equal to 10 seconds

# Adding Buttons (OPTIONAL)
Notice! - Buttons are not needed as the program will cycle through your images every 5000 seconds (more or less depending on your changes)  
This project was made to fit inside a Kingdom Hearts - Pink Agaricus, so I needed it to have buttons that extended out. The buttons on the board itself were too restrictive in terms of space.
- If you'd like to add your own wires for buttons to traverse through the pictures, I used pins 25(Left Button) and 21(Right Button) and the bottom and top Ground labeled G on the left side of the board for the buttons.  
<img width="788" height="733" alt="image" src="https://github.com/user-attachments/assets/0e6a45bb-3e58-482c-a0c3-4c6b3580cade" />

**Soldering**  
***WARNING** Solder with caution and follow the steps closely, if you are not confident in doing this, I suggest looking into tutorials beforehand to avoid damaging your board.*  
- For the Left Button (To go to the next image):
  - I soldered the end of one wire to pin 25 and the other end of the wire to one side of the button.
  - I soldered a DIFFERENT wire to the bottom G pin and the other end of the wire to the other side of the button that has not been used.
 
- For the Right Button (To go to the previous image):
  - I soldered the end of one wire to pin 21 and the other end of the wire to one side of the button.
  - I soldered a DIFFERENT wire to the top G pin and the other end of the wire to the other side of the button that was not used.

# Battery Type
If you'd like to have your T-display be portable and not have to leave it plugged in to your pc for it to work, below is the battery I used.
- 3.7 V LiPo battery (230 mAh) with a JST connector that plugs into the back of the LilyGo board
- The connector on the board for the battery is displayed below:
<img width="426" height="321" alt="Screenshot 2026-08-26 214645" src="https://github.com/user-attachments/assets/8aff3d40-26cb-4974-8f70-45a8f1a23e43" />


You should now have a fully functioning mini slideshow display with buttons to sift through your pictures!
