#include <stdio.h>
#include "stack.h"

int menu(void);
//The main.c program initializes an empty stack and repeatedly displays a menu for the user to choose stack operations. It performs push, pop, and print actions only when valid and continues until the user selects the option to quit.
int main(void) {
    stack top;
    int data_item;
    int selection;

    init_stack(&top);
    selection = menu();

    while (selection != 4) {
        switch(selection) {

            case 1:
                if (!is_full()) {
                    printf("Enter number: ");
                    scanf("%d", &data_item);
                    push(&top, data_item);
                } else {
                    printf("Stack is full\n");
                }
                break;

            case 2:
                if (!is_empty(top)) {
                    data_item = pop(&top);
                    printf("%d popped\n", data_item);
                } else {
                    printf("Stack is empty\n");
                }
                break;

            case 3:
                if (!is_empty(top)) {
                    print_stack(top);
                } else {
                    printf("Stack is empty\n");
                }
                break;

            default:
                printf("Not a valid selection\n");
        }

        selection = menu();
    }

    return 0;
}
int menu ()
{
    int choice;
    printf("\n--- STACK MENU ---\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print Stack\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}