#pragma once
#include "room.h"

typedef struct health_handler* health_handler_t;

//Allocates memory for health handler and returns pointer to it
health_handler_t healthHandler_create(void);
//Adds room to the health handler
void healthHandler_addRoom(health_handler_t self, room_t room);
//Displays building health in the health handler
void healthHandler_showBuildingHealth(health_handler_t self);