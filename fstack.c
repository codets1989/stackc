#include <stdio.h>
#include <stdlib.h>
#include "fstack.h"

void init_fstack(fstack *s) {
    *s = NULL;
}

boolean fis_empty(fstack s) {
    if (s == NULL)
        return TRUE;
    else
        return FALSE;
}

boolean fis_full(void) {
    fstack temp;
    temp = (fstack) malloc(sizeof(struct stacknode));
    if (temp == NULL)
        return TRUE;
    else {
        free(temp);
        return FALSE;
    }
}
void fpush(fstack *s, char x) {
    fstack temp;
    temp = (fstack) malloc(sizeof(struct sstacknode));
    temp -> data = x;
    temp -> next = (*s);
    (*s) = temp;
}
float fpop(fstack *s) {
    fstack temp;
    float data_popped;
    temp = *s;
    data_popped = temp->data;
    *s = temp->next;
    free (temp);
    return data_popped;
}
void print_fstack(fstack s) {
    if (!fis_empty(s)){
        printf("%f \n", s->data);
        print_fstack(s->next);
    }
}