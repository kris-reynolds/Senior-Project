#include "mbed.h"
#include "Servo.h" 
#include "leg.h"

class Body {
 public:
    Leg left_leg;
    Leg right_leg;
    Body( Leg left_leg, Leg right_leg );
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
