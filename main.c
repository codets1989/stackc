#include <stdio.h>
#include <string.h>
#include "fsm.h"

int main(void)  {
    char string_input[101];
    printf("Enter a string : ");
    gets(string_input);
    if (fsm(string_input))
        printf("All matched correctly\n");
    return 0;
}