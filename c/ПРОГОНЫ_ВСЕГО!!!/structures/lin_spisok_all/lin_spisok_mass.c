#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SIZE 100

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
}List;

void init(List *l){
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}


bool is_empty(List *l){
    if (l->size == 0){
        return true;
    }
    return false;
}

bool is_full(List *l){
    if(l->size >= MAX_SIZE){
        return true;
    }
    return false;
}

void insert_back(List *l,int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    l->tail->next = newnode;
    newnode->next = l->head;
    l->size++;
}

int pop_back(List *l){
    if (is_empty(l)){
        return -1;
    }
    Node *temp = l->tail;
    l->tail = l->tail->prev;
    l->tail->next = l->head;
    l->size--;
    int res = temp->data;
    free(temp);
    return res;
}

void insert_after(List *l,int val,int target){
    Node *temp = l->head;
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    while(temp->data != target){
        temp = temp->next;
    }
     if (temp->data == target){

        temp->next = newnode;
        newnode->prev = temp;
        newnode->next = temp->next->next;
    }
    free(temp);
    l->size++;
}


void insert_infront(List *l,int val,int target){
    Node *temp = l->tail;
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    while(temp->data != target){
        temp = temp->prev;
    }
     if (temp->data == target){
        temp->prev = newnode;
        newnode->next = temp;
    }
    free(temp);
    l->size++;
}
