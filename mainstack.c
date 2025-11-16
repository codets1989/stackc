#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    stack s;
    int choice, num;

    init_stack(&s);

    // Display menu
    printf("\n--- STACK MENU ---\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print Stack\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 4) {

        if (choice == 1) {   // PUSH
            if (!is_full()) {
                printf("Enter a number to push: ");
                scanf("%d", &num);
                push(&s, num);
            } else {
                printf("ERROR: Stack is full.\n");
            }
        }

        else if (choice == 2) {  // POP
            if (!is_empty(s)) {
                num = pop(&s);
                printf("Popped number: %d\n", num);
            } else {
                printf("ERROR: Stack is empty.\n");
            }
        }

        else if (choice == 3) {  // PRINT
            if (!is_empty(s)) {
                print_stack(s);
            } else {
                printf("Stack is empty.\n");
            }
        }

        else {
            printf("Invalid menu selection. Try again.\n");
        }

        // Display menu again
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    printf("\nGoodbye! Program ended.\n");
    return 0;
}
