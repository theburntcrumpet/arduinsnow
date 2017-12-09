#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Drawable{
  
  protected:
    int xPos;
    int yPos;
    Adafruit_SSD1306 * display;
    
  public:
    int GetX(){return xPos;};
    int GetY(){return yPos;};
    void SetX(int x){xPos = x;};
    void SetY(int y){yPos = y;};
    void SetCoords(int x,int y){xPos = x;yPos = y;};
    Drawable(Adafruit_SSD1306 * pDisplay);
    ~Drawable();
};
