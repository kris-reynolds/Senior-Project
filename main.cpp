#include "mbed.h"
#include "Servo.h"
#include "BMA180.h"
#include "leg.h"
#include "body.h"
#include "constants.h"


using namespace std;

Serial pc(USBTX, USBRX); // tx, rx

int main() {
    pc.printf("Hello World!\n");

   // BMA180 accelerometer( p27, p28 );

    // Label the pins for where Servo's attach
    PinName up_left_hip = p21;
    PinName low_left_hip = p22;
    PinName left_knee = p23;

    PinName up_right_hip = p24;
    PinName low_right_hip = p25;
    PinName right_knee = p26;

    // Set up the body
    /*
    Leg left_leg( up_left_hip, low_left_hip, left_knee, LEFT );
    Leg right_leg( up_right_hip, low_right_hip, right_knee, RIGHT );
    Body body( left_leg, right_leg );

    // Set the default speed
    //body.set_speed( 1 );

    // Calibrate to stand straight at start
    //body.calibrate();
    
    // On the left leg 0-0.5 is front of body
    // On the right leg 0-0.5 is back of body
    */
    Leg left_leg( up_left_hip, low_left_hip, left_knee, LEFT );
    Leg right_leg( up_right_hip, low_right_hip, right_knee, RIGHT );

    left_leg.calibrate();
    right_leg.calibrate( );
    wait( 1 );

   //pc.printf( "up_hip:\t%f\nlow_hip:\t%f\nknee:\t%f\n", up_hip_servo.read(), low_hip_servo.read(), knee_servo.read() );

    while( 1 ) {
        for( float p = 0.2; p < 0.8; p+=0.02 ) {
            left_leg.move_front( FORWARD, p );
            right_leg.move_front( FORWARD, p );
            wait( 0.02 );
        }
        
        for( float p = 0.8; p > 0.2; p-=0.02 ) {
            left_leg.move_front( FORWARD, p );
            right_leg.move_front( FORWARD, p );
            wait( 0.02 );
        }
    }
}

