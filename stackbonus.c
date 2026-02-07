#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "boolean.h"

int main(void) {
    stack top;
    init_stack(&top);

    char string_input[31], pop_item;
    int i = 0;

    printf("Enter a string: ");
    gets(string_input);   
    printf("string: %s\n", string_input);

    while (string_input[i] != '\0') {
        if (!is_full()) {
                push(&top, string_input[i]);
                
            } else {
                printf("ERROR: Stack is full.\n");
            }
        i++;
    }

    print_stack(top);
    printf("\n");

    printf("Pop function:\n");
    while (!is_empty(top)) {
        if (!is_empty(top)) {
        pop_item = pop(&top);
        printf("-->%c<--\n", pop_item);
    }
        else
        {
            printf("Stack is empty\n");
        }
    }

    if (is_empty(top)) {
        printf("Stack is empty\n");
    }

    return 0;
}
