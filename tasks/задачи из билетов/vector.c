#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int *data;
    int size;
    int capacity;
} Vector;

void init(Vector *v, int capacity){
    v->data = (int*)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void resize(Vector *v){
    if (v->size == v->capacity){
        v->capacity *= 2;
        v->data = (int*)realloc(v->data,v->capacity * sizeof(int));
    }
}

void push_back(Vector *v,int value){
    if (v->size == v->capacity){
        resize(v);
    }
    v->data[v->size++] = value;
}


void pop_back(Vector *v){
    if(v->size > 0){
        v->size--;
    }
}

int get(Vector *v,int index){
    if (index >= 0 && index <= v-> size){
        return v->data[index];
    }
    return -1;
}

void free_vector(Vector *v){
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 1;
}


