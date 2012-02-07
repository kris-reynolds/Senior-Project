

#include <Servo.h>

Servo left_hip;
Servo right_hip;

int left_hip_pos = left_hip.read();
int right_hip_pos = right_hip.read();

void setup() {
	left_hip.attach(9);
	right_hip.attach(10);
}

void loop() {
	for( left_hip_pos = left_hip_pos; left_hip_pos < 120; left_hip_pos++, right_hip_pos-- ) {
		left_hip.write(left_hip_pos);
		right_hip.write(right_hip_pos);
	}

	for( left_hip_pos = right_hip_pos; left_hip_pos > 90; left_hip_pos--, right_hip_pos++ ) {
		left_hip.write( left_hip_pos );
		right_hip.write( right_hip_pos );
	} 

}

