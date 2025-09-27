#include <stdio.h>
#include <stdlib.h>
#include "rpn.h"

double rpneval(char input[]) {
    int i = -1, nextstate = 0;
    float temp_i=0;
    char temp[50]; 
    cstack stack;

    init_stack(&stack);

    while (1) {
        switch (nextstate) {
            case 0: 
                i++;
                if (strchr("+-*/", input[i])) {
                    nextstate = 1;
                } else if (isdigit(input[i])) {
                    nextstate = 2;
                } else if (isspace(input[i])) {
                    nextstate = 4;
                } else if (input[i] == '\0') {
                    nextstate = 5;
                } else {
                    nextstate = 6;
                }
                break;

            case 1: { 
                if (!cis_empty(stack)) {
                     float b = cpop(&stack);
                }
                else {
                    printf("Error Stack empty \n");
                    exit(0);
                }
                if (!cis_empty(stack)) {
                     float a = cpop(&stack);
                }
                else
                {
                    printf("Error Stack empty \n");
                    exit(0);
                } 
                float result;
                switch (input[i]) {
                    case '+': result = a + b; break;
                    case '-': result = a - b; break;
                    case '*': result = a * b; break;
                    case '/':
                        if (b == 0) {
                            printf("Error: Division by zero\n");
                            exit(0);
                        }
                        result = a / b; break;
                }
                if (!cis_full())
                {
                    push(&stack, result);
                    nextstate = 0;
                    break;
                }
                else {
                    printf("Error! Stack is full\n");
                    exit(0);
                }
                
            }

            case 2: 
                temp[temp_i++] = input[i];
                i++;
                if (isdigit(input[i]) || input[i] == '.') {
                    nextstate = 2;
                } else {
                    nextstate = 3;
                }
                break;

            case 3: 
                temp[temp_i] = '\0';
                float val = atof(temp);
                if (!cis_full()){
                   cpush(&stack, val);
                    temp_i = 0;
                    i--; 
                    nextstate = 0;
                    break;
                }
                else
                {
                    printf("Error! Stack is full\n");
                    exit(0);
                }
            case 4: 
                nextstate = 0;
                break;

            case 5: { 
                if (!is_empty(&stack)) {
                    float ans = cpop(&stack);
                   
                }
                else
                {
                    printf("Error Stack empty \n");
                    exit(0);
                }
                if (!is_empty(&stack)) {
                    printf("Error: Extra operands left on stack\n");
                    exit(0);
                }
                return ans;
            }

            case 6: 
                printf("Error: Invalid character '%c'\n", input[i]);
                exit(0);
        }
    }
}
