#pragma once
/*
 * Kudos to tonycheng888 of the mBed community
 * He provided the original code that started the BMA180 code
 */
#ifndef MBED_BMA180_H
#define MBED_BMA180_H
#define BMA180_ID       0x00
#define BMA180_ADDR     0x80 //datasheet says 0x40 !
#define BMA180_X_ACC    0x02
#define BMA180_Y_ACC    0x04
#define BMA180_Z_ACC    0x06

#include "mbed.h"

class BMA180 {
public:
    BMA180(PinName sda, PinName scl);

    float getX();
    float getY();
    float getZ();
    float* getAll();
    float angleAcceleration();
    int run();
    void calibrate();

private:
    int init();

    I2C _i2c;
    char data[2];
    int16_t x,y,z;
};

#endif
