#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Queue.h"

int main() {
    Queue* Q = queue_create();

    // test capacity
    assert(queue_empty(Q));
    assert(queue_size(Q) == 0);

    // test access and modifiers
    int count = 5;
    char** strArr = malloc(count * sizeof(char*));
    strArr[0] = "Hello ";
    strArr[1] = "World! ";
    strArr[2] = "How ";
    strArr[3] = "are ";
    strArr[4] = "you?";

    enqueue(Q, strArr[0]);
    assert(!queue_empty(Q));
    assert(queue_size(Q) == 1);
    assert(queue_front(Q) == strArr[0]);

    for (int i = 1; i < count; ++i) {
        enqueue(Q, strArr[i]);
    }
    assert(!queue_empty(Q));
    assert(queue_size(Q) == count);
    assert(queue_front(Q) == strArr[0]);

    for (int i = 0; i < count; ++i) {
        assert(dequeue(Q) == strArr[i]);
    }
    assert(queue_empty(Q));
    assert(queue_size(Q) == 0);

    int intArr[] = {1, 2, 3};
    enqueue(Q, strArr[0]);
    enqueue(Q, &(intArr[0]));
    enqueue(Q, strArr[2]);
    enqueue(Q, &(intArr[1]));
    enqueue(Q, strArr[4]);
    enqueue(Q, &(intArr[2]));

    assert(dequeue(Q) == strArr[0]);
    assert(dequeue(Q) == &(intArr[0]));
    assert(dequeue(Q) == strArr[2]);
    assert(dequeue(Q) == &(intArr[1]));
    assert(dequeue(Q) == strArr[4]);
    assert(dequeue(Q) == &(intArr[2]));

    enqueue(Q, strArr[0]);
    assert(dequeue(Q) == strArr[0]);
    enqueue(Q, &(intArr[0]));
    assert(queue_front(Q) == &(intArr[0]));
    enqueue(Q, strArr[2]);
    assert(queue_front(Q) == &(intArr[0]));
    assert(queue_back(Q) == strArr[2]);
    assert(dequeue(Q) == &(intArr[0]));
    assert(!queue_empty(Q));
    assert(queue_size(Q) == 1);
    assert(queue_front(Q) == strArr[2]);
    assert(queue_back(Q) == strArr[2]);

    queue_destroy(Q);
    free(strArr);
    Q = NULL;
    return 0;
}
