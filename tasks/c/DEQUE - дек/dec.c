#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int head;
    int size;
} Deque;

void init(Deque *d) {
    d->size = 0;
    d->head = 0;
}

bool is_empty(Deque *d) {
    return d->size == 0;
}

bool is_full(Deque *d) {
    return d->size == MAX_SIZE;
}

bool push_back(Deque *d, int val) {
    if (is_full(d)) return false;
    
    int tail = (d->head + d->size) % MAX_SIZE;
    d->data[tail] = val;
    d->size++;
    return true;
}

bool push_front(Deque *d, int val) {
    if (is_full(d)) return false;
    
    d->head = (d->head - 1 + MAX_SIZE) % MAX_SIZE; // двигаем НАЗАД
    d->data[d->head] = val;
    d->size++;
    return true;
}

int pop_front(Deque *d) {
    if (is_empty(d)) return -1;
    
    int val = d->data[d->head];
    d->head = (d->head + 1) % MAX_SIZE; // двигаем ВПЕРЕД
    d->size--;                          // УМЕНЬШАЕМ размер
    return val;
}

int pop_back(Deque *d) {
    if (is_empty(d)) return -1;
    
    int tail = (d->head + d->size - 1) % MAX_SIZE;
    int val = d->data[tail];
    d->size--;                          // УМЕНЬШАЕМ размер
    return val;
}

void destroy(Deque *d) {
    d->size = 0;
    d->head = 0;
}