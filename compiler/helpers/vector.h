#ifndef VECTOR_H
#define VECTOR_H

#define VECTOR_MAX_SIZE 1024     


typedef struct {
    int data[VECTOR_MAX_SIZE];
    int size;
    int peek_index;
} 
Vector;

Vector vector_create(); 

void vector_push(Vector *vec, int value);

int vector_pop(Vector *vec);

void vector_set_peek_pointer(Vector *vec, int index);

int vector_peek(Vector *vec);

#endif