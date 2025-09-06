#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void init_queue(queue *q) {
    *q = (queue) malloc(sizeof(struct endpointter));
    (*q)->front = NULL;
    (*q)->back = NULL;
}

boolean is_empty(queue q) {
    if ((q->front == NULL) && (q->back == NULL))
        return TRUE;
    else
        return FALSE;
}

boolean is_full(void) {
    node_pointer temp;
    temp = (node_pointer) malloc(sizeof(struct queuenode));
    if (temp == NULL)
        return TRUE;
    else {
        free(temp);
        return FALSE;
    }
}

void add_queue(queue *q, int x) {
    node_pointer newnode;
    newnode = (node_pointer) malloc(sizeof(struct queuenode));
    newnode->data = x;
    newnode->next = NULL;

    if (is_empty(*q)) {
        (*q)->front = newnode;
        (*q)->back = newnode;
    } else {
        (*q)->back->next = newnode;
        (*q)->back = newnode;
    }
}

int fetch(queue *q) {
    node_pointer temp;
    int data_fetched;
    temp = (*q)->front;
    data_fetched = temp->data;

    if ((*q)->front == (*q)->back) {
        (*q)->front = NULL;
        (*q)->back = NULL;
    } else {
        (*q)->front = temp->next;
    }
    free(temp);
    return data_fetched;
}

void list(queue q) {
    node_pointer temp;
    temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
