#pragma once
#include <stdint.h>
#include "temperature.h"
#include "humidity.h"

typedef struct room* room_t;

typedef enum {
	PERFECT
	, GOOD
	, AVERAGE
	, BAD
	, DISASTER
}room_roomHealth_t;

//Allocates memory and returns a pointer to the room
room_t room_create(char* location, uint8_t sqMeter);
//Adds temperature sensor to the room
void room_addTemperature(room_t self, temp_t temperature);
//Adds humidity sensor to the room
void room_addHumidity(room_t self, humidity_t humidity);
//Calculates average conditions in the room and returns inforamtion about health
room_roomHealth_t room_getRoomHealth(room_t self);
//Returns string about room condition
char* room_getRoomHealthText(room_roomHealth_t health);
//Returns location of the room
char* room_getLocation(room_t self);
//Returns area of the room
uint8_t room_getArea(room_t self);