#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct{
    int data;
    struct Node *next;
}Node;

typedef struct{
    Node *head;
    Node *tail;
    int size;
}Queue;

void init(Queue *q){
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

bool is_empty(Queue *q){
    if (q->size == 0){
        return true;
    }
    return false;
}

void push_back(Queue *q, int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;

    if (q->tail != NULL){
        q->tail->next = newnode;
    }
    q->tail = newnode;

    if (q->head == NULL){
        q->head = newnode;
    }
    q->size++;
}


int pop_front(Queue *q){
    if (is_empty(q)){
        return -1;
    }
    Node *temp = q->head;
    int val = temp->data;
    q->head = q->head->next;

    if (q->head == NULL){
        q->tail = NULL;
    }
    free(temp);
    q->size--;
    return val;
}

int first(Queue *q){
    if (is_empty(q)){
        return -1;
    }
    return q->head->data;
}

void destroy(Queue *q){
    while (!is_empty(q)){
        pop_front(q);
    }
}