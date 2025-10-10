#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SIZE 100


typedef struct{
    int data[MAX_SIZE];
    int head;
    int size;
}Queue;

void init(Queue *q){
    q->size = 0;
    q->head = 0;
}

bool is_empty(Queue *q){
    if (q->size == 0){
        return true;
    }
    return false;
}

bool is_full(Queue *q){
    if (q->size >= MAX_SIZE){
        return true;
    }
    return false;
}

bool push_back(Queue *q, int data){
    if (is_full(q)){
        return false;
    }
    q->data[(q->head + q->size) % MAX_SIZE] = data;
    q->size++;
    return true;
}

int pop_first(Queue *q){
    if (is_empty(q)){
        return -1;
    }
    int val = q->data[q->head];
    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;
    return val;
}

int first(Queue *q){
    if (is_empty(q)){
        return -1;
    }
    return q->data[q->head];
}

void destroy(Queue *q){
    q->size = 0;
    q->head = 0;
}