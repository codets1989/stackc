#include <stdio.h>
#include <string.h>
#include "cstack.h"
#include "boolean.h"

int main(void) {
    cstack top;
    init_cstack(&top);

    char string_input[31], pop_item;
    int i = 0;

    printf("Enter a string: ");
    gets(string_input);   
    printf("string: %s\n", string_input);

    while (string_input[i] != '\0') {
        if (!cis_full()) {
                cpush(&top, string_input[i]);
                
            } else {
                printf("ERROR: Stack is full.\n");
            }
        i++;
    }

    print_cstack(top);
    printf("\n");

    printf("Pop function:\n");
    while (!cis_empty(top)) {
        if (!cis_empty(top)) {
        pop_item = cpop(&top);
        printf("-->%c<--\n", pop_item);
    }
        else
        {
            printf("ERROR: Stack is empty\n");
        }
    }

    if (cis_empty(top)) {
        printf("ERROR: Stack is empty\n");
    }

    return 0;
}
