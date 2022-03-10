#include <stdio.h>
#include"my_string_func.h"

#define MAX_LENGTH 1000
int main() { 
	char line[MAX_LENGTH];
	char upper[MAX_LENGTH];
	int line_length;
	char string[] = "I miss java\n";
	printf("HELLO\n");

		my_to_upper(string, upper);
		line_length = my_length(string);
		printf("Length: %d\t%s\n", line_length, upper);

	return 0; 
}
