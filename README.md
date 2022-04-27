# TMP102-Cube
TMP102 Library for STM32Cube

### Initializing the sensor
Before reading the sensor, it must be initialized with _tmpBegin_.\
_tmpBegin_ takes a pointer to the I2C Handler and returns 1 if connection was successful.\
_Example:_ `tmpBegin(&hi2c1);`

### Reading the sensor
`readTMPTemperature()` returns the temperature in °C as _float_.
