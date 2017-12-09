#include <SPI.h>
#include <Wire.h>
#include "SnowFlake.h"

#define OLED_RESET 4
#define SNOWFLAKES 20

Adafruit_SSD1306 * pDisplay = new Adafruit_SSD1306(OLED_RESET);

SnowFlake * flakes[SNOWFLAKES];

int cycles = 0;
bool invert = false;
void CreateFlakes(){
    for(int i=0;i<SNOWFLAKES;i++){
      flakes[i] = new SnowFlake(pDisplay);
    }
}

void setup() {
  Serial.begin(9600);
  pDisplay->begin(SSD1306_SWITCHCAPVCC, 0x3C);
  CreateFlakes();
  pDisplay->clearDisplay();
  pDisplay->display();
}

void Snow(){
  pDisplay->invertDisplay(false);
  for(int i = 0; i < SNOWFLAKES; i++){
    flakes[i]->ScrollFlake();
    flakes[i]->Draw();
    delay(5);  
  }
  pDisplay->display();
  pDisplay->clearDisplay();
}

void MerryChristmas(){
  pDisplay->setTextSize(2);
  pDisplay->setTextColor(WHITE);
  pDisplay->setCursor(10,0);
  pDisplay->println("Merry\nChristmas!");
  pDisplay->invertDisplay(invert);
  if(cycles % 5 == 0 && cycles % 2 != 0)
    invert = !invert;
  pDisplay->display();
  pDisplay->clearDisplay();
}

void loop() {
  if(cycles < 100)
    Snow();
  
  if(cycles >= 100)
    MerryChristmas();      

  if(cycles > 250)
     cycles = 0;
  
  cycles++;
}
