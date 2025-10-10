#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

typedef struct{
    Node *head, *tail;
    int size;
} List;

void init(List *l){
    l->head = l->tail = NULL;
    l->size = 0;
}

bool is_empty(List *l){
    return l->size == 0;
}

void push_back(List *l, int val){
    Node *n = malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    if (l->tail) l->tail->next = n;
    else l->head = n;
    l->tail = n;
    l->size++;
}

void push_front(List *l, int val){
    Node *n = malloc(sizeof(Node));
    n->data = val;
    n->next = l->head;
    l->head = n;
    if (l->tail == NULL) l->tail = n;
    l->size++;
}

int pop_front(List *l){
    if (is_empty(l)) return -1;
    Node *t = l->head;
    int val = t->data;
    l->head = t->next;
    if (l->head == NULL) l->tail = NULL;
    free(t);
    l->size--;
    return val;
}

bool insert_after(List *l, int target, int val){
    Node *cur = l->head;
    while (cur && cur->data != target)
        cur = cur->next;
    if (!cur) return false; // не нашли target
    Node *n = malloc(sizeof(Node));
    n->data = val;
    n->next = cur->next;
    cur->next = n;
    if (cur == l->tail) l->tail = n;
    l->size++;
    return true;
}

void print(List *l){
    for (Node *p = l->head; p; p = p->next)
        printf("%d ", p->data);
    printf("\n");
}

int main(){
    List l; init(&l);
    push_back(&l, 1);
    push_back(&l, 2);
    push_front(&l, 0);
    insert_after(&l, 1, 5);
    print(&l);
}
