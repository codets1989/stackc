#include <stdio.h>
#include <string.h>
#include "fstack.h"
#include "boolean.h"

int main(void) {
    fstack top;
    init_fstack(&top);

    char string_input[30];   
    int i = 0;
    char ch;

    printf("Enter a string (max 30 chars): ");
    gets(string_input);   
    printf("string: %s\n", string_input);

    //  push each character onto stack using while loop
    while (string_input[i] != '\0') {
        push(&top, string_input[i]);
        i++;
    }

    // print contents of stack (reversed string)
    printf("Reversed string: ");
    print_fstack(top);   // recursive print will display characters in reverse order
    printf("\n");

    //  pop chars with --> x <--
    printf("Pop sequence:\n");
    while (!fis_empty(top)) {
        ch = fpop(&top);
        printf("-->%c<--\n", ch);
    }

    // show stack is empty
    if (fis_empty(top)) {
        printf("Stack is empty\n");
    }

    return 0;
}