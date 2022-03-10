#include <stdio.h>
#include "myStr.h"

int main() {
    char string1[] = "I am going insane because of that corona lockdown";
    char string2[] = "What is love";
    char string3[] = "baby don't hurt me";
    char string4[] = "What is love";

    printf("String 1 length: %d\n", my_strlen(string1));
    printf("String 2 length: %d\n", my_strlen(string2));
    printf("String 3 length: %d\n", my_strlen(string3));
    printf("String 4 length: %d\n", my_strlen(string4));

    printf("Comparing two different strings (string 1 and 2): %d\n", my_strcmp(string1, string2));
    printf("Comparing two the same strings (string 2 and 4): %d\n", my_strcmp(string2, string4));

    char source[] = "Source string that should be copied\n";
    char destination[50];
    my_strcpy(destination, source);
    printf("Copy of the string: %s\n", destination);

    char duplicateString[] = "If you say it again you are gay";

    printf("Original: %s\nDuplicate: %s\n", duplicateString, my_strdup(duplicateString));


    return 0;
}