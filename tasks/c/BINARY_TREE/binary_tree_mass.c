#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SIZE 100


typedef struct{
    int data[MAX_SIZE];
    int size;
}Tree;


void init(Tree * t){
    t->size = 0;
}

bool is_empty(Tree * t){
    if (t->size == 0){
        return true;
    }
    return false;
}

bool is_full(Tree * t){
    if (t->size >= MAX_SIZE){
        return true;
    }
    return false;
}

bool insert_left(Tree * t, int parent_index, int val){
    if (is_full(t)){
        return false;
    }
    int left_index = parent_index * 2 + 1;
    if(left_index >= MAX_SIZE){
        return false;
    }
    t->data[left_index] = val;
    t->size++;
    return true;
}

bool insert_right(Tree * t, int parent_index, int val){
    if (is_full(t)){
        return false;
    }
    int right_index = parent_index * 2 + 2;
    if(right_index >= MAX_SIZE){
        return false;
    }
    t->data[right_index] = val;
    t->size++;
    return true;
}

int get_parent(Tree * t,int child_index){
    if (is_empty(t)){
        return -1;
    }
    int parent_index = (child_index - 1) / 2;
    return t->data[parent_index];
}


int get_left(Tree * t, int parent_index){
    if (is_empty(t)){
        return -1;
    }
    int left_index = parent_index * 2 + 1;
    int val = t->data[left_index];
    return val;
}

int get_right(Tree * t, int parent_index){
    if (is_empty(t)){
        return -1;
    }
    int right_index = parent_index * 2 + 2;
    int val = t->data[right_index];
    return val;
}

void insert_root(Tree *t, int val){
    t->data[0] = val;
    t->size++;
}