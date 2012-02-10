/*
 * Kudos to tonycheng888 of the mBed community
 * He provided the original code that started the BMA180 code
 */
#include "mbed.h"
#include "BMA180.h"
 
/*
 * Constructor
 */
BMA180::BMA180(PinName sda, PinName scl): _i2c(sda,scl) {
	_i2c.frequency(100000);
	data[0] = BMA180_ID;
	data[1] = 0x00;
	init();
}
	 
/*
 * Initiate the connection with the Accelerometer
 */
int BMA180::init(){
	_i2c.write(BMA180_ADDR, data, 1);    
     _i2c.read(BMA180_ADDR, data, 1);  
		         
     if (data[0] != 0x03) {
         printf("invalid chip id %d\n", data[0]);
         return 1;
     }
		     
     return 0;
}
		 
/*
 * Return the X acceleration
 */
float BMA180::getX(){
     data[0] = BMA180_X_ACC;
     _i2c.write(BMA180_ADDR, data, 1);
     _i2c.read(BMA180_ADDR, data, 2);
     data[0] >>= 2;
     x  = *((int16_t*)data);
     x /= 16384.0;
     return x;
}
			 
/*
 * Return the Y acceleration
 */
float BMA180::getY(){
     data[0] = BMA180_Y_ACC;
     _i2c.write(BMA180_ADDR, data, 1);
     _i2c.read(BMA180_ADDR, data, 2);
     data[0] >>= 2;
     y  = *((int16_t*)data);
     y /= 16384.0;
     return y;
}

/*
 * Return the Z acceleration
 */
float BMA180::getZ(){
     data[0] = BMA180_Z_ACC;
     _i2c.write(BMA180_ADDR, data, 1);
     _i2c.read(BMA180_ADDR, data, 2);
     data[0] >>= 2;
     z  = *((int16_t*)data);
     z /= 16384.0;
     return z;
}

/*
 * Return all 3 positions in one command
 */
float [] BMA180::getAll(){
	float position [] = [
		this.getX(),
		this.getY(),
		this.getZ()
	]
}

/*
 * Get the angle of acceleration
 * based on the current acceleration
 */
float [] BMA180::angleAcceleration() {
	float position [] = this.getAll();



}
