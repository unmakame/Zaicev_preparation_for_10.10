#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node Node;

struct Node{
    Node *next;
    Node *prev;
    int data;
};

typedef struct{
    Node *head;
    Node *tail;
    int size;
}Deque;

void init(Deque *d){
    d->head = NULL;
    d->tail = NULL;
    d->size = 0;
}

bool is_empty(Deque *d){
    if (d->size == 0){
        return true;
    }
    return false;
}

void push_back(Deque *d, int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = d->tail;

    if (d->tail != NULL){
        d->tail->next = newnode;
    }
    d->tail = newnode;
    d->size++;
}

int pop_back(Deque *d){
    if (is_empty(d)){
        return -1;
    }
    Node *temp = d->tail;
    int val = temp->data;
    d->tail = d->tail->prev;

    if (d->tail != NULL) {
        d->tail->next = NULL;  
    } else {
        d->head = NULL; 
    }

    free(temp);
    d->size--;
    return val;
}

void push_front(Deque *d, int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = d->head;
    newnode->prev = NULL;

    if (d->head != NULL) {
        d->head->prev = newnode;
    } else {
        d->tail = newnode;
    }

    d->head = newnode; 
    d->size++;
}


int pop_front(Deque *d){
    if (is_empty(d)){
        return -1;
    }
    Node *temp = d->head;
    d->head = d->head->next;
    int val = temp->data;

    if (d->head != NULL) {
    d->head->prev = NULL;  
    } else {
    d->tail = NULL;  
    }

    free(temp);
    d->size--;
    return val;
}


void destroy(Deque *d){
    while (!is_empty(d)){
        pop_front(d);
    }
}
