#include "mbed.h"
#include "Servo.h" 
#include "leg.h"

class body {
 public:
    leg left_leg;
    leg right_leg
    void set_mode(); 
    void set_speed();
  
 private:
    int mode;
    int speed;

};
