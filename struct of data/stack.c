#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define POOL_SIZE 100

typedef struct{
    int data[POOL_SIZE];
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

int deep(Stack *s){
    return s->size;
}

bool push_front(Stack *s, int val){
    if (s->size >= POOL_SIZE){
        return false;
    }
    s->data[s->size] = val;
    s->size++;
    return true;
}

int pop_front(Stack *s){
    if (is_empty(s)){
        return -1;
    }
    int res = s->data[s->size - 1];
    s->size--;
    return res;
}

int stack_top(Stack *s){
    if (is_empty(s)){
        return -1;
    }
    return s->data[s->size - 1];
}

void destroy(Stack *s){
    s->size = 0;
}
