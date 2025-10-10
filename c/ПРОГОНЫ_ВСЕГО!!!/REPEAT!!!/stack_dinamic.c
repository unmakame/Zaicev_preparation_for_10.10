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
    int size;
}Stack;

void init(Stack *s){
    s->head = NULL;
    s->size = 0;
}

bool is_empty(Stack *s){
    if(s->size == 0){
        return true;
    }
    return false;
}

int size(Stack *s){
    return s->size;
}


void push(Stack *s, int val){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->prev = s->head;
    newnode->next = NULL;
    if(s->head != NULL){
        s->head->next = newnode;
    }
    s->head = newnode;
    s->size++;
}

int pop(Stack *s){
    if(is_empty(s)){
        return -1;
    }
    Node *temp = s->head;
    int first = temp->data;
    s->head = s->head->prev;

    if (s->head != NULL){
        s->head->next = NULL;
    }
    free(temp);
    s->size--;
    return first;
}

int first(Stack *s){
    if (is_empty(s)){
        return -1;
    }
    return s->head->data;
}


void destroy(Stack *s){
    while (!is_empty(s)){
        pop(s);
    }
}























// typedef struct Node Node;

// struct Node{
//     Node *next;
//     Node *prev;
//     int data;
// };

// typedef struct{
//     Node *head;
//     int size;
// }Stack;


// void init(Stack *s){
//     s->head = NULL;
//     s->size = 0;
// }

// bool is_empty(Stack *s){
//     if (s->size == 0){
//         return true;
//     }
//     return false;
// }

// int get_size(Stack *s){
//     return s->size;
// }

// void push(Stack *s, int val){
//     Node *newnode = (Node*)malloc(sizeof(Node));
//     newnode->data = val;
//     newnode->prev = s->head;
//     newnode->next = NULL;

//     if (s->head != NULL){
//         s->head->next = newnode;
//     }
//     s->head = newnode;
//     s->size++;
// }

// int pop(Stack *s){
//     if (is_empty(s)){
//         return -1;
//     }
//     Node *temp = s->head;
//     int rez = temp->data;
//     s->head = s->head->prev;
//     if (s->head != NULL){
//         s->head->next = NULL;
//     }
//     free(temp);
//     s->size--;
//     return rez;
// }

// void destroy(Stack *s){
//     while (!is_empty(s)){
//         pop(s);
//     }
// }