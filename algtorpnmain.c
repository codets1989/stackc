#include <stdio.h>
#include <string.h>
#include "algtorpn.h"

int main(void) {
    char string_input[101];

    printf("Enter an arithmetic expression: ");
    gets(string_input);

    printf("%f\n", shunting_yard(string_input));

    return 0;
}