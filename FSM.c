#include <stdio.h>
#include <stdlib.h>
#include "fsm.h"

boolean fsm(char my_input[]) {
int i = -1;
int nextstate = 0;
cstack top;

init_cstack(&top);
while(1) {
    switch (nextstate) {
        case 0: i++;
            if (is_open(my_input[i]))
                nextstate = 1;
            else if (is_close(my_input[i]))
                nextstate = 2;
            else if (my_input[i] == '\0')
                nextstate = 3;
            else   
                nextstate = 4;
            break;
        case 1: if (!cis_full()){
                cpush(&top,my_input[i]);
                nextstate = 0;
        }
        else {
            printf("Error! Stack is full\n");
            exit(0);
        }
        break;
        case 2: if (!cis_empty(top)) {
                    o = cpop(&top);
                    c = my_input[i];
                    if (is_brother(o,c)) {
                        nextstate = 0;
                    }
                    else {
                        printf("Error! Delimeters do not match\n");
                        return FALSE;
                    }
        }
        else {
            printf("No open delimeter to compare to \n");
            return FALSE;
        }
        break;
        case 3: if (cis_empty(top)) {
                    return TRUE;
        }
        else {
            printf("Error! Extra open delimiters\n");
            return FALSE;
        }
        break;
        case 4: nextstate = 0;
                break;
    }
}
}