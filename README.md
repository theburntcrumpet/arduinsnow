# arduinsnow
Make it snow on a 128x64 OLED Display addressed over i2c

This project requires:
  * Adafruit_SSD1306 (https://github.com/adafruit/Adafruit_SSD1306)
  * Adafruit-GFX-Library (https://github.com/adafruit/Adafruit-GFX-Library)

These libraries can be easily installed in the Arduino IDE, simply by going to Sketch -> Include Library -> Add .ZIP Library

This sketch simply displays a snow animation on the OLED Display, which after a set amount of cycles, switches to a flashing "Merry Christmas!" message. 

The display used here was a 0.96 inch 128x64 SSD1306 communicable over i2c, which was found cheaply on eBay. Mine is connected to an Arduino Nano, though I suspect an Uno will produce similar results. 
