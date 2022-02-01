#include <assert.h>
#include "List.h"

List* create_list() {
    List* L = (List*) malloc(sizeof(List));
    L->length = 0;
    L->head = NULL;
    L->tail = NULL;
    return L;
}

void destroy_list(List* L) {
    assert(L != NULL);
    clear(L);
    free(L);
}


/* capacity */
bool empty(List* L) {
    assert(L != NULL);
    return (L->length == 0);
}

int size(List* L) {
    assert(L != NULL);
    return L->length;
}


/* element access */
void* front(List* L) {
    assert(L != NULL);

    if (L->length == 0) {
        return NULL;
    }

    return L->head->value;
}

void* back(List* L) {
    assert(L != NULL);

    if (L->length == 0) {
        return NULL;
    }

    return L->tail->value;
}

void* at_index(List* L, int index) {
    assert(L != NULL);

    // invalid index
    if (index < 0 || index >= L->length) {
        return NULL;
    }

    Node* t = L->head;
    int i = 0;

    while (i < index) {
        t = t->next;
        i++;
    }

    return t->value;
}


/* modifiers */
void push_front(List* L, void* elem) {
    assert(L != NULL);

    Node* node = (Node*) malloc (sizeof (Node));

    node->value = elem;
    node->next = NULL;
    node->prev = NULL;

    if (L->head == NULL) {
        L->head = node;
        L->tail = node;
    } else {
        Node* oldHead = L->head;
        node->next = oldHead;
        oldHead->prev = node;
        L->head = node;
    }
    L->length += 1;
}

void* pop_front(List* L) {
    assert(L != NULL);

    if (L->length == 0) {
        return NULL;
    }

    void* outValue = L->head->value;
    Node* oldHead = L->head;

    if (L->length == 1) {
        L->head = NULL;
        L->tail = NULL;
    } else {
        L->head = L->head->next;
        L->head->prev = NULL;
    }

    free(oldHead);
    L->length -= 1;
    return outValue;
}

void push_back(List* L, void* elem) {
    assert(L != NULL);

    Node* node = (Node*) malloc (sizeof (Node));

    node->value = elem;
    node->next = NULL;
    node->prev = NULL;

    if (L->head == NULL) {
        L->head = node;
        L->tail = node;
    } else {
        Node* oldTail = L->tail;
        node->prev = oldTail;
        oldTail->next = node;
        L->tail = node;
    }
    L->length += 1;
}

void* pop_back(List* L) {
    assert(L != NULL);

    if (L->length == 0) {
        return NULL;
    }

    void* outValue = L->tail->value;
    Node* oldTail = L->tail;

    if (L->length == 1) {
        L->head = NULL;
        L->tail = NULL;
    } else {
        L->tail = L->tail->prev;
        L->tail->next = NULL;
    }

    free(oldTail);
    L->length -= 1;
    return outValue;
}

void insert_at(List* L, int index, void* elem) {
    assert(L != NULL);
    assert(0 <= index && index <= L->length);

    if (index == 0) {
        push_front(L, elem);
    } else if (index == L->length) {
        push_back(L, elem);
    } else {
        Node* curr = L->head;
        int i = 0;
        while (i < index) {
            curr = curr->next;
            i++;
        }
        Node* node = (Node*) malloc(sizeof(Node));
        node->value = elem;
        node->next = curr;
        node->prev = curr->prev;
        node->prev->next = node;
        curr->prev = node;
        L->length += 1;
    }
}

void* remove_at(List* L, int index) {
    assert(L != NULL);
    assert(0 <= index && index < L->length);

    if (index == 0) {
        return pop_front(L);
    } else if (index == L->length - 1) {
        return pop_back(L);
    }

    void* outValue = NULL;
    Node* curr = L->head;
    int i = 0;

    while (i < index) {
        curr = curr->next;
        i++;
    }

    outValue = curr->value;
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    free(curr);
    L->length -= 1;
    return outValue;
}

void clear(List* L) {
    assert(L != NULL);

    Node* curr = L->head;
    while (curr != NULL) {
        Node* t = curr;
        curr = curr->next;
        free(t);
    }

    L->head = L->tail = NULL;
    L->length = 0;
}
