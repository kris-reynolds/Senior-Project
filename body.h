#pragma once
#include "mbed.h"
#include "leg.h"
#include "constants.h"

class Body {
 public:
    Leg left_leg;
    Leg right_leg;
    
    Body( Leg left_leg, Leg right_leg );
    Body();
    void set_mode(); 
    void set_speed( int tspeed );
    void move_forward();
    void move_backward();
    void turn( int direction );
    void calibrate();

 private:
    int speed;

};
