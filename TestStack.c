#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Stack.h"

int main() {
    Stack* S = stack_create();

    // test capacity
    assert(stack_empty(S));
    assert(stack_size(S) == 0);

    // test access and modifiers
    int count = 5;
    char** strArr = malloc(count * sizeof(char*));
    strArr[0] = "Hello ";
    strArr[1] = "World! ";
    strArr[2] = "How ";
    strArr[3] = "are ";
    strArr[4] = "you?";

    stack_push(S, strArr[0]);
    assert(!stack_empty(S));
    assert(stack_size(S) == 1);
    assert(stack_top(S) == strArr[0]);

    for (int i = 1; i < count; ++i) {
        stack_push(S, strArr[i]);
    }
    assert(!stack_empty(S));
    assert(stack_size(S) == count);
    assert(stack_top(S) == strArr[count - 1]);

    for (int i = count - 1; i >= 0; --i) {
        assert(stack_pop(S) == strArr[i]);
    }
    assert(stack_empty(S));
    assert(stack_size(S) == 0);

    int intArr[] = {1, 2, 3};
    stack_push(S, strArr[0]);
    stack_push(S, &(intArr[0]));
    stack_push(S, strArr[2]);
    stack_push(S, &(intArr[1]));
    stack_push(S, strArr[4]);
    stack_push(S, &(intArr[2]));

    assert(stack_pop(S) == &(intArr[2]));
    assert(stack_pop(S) == strArr[4]);
    assert(stack_pop(S) == &(intArr[1]));
    assert(stack_pop(S) == strArr[2]);
    assert(stack_pop(S) == &(intArr[0]));
    assert(stack_pop(S) == strArr[0]);

    stack_push(S, strArr[0]);
    assert(stack_pop(S) == strArr[0]);
    stack_push(S, &(intArr[0]));
    assert(stack_top(S) == &(intArr[0]));
    stack_push(S, strArr[2]);
    assert(stack_top(S) == strArr[2]);
    assert(stack_pop(S) == strArr[2]);
    assert(!stack_empty(S));
    assert(stack_size(S) == 1);
    assert(stack_top(S) == &(intArr[0]));

    stack_destroy(S);
    free(strArr);
    S = NULL;
    return 0;
}
