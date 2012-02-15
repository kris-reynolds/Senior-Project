#include "mbed.h"
#include "BMA180.h"
#include "leg.h"
#include "body.h"
#include "constants.h"


using namespace std;

Serial pc(USBTX, USBRX); // tx, rx

int main() {
    pc.printf("Hello World!\n");
    
    BMA180 accelerometer( p27, p28 );

    // Label the pins for where Servo's attach
    PinName up_left_hip = p21;
    PinName low_left_hip = p22;
    PinName left_knee = p23;
    
    PinName up_right_hip = p24;
    PinName low_right_hip = p25;
    PinName right_knee = p26; 

    // Set up the body
    Leg left_leg( up_left_hip, low_left_hip, left_knee, LEFT );
    Leg right_leg( up_right_hip, low_right_hip, right_knee, RIGHT );
    Body body( left_leg, right_leg );

    // Set the default speed
    body.set_speed( 1 );

    // Calibrate to stand straight at start
    body.calibrate();

    // Infinite while loop after start up
    return 0;
}
