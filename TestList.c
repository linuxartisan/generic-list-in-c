#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "List.h"

List* setup();
int** fillList(List*, int count);
void clearList(List*, int** intArr, int count);
void testCreation(List*);
void testAccess(List*);
void testRemoval(List*);
void testInsertion(List*);
void testRemoveAt(List*);
void testClear(List*);
void testDestruction(List*);

int main() {
    List* L = setup();
    testCreation(L);
    testAccess(L);
    testRemoval(L);
    testInsertion(L);
    testClear(L);
    testDestruction(L);
    L = NULL;

    return 0;
}

List* setup() {
    return create_list();
}

void testCreation(List* L) {
    assert(size(L) == 0);
    assert(empty(L));
}

int** fillList(List* L, int count) {
    int** intArr = malloc(count * sizeof(int*));
    for (int i = 0; i < count; ++i) {
        intArr[i] = malloc(sizeof(int*));
        *(intArr[i]) = i + 1;
        push_back(L, intArr[i]);
    }
    return intArr;
}

void clearList(List* L, int** intArr, int count) {
    clear(L);
    for (int i = 0; i < count; ++i) {
        free(intArr[i]);
    }
    free(intArr);
}

void testAccess(List* L) {
    int count = 5;
    int** intArr = fillList(L, count);

    assert(front(L) == intArr[0]);
    assert(back(L) == intArr[count - 1]);
    for (int i = 0; i < count; ++i) {
        assert(at_index(L, i) == intArr[i]);
    }

    clearList(L, intArr, count);
}

void testRemoval(List* L) {
    int count = 5;
    int** intArr = fillList(L, count);

    assert(front(L) == intArr[0]);
    assert(back(L) == intArr[count - 1]);
    for (int i = 0; i < count; ++i) {
        assert(at_index(L, i) == intArr[i]);
    }

    assert(pop_front(L) == intArr[0]);
    assert(pop_back(L) == intArr[count - 1]);
    assert(!empty(L));
    assert(size(L) == count - 2);

    assert(front(L) == intArr[1]);
    assert(back(L) == intArr[count - 2]);

    clearList(L, intArr, count);

    intArr = fillList(L, count);
    for (int i = 0; i < count; ++i) {
        assert(pop_front(L) == intArr[i]);
    }
    clearList(L, intArr, count);

    intArr = fillList(L, count);
    for (int i = 0; i < count; ++i) {
        assert(pop_back(L) == intArr[count - 1 - i]);
    }
    clearList(L, intArr, count);
}

void testInsertion(List* L) {
    int arr[] = {1, 2, 3, 4, 5};

    insert_at(L, 0, &(arr[0]));
    insert_at(L, 1, &(arr[1]));
    insert_at(L, 2, &(arr[2]));

    assert(size(L) == 3);
    assert(pop_back(L) == &(arr[2]));
    assert(pop_back(L) == &(arr[1]));
    assert(pop_back(L) == &(arr[0]));
    assert(size(L) == 0);

    push_front(L, &(arr[3]));
    push_front(L, &(arr[2]));
    push_front(L, &(arr[1]));
    push_front(L, &(arr[0]));
    insert_at(L, 4, &(arr[4]));

    for (int i = 0; i < 5; ++i) {
        assert(at_index(L, i) == &(arr[i]));
    }
    clear(L);

    push_back(L, &(arr[0]));
    push_back(L, &(arr[1]));
    push_back(L, &(arr[3]));
    push_back(L, &(arr[4]));
    insert_at(L, 2, &(arr[2]));

    for (int i = 0; i < 5; ++i) {
        // printf("arr[%d] = %d\n", i, arr[i]);
        assert(at_index(L, i) == &(arr[i]));
    }
    clear(L);
}

void testRemoveAt(List* L) {
    int count = 5;
    int** intArr = fillList(L, count);

    for (int i = 0; i < count; ++i) {
        assert(remove_at(L, i) == intArr[i]);
    }
    assert(empty(L));

    clearList(L, intArr, count);
}

void testClear(List* L) {
    int count = 4;
    int** intArr = fillList(L, count);
    assert(!empty(L));
    assert(size(L) == count);
    clear(L);
    assert(empty(L));
    assert(size(L) == 0);
    clearList(L, intArr, count);
}

void testDestruction(List* L) {
    destroy_list(L);
}
