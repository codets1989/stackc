#include <stdio.h>
#include <stdlib.h>
#include "cstack.h"

void init_cstack(cstack *s) {
    *s = NULL;
}

boolean cis_empty(cstack s) {
    if (s == NULL)
        return TRUE;
    else
        return FALSE;
}

boolean cis_full(void) {
    cstack temp;
    temp = (cstack) malloc(sizeof(struct stacknode));
    if (temp == NULL)
        return TRUE;
    else {
        free(temp);
        return FALSE;
    }
}
void cpush(cstack *s, char x) {
    cstack temp;
    temp = (cstack) malloc(sizeof(struct cstacknode));
    temp -> data = x;
    temp -> next = (*s);
    (*s) = temp;
}
char cpop(cstack *s) {
    cstack temp;
    char data_popped;
    temp = *s;
    data_popped = temp->data;
    *s = temp->next;
    free (temp);
    return data_popped;
}
void print_cstack(cstack s) {
    if (!cis_empty(s)){
        printf("%c \n", s->data);
        print_cstack(s->next);
    }
}