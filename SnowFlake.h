#include "Drawable.h"

class SnowFlake : Drawable{
  protected:
    int gravity;
    int driftMin;
    int driftMax;
    int gravityMin;
    int gravityMax;
    
  public:
    void Draw();
    void ScrollFlake();
    SnowFlake(Adafruit_SSD1306 * pDisplay);
    ~SnowFlake();
};
