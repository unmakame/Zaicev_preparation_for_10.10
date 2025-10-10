#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



#define MAX_SIZE 100

typedef struct{
    FILE *file;
    int size;
    int head;
}Queue;

void init(Queue *q,const char *filename){
    FILE *file = fopen(filename,"w+b");
    q->file = file;
    q->size = 0;
    q->head = 0;
}

bool is_empty(Queue *q){
    if (q->size == 0){
        return true;
    }
    return false;
}

bool is_full(Queue *q){
    if (q->size >= MAX_SIZE){
        return true;
    }
    return false;
}


bool push_back(Queue *q, int data){
    if (is_full(q)){
        return false;
    }
    fseek(q->file,((q->head + q->size) % MAX_SIZE) * sizeof(int),SEEK_SET);
    fwrite(&data,sizeof(int),1,q->file);
    q->size++;
    return true;
}

int pop_front(Queue *q){
    if (is_empty(q)){
        return -1;
    }
    int data;
    fseek(q->file,((q->head) % MAX_SIZE) * sizeof(int),SEEK_SET);
    fread(&data,sizeof(int),1,q->file);
    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;
    return data;
}

int get_first(Queue *q){
    if (is_empty(q)){
        return -1;
    }
    int first;
    fseek(q->file,((q->head) % MAX_SIZE) * sizeof(int),SEEK_SET);
    fread(&first,sizeof(int),1,q->file);
    return first;
}

void destroy(Queue *q){
    fclose(q->file);
    q->size = 0;
    q->head = 0;
}