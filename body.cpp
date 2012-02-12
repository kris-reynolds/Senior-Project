#include "mbed.h"
#include "Servo.h" 
#include "leg.h"
#include "constants.h"

/* 
 * Constructor takes two legs
 */
Body::Body( Leg left_leg, Leg right_leg ) {
	this.left_leg = left_leg;
	this.right_leg = right_leg;
};

/* 
 * Change the mode to forward/backward 
 */
void Body::set_mode( int mode ){ 
	this.mode = mode;
}


/* 
 * Set speed of movement 
 */
void Body::set_speed( int speed ) {
	this.speed = mode;
}

/* 
 * Move forward
 * Use threads to move both legs at once
 */
void Body::move_forward() {
	int direction = FORWARD;

	// Determine leading leg: the hip positon that is 
	// furthest forward is leading, bring trailing
	// forward first

	// Bring leading leg forward
	for( float pos = 0.5; pos < 0.75; pos+=0.05 ) {
		this.left_leg.move_front( direction, pos ); 
		this.right_leg.move_back( direction, pos );
		wait( 1 );
	}
	// Bring trailing leg forward 
	for( float pos = 0.5; pos > 0.25; pos-=0.05 ) {
		this.right_leg.move_front( direction, pos );
		this.left_leg.move_back( direction, pos );
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
