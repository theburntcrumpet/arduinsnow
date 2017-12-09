#include "Drawable.h"

Drawable::Drawable(Adafruit_SSD1306 * pDisplay){
  display =  pDisplay;
}

Drawable::~Drawable(){
}
