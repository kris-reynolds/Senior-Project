/*
 * Kudos to tonycheng888 of the mBed community
 * He provided the original code that started the BMA180 code
 */
#include "BMA180.h"
#include "constants.h"

//extern int g_mode;

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
int BMA180::init() {
    _i2c.write(BMA180_ADDR, data, 1);
    _i2c.read(BMA180_ADDR, data, 1);

    if (data[0] != 0x03) {
        printf("invalid chip id %d\n", data[0]);
        return 1;
    }

    return 0;
}

/*
 * Initiate the connection with the Accelerometer
 */
int BMA180::run() {
    // Define reasonable constraints
    // If outside these constraints will kick interrupt
    int xmin = -1;
    int xmax = 1;
    int ymin = -1;
    int ymax = 1;
    int zmin = -1;
    int zmax = 1;

    // Flag that will be set, 0 if not set
    float x_flag;
    float y_flag;
    float z_flag;


    // Reset flags for next reading
    x_flag = 0;
    y_flag = 0;
    z_flag = 0;

    // Get the most current data
    float* accel= {getAll()};
    int x_val = accel[0];
    int y_val = accel[1];
    int z_val = accel[2];

    // Set the flags
    if ( xmin > x_val || xmax < x_val )
        x_flag = x_val;
    if ( ymin > y_val || ymax < y_val )
        y_flag = y_val;
    if ( zmin > z_val || zmax < z_val )
        z_flag = z_val;

    // If a flag was thrown, do something about it
    if ( 0 != x_flag || 0 != y_flag || 0 != z_flag ) {
        float flags[] = { x_flag, y_flag, z_flag };
        flags[1] = flags[1]*2;
        // Throw and interrupt with the flag data
        // During the interrupt this should still run
        // Will need current accell data why doing corrections
    }
    // Check every tenth of a second
    // Don't want to bog down
    wait( 0.1 );

    return SUCCESS;
}

/*
 * Return the X acceleration
 */
float BMA180::getX() {
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
float BMA180::getY() {
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
float BMA180::getZ() {
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
float* BMA180::getAll() {
    float* position = new float[3];
    position[0] = getX();
    position[1] = getY();
    position[2] = getZ();

    return position;
}

/*
 * Get the angle of acceleration
 * based on the current acceleration
 */
float BMA180::angleAcceleration() {
    float* accel= {getAll()};
    return accel[0];
}
