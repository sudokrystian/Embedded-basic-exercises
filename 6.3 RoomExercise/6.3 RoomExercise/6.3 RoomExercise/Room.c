#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "room.h"

#define MAX_TEMP_SENSORS 4
#define MAX_HUMIDITY_SENSORS 2

typedef struct room
{
	char _location[50];
	uint8_t _squareMeters;
	temp_t _tempSensors[MAX_TEMP_SENSORS];
	humidity_t _humiditySensors[MAX_HUMIDITY_SENSORS];
} room;

static room_roomHealth_t _calculateHealth(float temp, float hum)
{
	if (temp < 4 && hum > 10) {
		return BAD;
	}
	else if (temp < 10 && hum > 3) {
		return AVERAGE;
	}
	return DISASTER; // dummy calculation;
}

static float _calculateAverageTemperature(float totalTemp, int numberOfMeasurements)
{
	return (float)totalTemp / numberOfMeasurements;
}

static uint8_t _calculateAverageHumidity(uint8_t totalHumidity, int numberOfMeasurements)
{
	return (uint8_t)totalHumidity / numberOfMeasurements;
}

room_t room_create(char* location, uint8_t sqMeter)
{
	room_t _newRoom = calloc(sizeof(room), 1);

	if (_newRoom == NULL)
	{
		return NULL;
	}

	strncpy(_newRoom->_location, location, sizeof(_newRoom->_location) - 1);
	_newRoom->_squareMeters = sqMeter;

	return _newRoom;
}

void room_destroy(room_t self)
{
	for (int i = 0; i < MAX_HUMIDITY_SENSORS; i++)
	{
		free(self->_humiditySensors[i]);
	}

	for (int i = 0; i < MAX_TEMP_SENSORS; i++)
	{
		free(self->_tempSensors[i]);
	}

	free(self);
}

void room_addTemperature(room_t self, temp_t temperature)
{
	for (int i = 0; i < MAX_TEMP_SENSORS; i++)
	{
		if (self->_tempSensors[i] == NULL)
		{
			self->_tempSensors[i] = temperature;
			return;
		}
	}
}

void room_addHumidity(room_t self, humidity_t humidity)
{
	for (int i = 0; i < MAX_HUMIDITY_SENSORS; i++)
	{
		if (self->_humiditySensors[i] == NULL)
		{
			self->_humiditySensors[i] = humidity;
			return;
		}
	}
}

room_roomHealth_t room_getRoomHealth(room_t self)
{
	int _humidityMeasurements = 0;
	uint8_t _totalHumidity = 0;

	for (int i = 0; i < MAX_HUMIDITY_SENSORS; i++)
	{
		if (self->_humiditySensors[i] != NULL)
		{
			humidity_meassure(self->_humiditySensors[0]);
			_totalHumidity += humidity_getHumidity(self->_humiditySensors[0]);
			_humidityMeasurements++;
		}
	}

	int _tempMeasurements = 0;
	float _totalTemp = 0;

	for (int i = 0; i < MAX_TEMP_SENSORS; i++)
	{
		if (self->_tempSensors[i] != NULL)
		{
			temperature_meassure(self->_tempSensors[i]);
			_totalTemp += temperature_getTemperature(self->_tempSensors[i]);
			_tempMeasurements++;
		}
	}

	float averageTemp = _calculateAverageTemperature(_totalTemp, _tempMeasurements);

	float averageHumidity = _calculateAverageHumidity(_totalHumidity, _humidityMeasurements);

	return _calculateHealth(averageTemp, averageHumidity);
}

char* room_getRoomHealthText(room_roomHealth_t health)
{
	if (health == BAD) {
		return "Bad\n";
	}
	else if (health == AVERAGE) {
		return "Average\n";
	}
	else if (health == DISASTER) {
		return "Disaster\n";
	}
	return "Error in getting room health\n";
}

char* room_getLocation(room_t self)
{
	return self->_location;
}

uint8_t room_getArea(room_t self)
{
	return self->_squareMeters;
}