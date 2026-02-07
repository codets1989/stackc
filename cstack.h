#ifndef STACK_H
#define STACK_H

#include "boolean.h"

typedef struct stacknode {
    char  data;
    struct stacknode *next;
} *cstack;

void init_cstack(cstack *);
boolean cis_empty(cstack);
boolean cis_full(void);
void push(cstack *, char);
int pop(cstack *);
void print_cstack(cstack s);

#endif