#include <stdio.h>
#include"my_string_func.h"

/* read_line: read a line into s, return length */
int read_line(char s[]) {
	int c = 0;
	int i = 0;
	int done = 0;
	do {
		c = getchar();
		if(c == EOF|| c == '\n') {
			done = 1;
		} else {
			s[i++] = c;
		}
	} while(!done);
	
	s[i] = '\0';
	return i;
}

void my_to_upper(char*str_in, char*str_out) {
	for (str_in; *str_in != '\0'; str_in++)
	{
		if (*str_in >= 'A' && *str_in <= 'Z')
		{
			*str_out++ = *str_in;
		}
		else if (*str_in >= 'a' && *str_in <= 'z')
		{
			*str_out++ = *str_in - 32;
		}
		else
		{
			*str_out++ = *str_in;
		}
	}
}

int my_length(char* str) {
	int count = 0;

	for (str; *str != '\0'; str++) {
		count++;
	}

	return count;
}
