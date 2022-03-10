#pragma once
#include <stdint.h>

typedef struct temp* temp_t;

//Allocates memory and returns a pointer to tempreature
temp_t temperature_create(uint8_t portNo);
//Measures temperature in the room and updates lates measurement
void temperature_meassure(temp_t self);
//Returns latest temperature measurement
float temperature_getTemperature(temp_t self);