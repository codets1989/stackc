#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cstack.h"
#include "rpn.h"
#include "algtorpn.h"
int is_op(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    return 0;
}

float shunting_yard(char input_string[]) {
    int i = -1, o = 0, state = 0;
    char output_string[101],junk;
    cstack top;
    init_cstack(&top);

    while (1) {
        switch (state) {
            case 0: 
                i++;
                if (isdigit(input_string[i]))
                    state = 1;
                else if (is_op(input_string[i]))
                    state = 2;
                else if (input_string[i] == '(')
                    state = 3;
                else if (input_string[i] == ')')
                    state = 4;
                else if (input_string[i] == '\0')
                    state = 5;
                else if (isspace(input_string[i]))
                    state = 0; 
                else
                    state = 6;
                break;

            case 1: 
                output_string[o++] = input_string[i++];
                while (isdigit(input_string[i]) || input_string[i] == '.') {
                    output_string[o++] = input_string[i++];
                }
                output_string[o++] = ' '; 
                i--; 
                state = 0;
                break;

            case 2: 
                while ((!cis_empty(top)) && (is_op(top->data)) && (prec(input_string[i]) <= prec(top->data))){
                    output_string[o] = cpop(&top);
                    o++;
                    output_string[o] = ' ';
                    o++;
                }
                if (!cis_full()) {
                    cpush(&top, input_string[i]);
                }
                else
                {
                    printf("Stack Full \n");
                }
                state = 0;
                break;

            case 3: 
                if (!cis_full()){
                    cpush(&top, input_string[i]);
                }
                else
                {
                    printf("Error! Stack is Full \n");
                    exit(0);
                }
                state = 0;
                break;

            case 4: 
                while ((!cis_empty(top)) && (top->data != '(')) {
                    output_string[o] = cpop(&top);
                    o++;
                    output_string[o] = ' ';
                    o++;
                }
                if (!cis_empty(top)) {
                    junk= cpop(&top);
                } else {
                    printf("Error: mismatched parentheses\n");
                    exit(0);
                }
                state = 0;
                break;

            case 5: 
                while (!cis_empty(top) && is_op(top->data)) {
                    output_string[o] = cpop(&top);
                    o++;
                    output_string[o] = ' ';
                    o++;
                }
                if (!cis_empty(top)) {
                    printf("Error: leftover parentheses\n");
                    exit(0);
                }
                output_string[o] = '\0';
                return rpneval(output_string);

            case 6: 
                printf("Error: invalid character '%c'\n", input_string[i]);
                exit(0);
        }
    }
}
