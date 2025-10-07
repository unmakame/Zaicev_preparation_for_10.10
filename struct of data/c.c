// вектор - на динамических струкрутах (возвращать с индексом v->size - 1, а добавлять просто по размеру) - написал
// щчередь на файле(открывать файл в режиме "w+b") - написал
// очередь на массиве - norm
// очередь на динамических структурах - НАПИСАЛ НОРМАЛЬНО (typedef struct Node Node; и потом struct Node{};)
// стек на файле - push - (писать в позицию size,pop - читать из позиции size-1)
// стек на динамических структурах - ЗАККОМЕНТИРОВАЛ - ЗАВТРА ПОВТОРИТЬ 
// стек на массиве - norm


// это дописать затвра утром
// дек на массиве - ошибки были толко в проверках при вставке на наличие head или tail(dopisal)
// двоичное дерево на массиве - не забывать про проверку на выход за границы индексов(dopical)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// typedef struct Node Node;

// struct Node{
//     int data;
//     Node *next;
//     Node *prev;
// };

// typedef struct{
//     int size;
//     Node *head;
// }Stack;


// void init(Stack *s){
//     s->size = 0;
//     s->head = NULL;
// }

// bool is_empty(Stack *s){
//     if (s->size == 0){
//         return true;
//     }
//     return false;
// }

// void push(Stack *s, int val){
//     Node *newnode = (Node*)malloc(sizeof(Node));
//     newnode->data = val;
//     newnode->next = NULL;
//     newnode->prev = s->head;

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
//     int val = temp->data;
//     s->head = s->head->prev;

//     if (s->head != NULL){
//         s->head->next = NULL;
//     }

//     free(temp);
//     s->size--;
//     return val;
// }

