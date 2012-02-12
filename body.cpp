#include "mbed.h"
#include "Servo.h" 
#include "leg.h"
#include "constants.h"

extern int g_mode;
/* 
 * Constructor takes two legs
 */
Body::Body( Leg left_leg, Leg right_leg ) {
	this.left_leg = left_leg;
	this.right_leg = right_leg;
};

// Carefully bring all body parts to center
Body::calibrate() {
	::g_mode = CALIBRATION_MODE;

	int pos_left = this.left_leg.postion();
	int pos_right = this.right_leg.postion();

	// Keep calibrating until reach center
	while( 0.5 != this.left_leg.position() && 0.5 != this.right_leg.position() ) {
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
		elseif( 0.5 > pos_left ) 
			pos_left += 0.1;

		if( 0.5 > pos_right ) 
			pos_right -= 0.1;
		elseif( 0.5 < pos_right ) 
			pos_right += 0.1;
		
		// Write the new position
		this.left_leg.calibrate( pos_left );
		this.right_leg.calibrate( pos_right );

		// Wait for movement to finish
		wait( 1 );
	}
}

/* 
 * Set speed of movement 
 */
void Body::set_speed( int speed ) {
	this.speed = speed;
}

/* 
 * Move forward
 */
void Body::move_forward() {
	// determine leading leg: the hip positon that is 
	// furthest forward is leading, bring trailing
	// forward first
	int forward_leg;
	float forward_leg_position;
	float rear_leg_position;
	float target_position;
	float postion_increment;

	if ( this.left_leg.position() >= this.right_leg.postion() ) {
		forward_leg = left;
		forward_leg_position = this.left_leg.position();
		rear_leg_position = this.right_leg.position();
		position_increment = -0.05
	}
	else {
		forward_leg = right;
		forward_leg_position = this.right_leg.position();
		rear_leg_position = this.left_leg.position();
		position_increment = 0.05
	}

	
	// Start walking from the current position
	for( float pos = forward_leg_postion; 0.75 > pos && 0.25 < pos; pos+=position_increment ) {
		// Bring trailing leg forward first
		if( RIGHT == forward_leg ) {
			this.left_leg.move_front( direction, pos ); 
			this.right_leg.move_back( direction, pos );
		}
		// Only move the other leg if not in calibration mode
		else {
			this.right_leg.move_front( direction, pos ); 
			this.left_leg.move_back( direction, pos );
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
