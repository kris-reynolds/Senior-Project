#include "mbed.h"
#include "Servo.h"
 
/*
 * Construct a leg with direction
 */
Leg::Leg(PinName upper_hip, PinName lower_hip, PinName knee, int leg_side) {
	up_hip_servo( upper_hip );
	low_hip_servo( lower_hip );
	knee_servo( lower_hip );
	
	SIDE = leg_side;
	calibrate();
	
}

/*
 * Return all servos to center, power up/power down or fall 
 * Subject to change after experimentation
 */
Leg::calibrate() {
	up_hip_servo = 0.5;
	low_hip_servo = 0.5;
	knee_servo = 0.5;
}

/*
 * Move the Leg in the specified direction
 * Leading LEG
 * Take into account speed and size of step
 */
Leg::move_front( int direction, int speed, int size ){
	// Take in direction and speed
	
	// Figure out angle of movement depending on speed, and stride size
	// Move all 3 motors together...threads?
	// Return on end of movement
}

/*
 * Move the Leg in the specified direction
 * Trailing Leg 
 * Take into account speed and size of step
 */
Leg::move_back( int direction, int speed, int size ){
	// Take in direction and speed
	// Figure out angle of movement depending on speed, and stride size
	// Move all 3 motors together...threads?
	// Return on end of movement
}

/*
 * Set the current mode (based off body)
 */
Leg::set_mode( int mode ) {
	this.mode = mode; 
}
