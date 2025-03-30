#include "vector.h"

Vector vector_create() {

    Vector vec;
    vec.size = 0;
    vec.peek_index = 0;
    return vec;
}

void vector_push(Vector *vec, int value) {

    if (vec->size < VECTOR_MAX_SIZE) {
        vec->data[vec->size++] = value;
    }
}

int vector_pop(Vector *vec) {

    if (vec->size > 0) {
        return vec->data[--vec->size];
    }
    return -1; // Or handle the error appropriately
}

void vector_set_peek_pointer(Vector *vec, int index) {

    if (index >= 0 && index < vec->size) {
        vec->peek_index = index;
    }
}

int vector_peek(Vector *vec) {
    
    if (vec->size > 0) {
        return vec->data[vec->peek_index];
    }
    return -1; // Or handle the error appropriately
}