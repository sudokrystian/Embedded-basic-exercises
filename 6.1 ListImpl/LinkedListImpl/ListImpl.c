#include "List.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
typedef struct list list;

typedef struct node{
	void* data;
	node* next;
} node;

typedef struct list{
	node* head;
} list;


list_t list_create(void)
{
	list_t _newList = calloc(sizeof(list), 1);
	//Check if there is enough memory
	if (NULL == _newList) {
		return NULL;
	}

	_newList->head = NULL;

	return _newList;
}

static void _node_destroy(node* self)
{
	free(self);
	self = NULL;
}

ListReturnCode list_destroy(list_t self)
{
	if (self == NULL)
	{
		return LIST_NULL;
	}

	node* _current = self->head;
	node* _next;
	while (_current != NULL)
	{
		_next = _current->next;
		_node_destroy(_current);
		_current = _next;
	}
	free(self);
	self = NULL;
	return LIST_OK;
}

ListReturnCode list_addItem(list_t self, void* item)
{
	node* _newNode = (node*) calloc(sizeof(node), 1);

	if (NULL == _newNode)
	{
		return LIST_ERROR;
	}

	_newNode->data = item;
	_newNode->next = NULL;

	if (self == NULL)
	{

		return LIST_NULL;
	}

	if (self->head == NULL)
	{
		self->head = _newNode;
		return LIST_OK;
	}

	node* _current = self->head;
 
	while (_current->next != NULL)
	{
		_current = _current->next;
	}

	_current->next = _newNode;


	return LIST_OK;
}

ListReturnCode list_getItem(list_t self, void** item, uint16_t index)
{
	if (self == NULL)
	{
		return LIST_NULL;
	}
	node* _current = self->head;

	for (int i = 0; i <= index; i++)
	{
		if (i == index)
		{
			*item = _current->data;
			return LIST_OK;
		}
		_current = _current->next;
	}
	item = NULL;
	return LIST_NOT_FOUND;
}

ListReturnCode list_removeItem(list_t self, void* item)
{
	if (self == NULL)
	{
		return LIST_NULL;
	}

	node* _current = self->head;

	if (_current->data == item)
	{
		_current = self->head->next;
		_node_destroy(self->head);
		self->head = _current;
		return LIST_OK;
	}

	if (_current->next == NULL) {
		return LIST_NOT_FOUND;
	}

	node* _previous = self->head;
	_current = _current->next;

	while (_current->next != NULL)
	{
		if (_current->data == item)
		{
			_previous->next = _current->next;
			_node_destroy(_current);
			return LIST_OK;
		}
		_previous = _current;
		_current = _current->next;
	}

	return LIST_NOT_FOUND;
}

uint16_t list_noOfItems(list_t self)
{
	if (self == NULL)
	{
		return NULL;
	}

	if (self->head == NULL)
	{
		return 0;
	}

	uint16_t _noElements = 1;
	node* _current = self->head;

	while (_current->next != NULL)
	{
		_noElements++;
		_current = _current->next;
	}

	return _noElements;
}
