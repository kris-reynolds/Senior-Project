#include "mbed.h"
#include "Servo.h" 
#include "leg.h"

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
