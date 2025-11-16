#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//The main.c program initializes an empty stack and repeatedly displays a menu for the user to choose stack operations. It performs push, pop, and print actions only when valid and continues until the user selects the option to quit.
int main() {
    stack s;
    int choice, num;

    init_stack(&s);

    printf("\n--- STACK PROGRAM ---\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print\n");
    printf("4. Quit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    while (choice != 4) {

        switch (choice) { //Based on the choice do something

            case 1: 
                if (!is_full()) {
                    printf("Enter value: ");
                    scanf("%d", &num);
                    push(&s, num);
                } else {
                    printf("Cannot push: Stack is full.\n");
                }
                break;

            case 2: 
                if (!is_empty(s)) {
                    num = pop(&s);
                    printf("Value popped: %d\n", num);
                } else {
                    printf("Cannot pop: Stack is empty.\n");
                }
                break;

            case 3: 
                if (!is_empty(s)) {
                    printf("Stack contents:\n");
                    print_stack(s);
                } else {
                    printf("Stack is empty.\n");
                }
                break;

            default:
                printf("Invalid option. Try again.\n");
        }

        printf("\n--- STACK PROGRAM ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
    }

    printf("\nThanks for using the stack program!\n");
    return 0;
}
