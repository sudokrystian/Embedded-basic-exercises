#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "temperature_sensor.h"
#include "temperature.h"

typedef struct temp
{
	// Declaration
	bool temperature_metricUnits;
	float _latestTemp;
	uint8_t _driverPort;
} temp;

static float _calculateTemp(float voltage)
{
	//Dummy conversion
	return (3 * voltage)/2;
}

temp_t temperature_create(uint8_t portNo)
{
	temp_t _newTemp = malloc(sizeof(temp));

	if (_newTemp == NULL)
	{
		return NULL;
	};

	_newTemp->_driverPort = portNo;
	_newTemp->_latestTemp = 0;
	temperatureSensor_initPort(portNo);

	return _newTemp;
}

void temperature_meassure(temp_t self)
{
	self->_latestTemp = _calculateTemp(temperatureSensor_getVoltage(self->_driverPort));
}

float temperature_getTemperature(temp_t self)
{
	float _tmp = self->_latestTemp;
	if (self->temperature_metricUnits)
	{
		//Here actual conversion should happen depending on the sensor documentation. For now let's assume taht value 0.4 is correct
		_tmp *= 0.4;
	}

	return _tmp;
}
