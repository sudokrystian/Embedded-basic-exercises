#pragma once
#include <stdint.h>

typedef struct list* list_t;

typedef enum {
	LIST_OK, LIST_EMPTY, LIST_NOT_FOUND, LIST_NULL, LIST_ERROR
}ListReturnCode;

//Allocate memory for the list and return a pointer to it
list_t list_create(void);
//Destroy the list and free memory
ListReturnCode list_destroy(list_t self);
//Add an item to the list
ListReturnCode list_addItem(list_t self, void* item);
//Het an item from the list
ListReturnCode list_getItem(list_t self, void** item, uint16_t index);
//Remove an item from the list
ListReturnCode list_removeItem(list_t self, void* item);
//Return size of the list
uint16_t list_noOfItems(list_t self);