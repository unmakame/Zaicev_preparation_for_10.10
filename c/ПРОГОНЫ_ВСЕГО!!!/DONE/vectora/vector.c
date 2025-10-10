#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int *data;
    int size;
    int capacity;
}Vector;

void init(Vector *v, int capacity){
    v->data = (int*)malloc(capacity * sizeof(int));
    v->capacity = capacity;
    v->size = 0;
}

void resize(Vector *v){
    v->capacity *= 2;
    v->data = (int*)realloc(v->data,v->capacity * sizeof(int));
}

bool is_empty(Vector *v){
    if (v->size == 0){
        return true;
    }
    return false;
}

void push_back(Vector *v, int data){
    if (v->size == v->capacity){
        resize(v);
    }
    v->data[v->size++] = data;
}

bool pop_back(Vector *v){
    if (is_empty(v)){
        return false;
    }
    v->size--;
    return true;
}

int get(Vector *v, int index){
    if (index >= 0 && index < v->size){
        return v->data[index];
    }
    return -1;
}

void free_vector(Vector *v){
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}