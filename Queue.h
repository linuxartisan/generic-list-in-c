#ifndef LINUXARTISAN_QUEUE_H
#define LINUXARTISAN_QUEUE_H

#include "List.h"

typedef struct Queue
{
    List* list;
}Queue;


Queue* queue_create();
void queue_destroy(Queue*);

/* capacity */
bool queue_empty(Queue*);
int queue_size(Queue*);

/* element access */
void* queue_front(Queue*);
void* queue_back(Queue*);

/* modifiers */
void enqueue(Queue*, void* elem);
void* dequeue(Queue*);

#endif
