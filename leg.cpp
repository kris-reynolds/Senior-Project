#include "leg.h"
#include "Servo.h"
#include "constants.h"

/*
 * Construct a leg with direction
 */
Leg::Leg(PinName upper_hip, PinName lower_hip, PinName knee, int leg_side) {
    // Create new servo's at the specified places
    Servo *hip1  = new Servo( upper_hip, leg_side );
    Servo *hip2  = new Servo( lower_hip, leg_side );
    Servo *_knee = new Servo( knee, leg_side );

    // Assign the motors to pointers
    up_hip_servo  = hip1;
    low_hip_servo = hip2;
    knee_servo    = _knee;

    SIDE = leg_side;
}

Leg::Leg() {
    SIDE = LEFT;
}

/*
 * Return all servos to center, power up/power down or fall
 * Subject to change after experimentation
 */
void Leg::calibrate(  ) {
    // Calibrate the legs again to meet the new spec
    // Consider a new foot design to help with forward/back issues
    *up_hip_servo = 0.5;
    *low_hip_servo = 0.50;
    *knee_servo = 0.38;

}

/*
 * Move the Leg in the specified direction
 * Leading LEG
 * Take into account speed and size of step
 */
void Leg::move_front( int direction, float increment ) {
    // Adjustment for natural movement
    float adjust_hip  = 1.0;
    float adjust_knee = 1.0;
    float increment_knee = increment;
    float increment_hip = increment;

    Serial pc(USBTX, USBRX); // tx, rx
    // On the left  leg 0-0.5 is front of body
    float curr_position = get_position();

    // When leg gets all the way back bend the knee
    if ( fabs( curr_position - 0.80 ) < 0.03 ) {
        *knee_servo      = 0;
    }
    // after it passes halfway straighten the knee gradually
    else if ( curr_position > increment && 0.4 > increment ) {
        *knee_servo = 0.85 - increment;
    }

    *low_hip_servo   = increment_hip  * direction;

    // When a leg is headed backward lean that way
    if (  curr_position < increment )
        *up_hip_servo = 0.6;
    else
        *up_hip_servo = 0.45;

    // Take in direction and speed
    //low_hip_servo   = low_hip_servo.read() + direction * size + adjust_hip;
    //knee_servo      = knee_servo.read() - direction * size + adjust_knee;

    // No delays done here, just step
    // Figure out angle of movement depending on speed, and stride size
    // Return on end of movement
}

/*
 * Move the Leg in the specified direction
 * Trailing Leg
 * Take into account speed and size of step
 */
void Leg::move_back( int direction, float increment ) {
    // Adjustment for natural movement
    int adjust_hip  = 1.0;
    int adjust_knee = 1.5;
    float curr_position = get_position();

    // Moving leg forwards (majority of cases)
    if (  curr_position > increment  ) {
        // When bringing back knee stays fairly straight
        *low_hip_servo   = direction * increment * adjust_hip;
        *knee_servo      = direction * increment * adjust_knee;
    }
    // Moving leg backwards (starting out)
    else if ( curr_position <= increment ) {
        // When moving forward bring knee much higher
    }

    // No delays done here just step servo
    // Figure out angle of movement depending on speed, and stride size
    // Return on end of movement
}

float Leg::get_position( void ) {
    return *low_hip_servo;
}
