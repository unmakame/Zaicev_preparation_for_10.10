#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} List;

void init(List *l) {
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

bool is_empty(List *l) {
    return l->head == NULL;
}

// Вставка в начало
void push_front(List *l, int val) {
    Node *new = malloc(sizeof(Node));
    new->data = val;
    new->next = l->head;
    new->prev = NULL;
    
    if (l->head != NULL) l->head->prev = new;
    else l->tail = new;
    
    l->head = new;
    l->size++;
}

// Вставка в конец
void push_back(List *l, int val) {
    Node *new = malloc(sizeof(Node));
    new->data = val;
    new->next = NULL;
    new->prev = l->tail;
    
    if (l->tail != NULL) l->tail->next = new;
    else l->head = new;
    
    l->tail = new;
    l->size++;
}

// Удаление с начала
int pop_front(List *l) {
    if (is_empty(l)) return -1;
    
    Node *temp = l->head;
    int val = temp->data;
    
    l->head = l->head->next;
    if (l->head != NULL) l->head->prev = NULL;
    else l->tail = NULL;
    
    free(temp);
    l->size--;
    return val;
}

// Удаление с конца
int pop_back(List *l) {
    if (is_empty(l)) return -1;
    
    Node *temp = l->tail;
    int val = temp->data;
    
    l->tail = l->tail->prev;
    if (l->tail != NULL) l->tail->next = NULL;
    else l->head = NULL;
    
    free(temp);
    l->size--;
    return val;
}

// Вставка ПОСЛЕ target
void insert_after(List *l, Node *target, int val) {
    Node *new = malloc(sizeof(Node));
    new->data = val;
    new->next = target->next;
    new->prev = target;
    
    if (target->next != NULL) 
        target->next->prev = new;
    else 
        l->tail = new;  // Если вставляем в конец
    
    target->next = new;
    l->size++;
}

// Вставка ДО target  
void insert_before(List *l, Node *target, int val) {
    Node *new = malloc(sizeof(Node));
    new->data = val;
    new->next = target;
    new->prev = target->prev;
    
    if (target->prev != NULL)
        target->prev->next = new;
    else
        l->head = new;  // Если вставляем в начало
    
    target->prev = new;
    l->size++;
}

// Поиск узла по значению (для использования с insert)
Node* find_node(List *l, int val) {
    Node *cur = l->head;
    while (cur != NULL) {
        if (cur->data == val) return cur;
        cur = cur->next;
    }
    return NULL;
}
