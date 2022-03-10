#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

#include "temperature_sensor.h"

void temperatureSensor_initPort(uint8_t port) {
	srand(time(0));
}

float temperatureSensor_getVoltage() {
	float randomNumber = (rand() % 45);
	return randomNumber;
}