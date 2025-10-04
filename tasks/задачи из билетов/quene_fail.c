#include <stdio.h>
#include <stdbool.h>

#define POOL_SIZE 50

typedef struct{
    FILE *file;
    int size;
    int head;
    int max_size;
} Quene;

void init(Quene *q, const char *filename){
    FILE *file = fopen(filename,"w+b");
    q->size = 0;
    q->head = 0;
    q->file = file;
    q->max_size = POOL_SIZE;
}

void destroy(Quene *q){
    q->size = 0;
    fclose(q->file);
}

bool is_empty(Quene *q){
    return q->size ==0;
}

bool push_back(Quene *q, int val){
    if (q->size == q->max_size){
        return false;
    }
    fseek(q->file,((q->size +q->head) % q->max_size) * sizeof(int),SEEK_SET);
    fwrite(&val,sizeof(int),1,q->file);
    q->size++;
    return true;
}


int pop_front(Quene *q){
    if (is_empty(q)){
        return -1;
    }
    int val;
    fseek(q->file,q->head * sizeof(int),SEEK_SET);
    fread(&val,sizeof,1,q->size);
    q->head = (q->head + 1) % q->max_size;
    q->size--;
    return val;
}