#include <assert.h>
#include "Stack.h"

Stack* stack_create() {
    Stack* S = (Stack*) malloc(sizeof(Stack));
    S->list = create_list();
    return S;
}

void stack_destroy(Stack* S) {
    assert(S != NULL);
    destroy_list(S->list);
    free(S);
}


/* capacity */
bool stack_empty(Stack* S) {
    assert(S != NULL);
    return empty(S->list);
}

int stack_size(Stack* S) {
    assert(S != NULL);
    return size(S->list);
}


/* element access */
void* stack_top(Stack* S) {
    assert(S != NULL);
    return front(S->list);
}


/* modifiers */
void stack_push(Stack* S, void* elem) {
    assert(S != NULL);
    push_front(S->list, elem);
}

void* stack_pop(Stack* S) {
    assert(S != NULL);
    return pop_front(S->list);
}
