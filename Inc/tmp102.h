#ifndef TMP102_H
#define TMP102_H

uint8_t tmpBegin(I2C_HandleTypeDef *i2cdev);
float readTMPTemperature(void);

#endif