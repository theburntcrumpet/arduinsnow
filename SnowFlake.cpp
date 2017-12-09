#include "SnowFlake.h"

SnowFlake::SnowFlake(Adafruit_SSD1306 * pDisplay):Drawable(pDisplay){
  delay(10);
  xPos = random(1,display->width()-1);
  yPos = 0;
  driftMin = -5;
  driftMax = 4;
  gravityMin = 1;
  gravityMax = 4;
  delay(5);
  gravity = random(gravityMin,gravityMax);
}

SnowFlake::~SnowFlake(){
  
}

void SnowFlake::Draw(){
  display->drawPixel(xPos,yPos,WHITE);
  display->drawPixel(xPos+1,yPos-1,WHITE);
  display->drawPixel(xPos+1,yPos,WHITE);
  display->drawPixel(xPos+1,yPos+1,WHITE);
  display->drawPixel(xPos+2,yPos,WHITE);
}

void SnowFlake::ScrollFlake(){
  yPos += gravity;
  xPos += random(driftMin,driftMax);
  
  if(xPos > display->width())
    xPos -= display->width();
    
  if(xPos < 0)
    xPos += display->width();
    
  if(yPos > display->height()){
    yPos = 0;
    xPos = random(1,display->width()-1);
    gravity = random(gravityMin,gravityMax);
  }
}


