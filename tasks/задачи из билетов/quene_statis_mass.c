#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>

#define MAX_LEN 100

typedef struct{
    int data[MAX_LEN];
    int size;
    int head;
} Quene;

void init(Quene *q){
    q->size = 0;
    q->head = 0;
}

int is_empty(Quene *q){
    return q->size == 0;
}

void destroy(Quene *q){
    q->size = 0;
    q->head = 0;
}

int size(Quene *q){
    return q->size;
}

bool push_back(Quene *q, int val){
    if (q->size >= MAX_LEN){
        return false;
    }
    q->data[((q->head + q->size) % MAX_LEN)] = val;
    q->size++;
    return true;
}

int pop_front(Quene *q){
    if (size(q) == 0){
        return -1;
    }
    int res = q->data[q->head];
    q->head = (q->head + 1) % MAX_LEN;
    q->size--;
    return res;
}

