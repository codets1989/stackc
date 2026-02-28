#ifndef STACK_H
#define STACK_H

#include "boolean.h"

typedef struct stacknode {
    float  data;
    struct stacknode *next;
} *fstack;

void init_fstack(fstack *);
boolean fis_empty(fstack);
boolean fis_full(void);
void fpush(fstack *, float);
int fpop(fstack *);
void print_fstack(fstack s);

#endif