
#define MAX_SIZE 100


typedef struct{
    int data[MAX_SIZE];
    int size;
    int head;
}Deque;

void init(Deque *d){
    d->size = 0;
    d->head = 0;
}

bool is_empty(Deque *d){
    if (d->size == 0){
        return true;
    }
    return false;
}

void destroy(Deque *d){
    d->size = 0;
}

bool push_back(Deque *d, int val){
    if (d->size >= MAX_SIZE){
        return false;
    }
    d->data[(d->size + d->head) % MAX_SIZE] = val;
    d->size++;
    return true;
}

int pop_back(Deque *d){
    if (is_empty(d)){
        return -1;
    }
    int val = d->data[(d->size - 1 + d->head) % MAX_SIZE];
    d->size--;
    return val;
}

bool push_front(Deque *d, int val){
    if (d->size >= MAX_SIZE){
        return false;
    }
    d->head = (d->head - 1 + MAX_SIZE) % MAX_SIZE;
    d->data[d->head] = val;
    d->size++;
    return true;
}

int pop_front(Deque *d){
    if (is_empty(d)){
        return -1;
    }
    int val = d->data[d->head];
    d->head = (d->head + 1) % MAX_SIZE;
    d->size--;
    return val;
}