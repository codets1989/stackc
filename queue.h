#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"

typedef struct queuenode {
    int data;
    struct queuenode *next;
} *node_pointer;

typedef struct endpointter {
    node_pointer front;
    node_pointer back;
} *queue;

void init_queue(queue *q);
boolean is_empty(queue q);
boolean is_full(void);
void add_queue(queue *q, int);
int fetch(queue *q);
void list(queue q);

#endif
