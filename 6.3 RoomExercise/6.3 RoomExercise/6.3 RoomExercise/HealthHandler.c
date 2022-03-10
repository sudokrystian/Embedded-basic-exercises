#include <stdio.h>
#include <stdlib.h>
#include "HealthHandler.h"

#define MAX_ROOMS_NO 10

typedef struct health_handler
{
	room_t _rooms[MAX_ROOMS_NO];
} health_handler;


static void _printRoomHealth(health_handler_t self)
{
	for (int i = 0; i < MAX_ROOMS_NO; i++)
	{
		if (self->_rooms[i] != NULL)
		{
			room_t room = self->_rooms[i];
			room_roomHealth_t roomHealth = (room_getRoomHealth(room));
			char* roomHealthText = room_getRoomHealthText(roomHealth);
			/*printf("%s: area: %d m2 Health: %s\n", room_getLocation(room), room_getArea(room), room_getRoomHealthText(room_getRoomHealth(room)));*/
			printf("-%s area of %d m2 , conditions: %s\n", room_getLocation(room), room_getArea(room), roomHealthText);
		}
	}
	printf("\n");
}

health_handler_t healthHandler_create(void)
{
	health_handler_t _newHealthHandler = calloc(sizeof(health_handler), 1);

	if (_newHealthHandler == NULL)
	{
		return NULL;
	}


	return _newHealthHandler;
}

void healthHandler_addRoom(health_handler_t self, room_t room)
{
	for (int i = 0; i < MAX_ROOMS_NO; i++)
	{
		if (self->_rooms[i] == NULL)
		{
			self->_rooms[i] = room;
			return;
		}
	}
}

void healthHandler_showBuildingHealth(health_handler_t self)
{
	_printRoomHealth(self);
}