#pragma once
#include <stdint.h>

//Get's voltage of the temperature sensor (dummy data for now)
float temperatureSensor_getVoltage();
void temperatureSensor_initPort(uint8_t portNo);
