#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "Temperature.h"
#include "Humidity.h"
#include "Room.h"
#include "HealthHandler.h"


void startMeasurements(health_handler_t healthHandler)
{
	int i = 1;
	while(1)
	{
		printf("Measurement nr #%d:\n", i);
		healthHandler_showBuildingHealth(healthHandler);
		i++;
		Sleep(3000);
	}
}

int main(void)
{
	health_handler_t healthHandler = healthHandler_create();

	//Create a room
	room_t basement = room_create("Basement", 120);
	//Create sensors
	temp_t temp1 = temperature_create(0);
	temp_t temp2 = temperature_create(1);
	humidity_t humidity1 = humidity_create(0);
	//Assign sensors to the room
	room_addTemperature(basement, temp1);
	room_addTemperature(basement, temp2);
	room_addHumidity(basement, humidity1);

	// Add basement to the Health Handler
	healthHandler_addRoom(healthHandler, basement);

	// Create second room
	room_t kitchen = room_create("Bedroom", 9);
	//Create sensors
	temp_t temp3 = temperature_create(2);
	humidity_t humididty2 = humidity_create(1);
	//Assign sensors to the room
	room_addTemperature(kitchen, temp3);
	room_addHumidity(kitchen, humididty2);

	// AddBedroom to the Health Handler
	healthHandler_addRoom(healthHandler, kitchen);
	//Start measuring
	startMeasurements(healthHandler);
	return 0;
}