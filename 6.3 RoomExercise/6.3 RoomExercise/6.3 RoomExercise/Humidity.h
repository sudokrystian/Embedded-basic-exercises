#pragma once
#include <stdint.h>

typedef struct humidity* humidity_t;

//Allocates memory and return a pointer to the humidity_t
humidity_t humidity_create(uint8_t portNo);
//Measures current humidity
void humidity_meassure(humidity_t self);
//Get's latest humidity
uint8_t humidity_getHumidity(humidity_t self);