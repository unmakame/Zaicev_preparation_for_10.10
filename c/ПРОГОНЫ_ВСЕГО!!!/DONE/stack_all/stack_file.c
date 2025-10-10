#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 100

typedef struct{
    FILE *file;
    int size;
}Stack;

void init(Stack *s, const char *filename){
    FILE *file = fopen(filename,"w+b");
    s->file = file;
    s->size = 0;
}

bool is_empty(Stack *s){
    if (s->size == 0){
        return true;
    }
    return false;
}

int get_size(Stack *s){
    if (is_empty(s)){
        return 0;
    }
    return s->size;
}

bool is_full(Stack *s){
    if (s->size >= MAX_LEN){
        return true;
    }
    return false;
}


bool push_front(Stack *s, int data){
    if (is_full(s)){
        return false;
    }
    fseek(s->file,s->size * sizeof(int),SEEK_SET);
    fwrite(&data,sizeof(int),1,s->file);
    s->size++;
    return true;
}

int pop_first(Stack *s){
    if (is_empty(s)){
        return -1;
    }
    int first;
    fseek(s->file,(s->size - 1) * sizeof(int),SEEK_SET);
    fread(&first,sizeof(int),1,s->file);
    s->size--;
    return first;
}

int get_first(Stack *s){
     if (is_empty(s)){
        return -1;
    }
    int first;
    fseek(s->file,(s->size - 1) * sizeof(int),SEEK_SET);
    fread(&first,sizeof(int),1,s->file);
    return first;
}

void destroy(Stack *s){
    fclose(s->file);
    s->file = NULL;
    s->size = 0;
}