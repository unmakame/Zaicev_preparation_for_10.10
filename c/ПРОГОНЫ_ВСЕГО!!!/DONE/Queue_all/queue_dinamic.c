#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node{
    Node *next;
    int data;
};

typedef struct{
    int size;
    Node *head;
    Node *tail;
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

void push_back(Queue *q, int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
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

int pop_first(Queue *q){
    if(is_empty(q)){
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
int get_first(Queue *q){
    if (is_empty(q)){
        return -1;
    }
    int first = q->head->data;
    return first;
}

void destroy(Queue *q){
    while(!is_empty(q)){
        pop_first(q);
    }
}