/*
 * Class for robot legs
 * Functions for intializing
 * Calibrating
 * Movement (forward, backward, speed)
 * Thank you Kelly for variable names
 */

#ifndef LEG_H
#include "mbed.h"
#include "Servo.h" 

class Leg {
 public:
    Leg(PinName upper_hip, PinName lower_hip, PinName knee, int side);

    void move( int direction, int speed );
     
    void calibrate();
    int SIDE;
     
  
 private:
     int init();
	void set_mode();
	Servo up_hip_servo;
	Servo low_hip_servo;
	Servo knee_servo;

	float up_hip_pos;
	float low_hip_pos;
	float knee_pos;
	int mode;
};
 
#endif
