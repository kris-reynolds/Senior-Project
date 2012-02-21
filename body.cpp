#include "mbed.h"
#include "body.h"
#include "constants.h"

/* 
 * Constructor takes two legs
 */
Body::Body( Leg tleft_leg, Leg tright_leg ) {
    left_leg = tleft_leg;
    right_leg = tright_leg;
};

Body::Body() {
    Leg left_leg( p21, p22, p23, LEFT );
    Leg right_leg( p24, p25, p26, RIGHT );
}

// Carefully bring all body parts to center
void Body::calibrate() {
   // ::g_mode = CALIBRATION_MODE;

    int pos_left = left_leg.get_position();
    int pos_right = right_leg.get_position();

    // Keep calibrating until reach center
    while( 0.5 != left_leg.get_position() && 0.5 != right_leg.get_position() ) {
        // If they are extremely close, just set to an exact
        // point that will get set to middle
        if ( 0.6 > pos_left && 0.4 < pos_left ) {
            pos_left = 0.6;
        }
        if ( 0.6 > pos_right && 0.4 < pos_right ) {
            pos_left = 0.6;
        }

        // Bring closer to center
        if( 0.5 < pos_left ) 
            pos_left -= 0.1;
        else if( 0.5 > pos_left ) 
            pos_left += 0.1;

        if( 0.5 > pos_right ) 
            pos_right -= 0.1;
        else if( 0.5 < pos_right ) 
            pos_right += 0.1;
        
        // Write the new position
        left_leg.calibrate(  );
        right_leg.calibrate(  );

        // Wait for movement to finish
        wait( 1 );
    }
}

/* 
 * Set speed of movement 
 */
void Body::set_speed( int tspeed ) {
    speed = tspeed;
}

/* 
 * Move forward
 */
void Body::move_forward() {
    // determine leading leg: the hip positon that is 
    // furthest forward is leading, bring trailing
    // forward first
    int direction = FORWARD;
    int forward_leg;
    float forward_leg_position;
    float rear_leg_position;
    //float target_position;
    float position_increment;

    if ( left_leg.get_position() >= right_leg.get_position() ) {
        forward_leg = LEFT;
        forward_leg_position = left_leg.get_position();
        rear_leg_position = right_leg.get_position();
        position_increment = -0.05;
    }
    else {
        forward_leg = RIGHT;
        forward_leg_position = right_leg.get_position();
        rear_leg_position = left_leg.get_position();
        position_increment = 0.05;
    }

    
    // Start walking from the current position
    for( float pos = forward_leg_position; 0.75 > pos && 0.25 < pos; pos+=position_increment ) {
        // Bring trailing leg forward first
        if( RIGHT == forward_leg ) {
            left_leg.move_front( direction, pos ); 
            right_leg.move_back( direction, pos );
        }
        // Only move the other leg if not in calibration mode
        else {
            right_leg.move_front( direction, pos ); 
            left_leg.move_back( direction, pos );
        }
        wait( 1 );
    }
}

/* 
 * Move backward
 * Use threads to move both legs at once
 */
void Body::move_backward() {
}

/* 
 * Turn left or right
 * Move one leg more/less then other
 */
void Body::turn( int direction ) {
}
