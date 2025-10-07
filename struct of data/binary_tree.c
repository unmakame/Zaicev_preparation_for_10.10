#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct{
    int data[MAXSIZE];
    int size;
}Tree;

void init(Tree *t){
    t->size = 0;
    for(int i = 0; i < MAXSIZE; i++) {
        t->data[i] = -1;  // ← ИНИЦИАЛИЗАЦИЯ
    }
}

bool is_empty(Tree *t){
    return t->size == 0;
}

bool insert_root(Tree *t, int val){
    if (t->size >= MAXSIZE) return false;
    if (t->data[0] != -1) return false;
    t->data[0] = val;
    t->size++;
    return true;
}

bool insert_left(Tree *t, int parent_index, int val){
    if (t->size >= MAXSIZE) return false;
    int left_index = 2 * parent_index + 1;
    if (left_index >= MAXSIZE) return false;  // ← ГРАНИЦЫ
    if (t->data[left_index] != -1) return false;
    t->data[left_index] = val;
    t->size++;
    return true;
}

bool insert_right(Tree *t, int parent_index, int val){
    if (t->size >= MAXSIZE) return false;
    int right_index = 2 * parent_index + 2;
    if (right_index >= MAXSIZE) return false;  // ← ГРАНИЦЫ
    if (t->data[right_index] != -1) return false;
    t->data[right_index] = val;
    t->size++;
    return true;
}

int get_left(Tree *t, int parent_index){
    int left_index = 2 * parent_index + 1;
    if (left_index >= MAXSIZE) return -1;
    
    return t->data[left_index];
}

int get_right(Tree *t, int parent_index){
    int right_index = 2 * parent_index + 2;
    if (right_index >= MAXSIZE) return -1;
    return t->data[right_index];
}

int get_parent(Tree *t, int child_index){
    if (child_index == 0) return -1;
    int parent_index = (child_index - 1) / 2;
    if (parent_index >= MAXSIZE) return -1;
    return t->data[parent_index];
}

void destroy(Tree *t){
    t->size = 0;
}