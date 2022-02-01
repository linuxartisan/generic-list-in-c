#ifndef LINUXARTISAN_STACK_H
#define LINUXARTISAN_STACK_H

#include "List.h"

typedef struct Stack
{
    List* list;
}Stack;


Stack* stack_create();
void stack_destroy(Stack*);

/* capacity */
bool stack_empty(Stack*);
int stack_size(Stack*);

/* element access */
void* stack_top(Stack*);

/* modifiers */
void stack_push(Stack*, void* elem);
void* stack_pop(Stack*);

#endif
