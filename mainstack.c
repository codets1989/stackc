#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int  menu (void);
int main() {
    stack s;
    int selection, num;

    init_stack(&s);
    selection = menu();
    
    while (selection != 4) {
        switch (selection)
        {
        case 1:
             if (!is_full()) {   //PUSH
                printf("Enter a number to push: ");
                scanf("%d", &num);
                push(&s, num);
            } else {
                printf("ERROR: Stack is full.\n");
            }
            break;
        case 2:
            if (!is_empty(s)) {    // POP
                num = pop(&s);
                printf("Popped number: %d\n", num);
            } else {
                printf("ERROR: Stack is empty.\n");
            }
            break;
        case 3:
             if (!is_empty(s)) {  //PRINT
                print_stack(s);
            } else {
                printf("Stack is empty.\n");
            }
            break;
        default:
            printf("Invalid menu selection. Try again.\n");
            break;
        }
        // Display menu again
        selection = menu();
        
    }

    printf("\nGoodbye! Program ended.\n");
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