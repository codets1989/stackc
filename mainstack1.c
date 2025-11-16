#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
//This program provides a simple loop that asks the user to push values, pop values, or print the stack while checking for full and empty conditions. It keeps running and responding to user choices until the user decides to exit.
void display_menu() {
    printf("\n--- STACK MENU ---\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print Stack\n");
    printf("4. Quit\n");
    printf("Enter choice: ");
}

int main() {
    stack s;
    int choice, value;

    init_stack(&s);

    display_menu();
    scanf("%d", &choice);

    while (choice != 4) {

        if (choice == 1) {   // Push
            if (!is_full()) {
                printf("Enter number to push: ");
                scanf("%d", &value);
                push(&s, value);
            } else {
                printf("ERROR: Stack is full.\n");
            }
        }

        else if (choice == 2) {   // Pop
            if (!is_empty(s)) {
                value = pop(&s);
                printf("Popped: %d\n", value);
            } else {
                printf("ERROR: Stack is empty.\n");
            }
        }

        else if (choice == 3) {   // Print
            if (!is_empty(s)) {
                print_stack(s);
            } else {
                printf("Stack is empty.\n");
            }
        }

        else {
            printf("Invalid selection.\n");
        }

        display_menu();
        scanf("%d", &choice);
    }

    printf("\nExiting program. Goodbye!\n");
    return 0;
}
