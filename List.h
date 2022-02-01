#ifndef LINUXARTISAN_LIST_H
#define LINUXARTISAN_LIST_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    void* value;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct List
{
    int length;
    struct Node* head;
    struct Node* tail;
}List;


List* create_list();
void destroy_list(List*);

/* capacity */
bool empty(List*);
int size(List*);

/* element access */
void* front(List*);
void* back(List*);
void* at_index(List*, int index);

/* modifiers */
void push_front(List*, void* elem);
void* pop_front(List*);
void push_back(List*, void* elem);
void* pop_back(List*);
void insert_at(List*, int index, void* elem);
void* remove_at(List*, int index);
void clear(List*);

#endif
