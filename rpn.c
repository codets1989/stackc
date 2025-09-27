#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "rpn.h"

float rpneval(char input[]) {
    int i = -1, nextstate = 0, temp_i = 0;
    char temp[50]; 
    cstack stack;
    float a, b, result, ans;
    init_fstack(&stack);

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

            case 1: 
                if (!fis_empty(stack)) {
                    b = fpop(&stack);
                } else {
                    printf("Error Stack empty \n");
                    exit(0);
                }
                if (!fis_empty(stack)) {
                    a = fpop(&stack);
                } else {
                    printf("Error Stack empty \n");
                    exit(0);
                }
                
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
                
                if (!fis_full()) {
                    fpush(&stack, result);
                    nextstate = 0;
                } else {
                    printf("Error! Stack is full\n");
                    exit(0);
                }
                break;

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
                if (!cis_full()) {
                    fpush(&stack, val);
                    temp_i = 0;
                    i--; 
                    nextstate = 0;
                } else {
                    printf("Error! Stack is full\n");
                    exit(0);
                }
                break;

            case 4: 
                nextstate = 0;
                break;

            case 5: 
                if (!fis_empty(stack)) {
                    ans = cpop(&stack);
                } else {
                    printf("Error Stack empty \n");
                    exit(0);
                }
                if (!fis_empty(stack)) {
                    printf("Error: Extra operands left on stack\n");
                    exit(0);
                }
                return ans;

            case 6: 
                printf("Error: Invalid character '%c'\n", input[i]);
                exit(0);
        }
    }
}