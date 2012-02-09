#include "mbed.h"
#include "Servo.h" 
#include "leg.h"

class body {
 public:
    leg left_leg;
    leg right_leg
    void set_mode(); 
    void set_speed();
    void move_forward();
    void move_backward();
    void turn_left();
    void turn_right();
  
 private:
    int mode;
    int speed;

};
