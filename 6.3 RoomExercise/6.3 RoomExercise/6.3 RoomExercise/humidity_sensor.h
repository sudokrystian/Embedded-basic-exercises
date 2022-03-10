#pragma once
#include <stdint.h>

//Get's humidity from the sensor (for now dummy data)
uint8_t humiditySensor_getHumidity();
//Initializes port
void humiditySensor_initPort(int port);