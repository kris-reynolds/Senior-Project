#include "leg.h"
#include "Servo.h"
#include "constants.h"



/*
 * Construct a leg with direction
 */
Leg::Leg(PinName upper_hip, PinName lower_hip, PinName knee, int leg_side) {
    Servo up_hip_servo( upper_hip );
    Servo low_hip_servo( lower_hip );
    Servo knee_servo( knee );
    
    SIDE = leg_side;
    calibrate( 0.5 );
}

Leg::Leg(){
    SIDE = LEFT;
    Servo up_hip_servo( p21 );
    Servo low_hip_servo( p22 );
    Servo knee_servo( p23 );
}


/*
 * Return all servos to center, power up/power down or fall 
 * Subject to change after experimentation
 */
void Leg::calibrate( int pos ) {
    up_hip_servo = pos;
    low_hip_servo = pos;
    knee_servo = pos;
}

/*
 * Move the Leg in the specified direction
 * Leading LEG
 * Take into account speed and size of step
 */
void Leg::move_front( int direction, int size ){
    // Adjustment for natural movement
    int adjust_hip  = 0;
    int adjust_knee = 0;

    // Take in direction and speed
    low_hip_servo   = low_hip_servo.read() - direction * size + adjust_hip;
    knee_servo      = knee_servo.read() + direction * size + adjust_knee;

    // No delays done here, just step    
    // Figure out angle of movement depending on speed, and stride size
    // Return on end of movement
}

/*
 * Move the Leg in the specified direction
 * Trailing Leg 
 * Take into account speed and size of step
 */
void Leg::move_back( int direction, int size ){
    // Adjustment for natural movement
    int adjust_hip  = 0;
    int adjust_knee = 0;

    // Take in direction and speed
    low_hip_servo   = low_hip_servo.read() + direction * size + adjust_hip;
    knee_servo      = knee_servo.read() - direction * size + adjust_knee;

    // No delays done here just step servo
    // Figure out angle of movement depending on speed, and stride size
    // Return on end of movement
}

float Leg::get_position( void ) {
    return low_hip_servo;
}
