#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SIZE 100


typedef struct{
    int data[MAX_SIZE];
    int size;
    int head;
    int max_size;
}Queue;

void init(Queue *q){
    q->size = 0;
    q->head = 0;
    q->max_size = MAX_SIZE;
}

bool is_empty(Queue *q){
    if(q->size == 0){
        return true;
    }
    return false;
}

void destroy(Queue *q){
    q->size = 0;
    q->head = 0;
}

bool push_back(Queue *q, int val){
    if (q->size >= q->max_size){
        return false;
    }
    q->data[(q->head + q->size) % q->max_size] = val;
    q->size++;
    return true;
}

int pop_front(Queue *q){
    if (is_empty(q) == true){
        return -1;
    }
    int val = q->data[q->head];
    q->head = (q->head + 1) % q->max_size;
    q->size--;
    return val;
}
