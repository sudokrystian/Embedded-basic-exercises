#include "List.h"
#include<stdio.h>
#include<stdint.h>


int main(void)
{
	list_t linkedList = list_create();

	list_addItem(linkedList, 20);
	list_addItem(linkedList, 30);
	list_addItem(linkedList, 50);
	list_addItem(linkedList, 60);
	list_addItem(linkedList, 70);
	list_addItem(linkedList, 80);

	int noOfItems = list_noOfItems(linkedList);

	printf("%d\n", noOfItems);

	int number = 0 ;

	list_getItem(linkedList, &number, 1);

	printf("%d\n", number);

	list_getItem(linkedList, &number, 2);
	printf("Before removing : %d\n", number);
	list_getItem(linkedList, &number, 3);
	printf("Before removing : %d\n", number);
	list_getItem(linkedList, &number, 4);
	printf("Before removing : %d\n", number);

	list_removeItem(linkedList, 60);
	printf("After removing and before getting : %d\n", number);
	list_getItem(linkedList, &number, 0);
	printf("After removing : %d\n", number);
	list_getItem(linkedList, &number, 1);
	printf("After removing : %d\n", number);
	list_getItem(linkedList, &number, 2);
	printf("After removing : %d\n", number);
	list_getItem(linkedList, &number, 3);
	printf("After removing : %d\n", number);
	list_getItem(linkedList, &number, 4);
	printf("After removing : %d\n", number);



	list_destroy(linkedList);


}