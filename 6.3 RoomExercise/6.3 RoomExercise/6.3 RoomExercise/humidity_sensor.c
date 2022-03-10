#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>

#include "humidity_sensor.h"

void humiditySensor_initPort() {
	srand(time(0));
}

uint8_t humiditySensor_getHumidity() {
	return rand();
}