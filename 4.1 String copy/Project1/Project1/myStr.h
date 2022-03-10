#ifndef MY_STR
#define MY_STR

// Returns length of the string
int my_strlen(const char* str);

// Compares two strings. Returns -1 if second string is shorter, 0 if they are the same and 1 if second string is longer
int my_strcmp(char str1[], char str2[]);

// Copys array to thet destination
char* my_strcpy(char* dest, const char* src);

// Duplicates string
char* my_strdup(const char* str);

#endif