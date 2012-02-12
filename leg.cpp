#include "mbed.h"
#include "Servo.h"
#include "constants.h"

extern int g_mode;

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
Leg::calibrate( int pos ) {
	this.up_hip_servo = pos;
	this.low_hip_servo = pos;
	this.knee_servo = pos;
}

/*
 * Move the Leg in the specified direction
 * Leading LEG
 * Take into account speed and size of step
 */
Leg::move_front( int direction, int size ){
	// Adjustment for natural movement
	int adjust_hip  = 0;
	int adjust_knee = 0;

	// Take in direction and speed
	lower_hip -= direction * size + adjust_hip;
	knee      += direction * size + adjust_knee;

	// No delays done here, just step	
	// Figure out angle of movement depending on speed, and stride size
	// Return on end of movement
	return;
}

/*
 * Move the Leg in the specified direction
 * Trailing Leg 
 * Take into account speed and size of step
 */
Leg::move_back( int direction, int size ){
	// Adjustment for natural movement
	int adjust_hip  = 0;
	int adjust_knee = 0;

	// Take in direction and speed
	lower_hip += direction * size + adjust_hip;
	knee      -= direction * size + adjust_knee;

	// No delays done here just step servo
	// Figure out angle of movement depending on speed, and stride size
	// Move all 3 motors together...threads?
	// Return on end of movement
}

int Leg::get_position( void ) {
	return lower_hip;
}
