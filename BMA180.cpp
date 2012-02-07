#include "mbed.h"
#include "BMA180.h"
 
BMA180::BMA180(PinName sda, PinName scl): _i2c(sda,scl) {
	_i2c.frequency(100000);
	data[0] = BMA180_ID;
	data[1] = 0x00;
	init();
}
	 
int BMA180::init(){
	_i2c.write(BMA180_ADDR, data, 1);    
     _i2c.read(BMA180_ADDR, data, 1);  
		         
     if (data[0] != 0x03) {
         printf("invalid chip id %d\n", data[0]);
         return 1;
     }
		     
     return 0;
}
		 
float BMA180::getX(){
     data[0] = BMA180_X_ACC;
     _i2c.write(BMA180_ADDR, data, 1);
     _i2c.read(BMA180_ADDR, data, 2);
     data[0] >>= 2;
     x  = *((int16_t*)data);
     x /= 16384.0;
     return x;
}
			 
float BMA180::getY(){
     data[0] = BMA180_Y_ACC;
     _i2c.write(BMA180_ADDR, data, 1);
     _i2c.read(BMA180_ADDR, data, 2);
     data[0] >>= 2;
     y  = *((int16_t*)data);
     y /= 16384.0;
     return y;
}
				 
float BMA180::getZ(){
     data[0] = BMA180_Z_ACC;
     _i2c.write(BMA180_ADDR, data, 1);
     _i2c.read(BMA180_ADDR, data, 2);
     data[0] >>= 2;
     z  = *((int16_t*)data);
     z /= 16384.0;
     return z;
}
