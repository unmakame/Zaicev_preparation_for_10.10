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
    q->head =0;
}

bool is_empty(Queue *q){
    if (q->size == 0){
        return true;
    }
    return false;
}

void destroy(Queue *q){
    q->size = 0;
    q->head = 0;
}

bool push_back(Queue *q, double val){
    if (q->size == MAX_SIZE){
        return false;
    }
    q->data[(q->head + q->size) % MAX_SIZE] = val;
    q->size++;
    return true;
}

int pop_front(Queue *q){
    if (q->size == 0){
        return -1;
    }
    int val;
    val = q->data[q->head];
    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;
    return val;
}