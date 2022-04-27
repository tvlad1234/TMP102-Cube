#include "main.h"
#include "tmp102.h"

#define REG_TEMP 0x00

static const uint8_t TMP102_ADDR = 0x48 << 1; // Use 8-bit address
I2C_HandleTypeDef *tmpPort;

uint8_t tmpBegin(I2C_HandleTypeDef *i2cdev)
{

    tmpPort = i2cdev;
    uint8_t a = REG_TEMP;
    HAL_StatusTypeDef ret = HAL_I2C_Master_Transmit(tmpPort, TMP102_ADDR, &a, 1, HAL_MAX_DELAY);
    if (ret != HAL_OK)
        return 0;
    return 1;
}

float readTMPTemperature(void)
{
    float temp;
    int16_t val;

    uint8_t buf[2];
    buf[0] = REG_TEMP;

    HAL_I2C_Master_Transmit(tmpPort, TMP102_ADDR, buf, 1, HAL_MAX_DELAY);
    HAL_Delay(10);
    HAL_I2C_Master_Receive(tmpPort, TMP102_ADDR, buf, 2, HAL_MAX_DELAY);

    val = ((int16_t)buf[0] << 4) | (buf[1] >> 4);

    // Convert to 2's complement, since temperature can be negative
    if (val > 0x7FF)
        val |= 0xF000;

    // Convert to float temperature value (Celsius)
    temp = val * 0.0625;

    return temp;
}