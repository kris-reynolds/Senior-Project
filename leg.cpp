/*
 * Kelly
 */


#include "mbed.h"
#include "Servo.h"
 
/*
 * Construct a leg with direction
 */
leg::leg(PinName upper_hip, PinName lower_hip, PinName knee, int leg_side) {
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
leg::calibrate() {
	up_hip_servo = 0.5;
	low_hip_servo = 0.5;
	knee_servo = 0.5;
}

leg::move( int direction, int speed, int size ){
	// Take in direction and speed
	// Figure out angle of movement depending on speed, and stride size
	// Move all 3 motors together...threads?
	// Return on end of movement
}
