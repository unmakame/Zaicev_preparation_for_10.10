#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;  // Достаточно только head
    int size;
} List;

void init(List *l) {
    l->head = NULL;
    l->size = 0;
}

// Вставка в пустой список
void push_empty(List *l, int val) {
    Node *new = malloc(sizeof(Node));
    new->data = val;
    new->next = new;
    new->prev = new;
    l->head = new;
    l->size++;
}

// Вставка ПОСЛЕ target (единственная нужная операция)
void insert_after(List *l, Node *target, int val) {
    Node *new = malloc(sizeof(Node));
    new->data = val;
    
    new->next = target->next;
    new->prev = target;
    target->next->prev = new;
    target->next = new;
    
    l->size++;
}

// Вставка ДО target (через after)
void insert_before(List *l, Node *target, int val) {
    insert_after(l, target->prev, val);  // Вставляем после предыдущего
}

// Вставка в начало
void push_front(List *l, int val) {
    if (l->head == NULL) push_empty(l, val);
    else insert_before(l, l->head, val);
}

// Вставка в конец  
void push_back(List *l, int val) {
    if (l->head == NULL) push_empty(l, val);
    else insert_before(l, l->head, val);  // Перед head = конец
}