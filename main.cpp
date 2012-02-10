#include <iostream>
#include "BMA180.h"
#include "leg.h"
#include "body.h"
#include "constants.h"

using namespace std;

int main() {
	BMA180 accelerometer = new BMA180( /*pin1, pin2 */);

	// Label the pins for where Servo's attach
	PinName up_left_hip = p21;
	PinName low_left_hip = p22;
	PinName left_knee = p23;
	
	PinName up_right_hip = p24;
	PinName low_right_hip = p25;
	PinName right_knee = p26; 

	Leg left_leg = new Leg( up_left_hip, low_left_hip, left_knee, LEFT );
	Leg right_leg = new Leg( up_right_hip, low_right_hip, right_knee, RIGHT );
	Body body = new Body( left_leg, right_leg );


	while(1) {

	}

return 0;
}
