#include <TFT_eSPI.h>
#include <LittleFS.h>

// portraits
#include "imagePT0.h"
#include "imagePT1.h"
#include "imagePT2.h"
#include "imagePT3.h"
#include "imagePT4.h"
#include "imagePT5.h"
#include "imagePT6.h"
#include "imagePT7.h"
#include "imagePT8.h"
#include "imagePT9.h"
#include "imagePT10.h"
#include "imagePT11.h"
#include "imagePT12.h"
#include "imagePT13.h"
#include "imagePT14.h"
#include "imagePT15.h"
#include "imagePT16.h"
#include "imagePT17.h"
#include "imagePT18.h"
#include "imagePT19.h"
#include "imagePT20.h"
#include "imagePT21.h"
#include "imagePT22.h"
#include "imagePT23.h"
#include "imagePT24.h"
#include "imagePT25.h"
#include "imagePT26.h"
#include "imagePT27.h"
#include "imagePT28.h"
#include "imagePT29.h"
#include "imagePT30.h"
#include "imagePT31.h"
#include "imagePT32.h"
#include "imagePT33.h"

// landscapes
#include "imageLS0.h"
#include "imageLS1.h"
#include "imageLS2.h"
#include "imageLS3.h"
#include "imageLS4.h"
#include "imageLS5.h"
#include "imageLS6.h"
#include "imageLS8.h"
#include "imageLS9.h"
#include "imageLS11.h"
#include "imageLS13.h"
#include "imageLS14.h"
#include "imageLS15.h"
#include "imageLS17.h"
#include "imageLS19.h"
#include "imageLS20.h"
#include "imageLS21.h"
#include "imageLS22.h"
#include "imageLS23.h"
#include "imageLS24.h"
#include "imageLS25.h"
#include "imageLS27.h"
#include "imageLS28.h"
#include "imageLS29.h"


// array portrait
const short unsigned int* portrait[] PROGMEM = {
  imagePT0,
  imagePT1,
  imagePT2,
  imagePT3,
  imagePT4,
  imagePT5,
  imagePT6,
  imagePT7,
  imagePT8,
  imagePT9,
  imagePT10,
  imagePT11,
  imagePT12,
  imagePT13,
  imagePT14,
  imagePT15,
  imagePT16,
  imagePT17,
  imagePT18,
  imagePT19,
  imagePT20,
  imagePT21,
  imagePT22,
  imagePT23,
  imagePT24,
  imagePT25,
  imagePT26,
  imagePT27,
  imagePT28,
  imagePT29,
  imagePT30,
  imagePT31,
  imagePT32,
  imagePT33,
  NULL
};

int portraitArrayLength = (sizeof(portrait) / sizeof(portrait[0])) - 1;

// array landscape
const short unsigned int* landscape[] PROGMEM = {
  imageLS0,
  imageLS1,
  imageLS2,
  imageLS3,
  imageLS4,
  imageLS5,
  imageLS6,
  imageLS8,
  imageLS9,
  imageLS11,
  imageLS13,
  imageLS14,
  imageLS15,
  imageLS17,
  imageLS19,
  imageLS20,
  imageLS21,
  imageLS22,
  imageLS23,
  imageLS24,
  imageLS25,
  imageLS27,
  imageLS28,
  imageLS29,
  NULL
};

int landscapeArrayLength = (sizeof(landscape) / sizeof(landscape[0])) - 1;

// pins
const int leftPin = 25;
const int rightPin = 21;

// loops
int i = 0;
int portraitLoopInt = 0;
int landscapeLoopInt = 1;

unsigned long lastImageTime = 0;
const unsigned long interval = 5000;

bool prime = false;

// object to push images to
TFT_eSPI tft = TFT_eSPI();


void setup() {
  Serial.begin(115200);

  pinMode(leftPin, INPUT_PULLUP);
  pinMode(rightPin, INPUT_PULLUP);

  tft.init();

  tft.setSwapBytes(true); 

}

void loop() { 

  checkButton();

  if (millis() - lastImageTime >= interval || !prime){
    prime = true;
  
  // Portrait
    if (portraitLoopInt == 0){

      int portraitReturn = loopPortrait(i);

      if (portraitReturn == 1){
        portraitLoopInt = 1;
        landscapeLoopInt = 0;
        i = 0;
        return;
      }

      else{
        i++;
        return;
      }
    }
  
  // Landscape
    if (landscapeLoopInt == 0){

      int landscapeReturn = loopLandscape(i);

      if (landscapeReturn == 1){
        portraitLoopInt = 0;
        landscapeLoopInt = 1;
        i = 0;
        return;
      }

      else{
        i++;
        return;
      }
    }
  }
}

void checkButton(){
  bool pressed = false;

    if (digitalRead(leftPin) == LOW){
      while(!pressed){
        pressed = true;
        delay(150);
        Serial.println("LEFT PRESS");
        i--;
        if (portraitLoopInt == 0){
          if(i < 0){
            i = landscapeArrayLength;
            portraitLoopInt = 1;
            landscapeLoopInt = 0;
            loopLandscape(i);
          }
          else{
            loopPortrait(i);
          }
        }

        if (landscapeLoopInt == 0){
          if(i < 0){
            i = portraitArrayLength;
            portraitLoopInt = 0;
            landscapeLoopInt = 1;
            loopPortrait(i);
          }
          else{
            loopLandscape(i);
          }
        }
      }
      return;
    }

    if (digitalRead(rightPin) == LOW){
      while(!pressed){
        pressed = true;
        delay(150);
        Serial.println("RIGHT PRESS");
        i++;
        if (portraitLoopInt == 0){
          if(i > portraitArrayLength){
            i = 0;
            portraitLoopInt = 1;
            landscapeLoopInt = 0;
            loopLandscape(i);
          }
          else{
            loopPortrait(i);
          }
        }

        if (landscapeLoopInt == 0){
          if(i > landscapeArrayLength){
            i = 0;
            portraitLoopInt = 0;
            landscapeLoopInt = 1;
            loopPortrait(i);
          }
          else{
            loopLandscape(i);
          }
        }
      }
      return;
    }
}


// Portrait
int loopPortrait(int i){

  lastImageTime = millis();
  tft.setRotation(0);

  Serial.println("condition met P");

  const short unsigned int* currentImage = portrait[i];

  if (currentImage != NULL){

    tft.fillScreen(TFT_BLACK); // clear previous photo
    tft.pushImage(0, 0, 135, 180, currentImage);

    return 0;
  }
  else{
    return 1;
  }
}


// Landscape
int loopLandscape(int i){

  lastImageTime = millis();
  tft.setRotation(1);

  Serial.println("condition met L");

  const short unsigned int* currentImage = landscape[i];

  if (currentImage != NULL){

    tft.fillScreen(TFT_BLACK); // clear previous photo
    tft.pushImage(0, 0, 180, 135, currentImage);

    // delay(3000);
    return 0;
  }
  else{
    return 1;
  }
}