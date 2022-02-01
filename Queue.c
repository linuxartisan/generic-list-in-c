#include <assert.h>
#include "Queue.h"

Queue* queue_create() {
    Queue* Q = (Queue*) malloc(sizeof(Queue));
    Q->list = create_list();
    return Q;
}

void queue_destroy(Queue* Q) {
    assert(Q != NULL);
    destroy_list(Q->list);
    free(Q);
}

/* capacity */
/* capacity */
bool queue_empty(Queue* Q) {
    assert(Q != NULL);
    return empty(Q->list);
}

int queue_size(Queue* Q) {
    assert(Q != NULL);
    return size(Q->list);
}

/* element access */
void* queue_front(Queue* Q) {
    assert(Q != NULL);
    return front(Q->list);
}

void* queue_back(Queue* Q) {
    assert(Q != NULL);
    return back(Q->list);
}

/* modifiers */
void enqueue(Queue* Q, void* elem) {
    assert(Q != NULL);
    push_back(Q->list, elem);
}

void* dequeue(Queue* Q) {
    assert(Q != NULL);
    return pop_front(Q->list);
}
