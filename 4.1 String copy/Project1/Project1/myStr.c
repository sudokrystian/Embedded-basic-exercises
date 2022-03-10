#include <stdlib.h>
#include "myStr.h"

int my_strlen(const char* str) {
    int length = 0;

    if (str[0] == '\0') {
        return 0;
    }


    while (*str != '\0') {
        length++;
        str++;
    }

    return length;
}

int my_strcmp(char string1[], char string2[]) {

    for (int i = 0; ; i++)
    {
        if (string1[i] != string2[i])
        {
            return string1[i] < string2[i] ? -1 : 1;
        }

        if (string1[i] == '\0')
        {
            return 0;
        }
    }
}

char* my_strcpy(char* dest, const char* src) {
    if (dest == NULL) {
        return NULL;
    }
    char* destination = dest;
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    //Pointer to a pointer to a pointer I am getting pointer cancer Jesus
    *dest = '\0';
    return destination;
}

char* my_strdup(const char* str) {
    char* string;
    char* p;
    int len = 0;

    while (str[len])
        len++;

    string = malloc(len + 1);
    p = string;

    while (*str)
        *p++ = *str++;
    *p = '\0';

    return string;
}