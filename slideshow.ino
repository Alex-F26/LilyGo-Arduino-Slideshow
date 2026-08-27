#include <TFT_eSPI.h>
#include <LittleFS.h>

// portraits
#include "imagePT0.h"
#include "imagePT1.h"
#include "imagePT2.h"
#include "imagePT3.h"


// landscapes
#include "imageLS0.h"
#include "imageLS1.h"
#include "imageLS2.h"
#include "imageLS3.h"



// array portrait
const short unsigned int* portrait[] PROGMEM = {
  imagePT0,
  imagePT1,
  imagePT2,
  imagePT3,
  NULL
};

int portraitArrayLength = (sizeof(portrait) / sizeof(portrait[0])) - 1;

// array landscape
const short unsigned int* landscape[] PROGMEM = {
  imageLS0,
  imageLS1,
  imageLS2,
  imageLS3,
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
