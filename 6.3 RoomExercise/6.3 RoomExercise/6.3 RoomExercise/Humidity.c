#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "humidity_sensor.h"
#include "Humidity.h"

typedef struct humidity
{
	uint8_t _latestHumidity;
	uint8_t portNo;
} humidity;

humidity_t humidity_create(uint8_t portNo)
{
	humidity_t _newHumidity = calloc(sizeof(humidity), 1);

	if (_newHumidity == NULL)
	{
		return NULL;
	};

	_newHumidity->_latestHumidity = -999;
	_newHumidity->portNo = portNo;
	humiditySensor_initPort(portNo);
	return _newHumidity;
}

void humidity_meassure(humidity_t self)
{
	self->_latestHumidity = humiditySensor_getHumidity();
}

uint8_t humidity_getHumidity(humidity_t self)
{
	return self->_latestHumidity;
}