#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SIZE 100

typedef struct{
    int data[MAX_SIZE];
    int size;
}Stack;

void init(Stack *s){
    s->size = 0;
}

bool is_empty(Stack *s){
    if (s->size == 0){
        return true;
    }
    return false;
}

bool is_full(Stack *s){
    if (s->size >= MAX_SIZE){
        return true;
    }
    return false;
}

int size(Stack *s){
    if (is_empty(s)){
        return 0;
    }
    return s->size;
}

bool push_back(Stack *s, int data){
    if (is_full(s)){
        return false;
    }
    s->data[s->size] = data;
    s->size++;
    return true;
}

int pop_back(Stack *s){
    if (is_empty(s)){
        return -1;
    }
    int val = s->data[s->size - 1];
    s->size -= 1;
    return val;
}

int get_first(Stack *s){
    if (is_empty(s)){
        return -1;
    }
    return s->data[s->size - 1];
}

void destroy(Stack *s){
    s->size = 0;
}
