#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Item {
    int data;
    struct Item *next;
    struct Item *prev;
} Item;

typedef struct deque {
    Item *left;
    Item *right;
    int size;
} deque;

// Создание дека
deque *CreateDeque() {
    deque *d = (deque*)malloc(sizeof(deque));
    d->size = 0;
    d->left = NULL;
    d->right = NULL;
    return d;
}

// Проверка пустоты
bool isEmptyDeque(deque *d) {
    return d->size == 0;
}

// Добавить элемент с левого конца
bool PushLeftDeque(deque *d, int i) {
    Item *q = NULL;
    if (d->left != NULL) {
        q = d->left;
        d->left = d->left->prev;
    }
    
    d->left = (Item*)malloc(sizeof(Item));
    d->left->data = i;
    d->left->next = q;
    
    if (d->left->next != NULL)
        d->left->next->prev = d->left;
    
    d->left->prev = NULL;
    
    if (q == NULL)
        d->right = d->left;
    
    d->size++;
    return true;
}

// Добавить элемент с правого конца
bool PushRightDeque(deque *d, int i) {
    Item *q = NULL;
    if (d->right != NULL) {
        q = d->right;
        d->right = d->right->next;
    }
    
    d->right = (Item*)malloc(sizeof(Item));
    d->right->data = i;
    d->right->next = NULL;
    d->right->prev = q;
    
    if (d->right->prev != NULL)
        d->right->prev->next = d->right;
    
    if (q == NULL)
        d->left = d->right;
    
    d->size++;
    return true;
}

// Взять элемент с левого конца
bool PopLeftDeque(deque *d) {
    if (isEmptyDeque(d))
        return false;
    
    Item *q = d->left->next;
    free(d->left);
    d->size--;
    d->left = q;
    
    if (d->size == 0) {
        d->right = d->left;
    }
    
    if (d->left != NULL)
        d->left->prev = NULL;
    
    return true;
}

// Взять элемент с правого конца
bool PopRightDeque(deque *d) {
    if (isEmptyDeque(d))
        return false;
    
    Item *q = d->right->prev;
    free(d->right);
    d->size--;
    d->right = q;
    
    if (d->size == 0) {
        d->left = d->right;
    }
    
    if (d->right != NULL)
        d->right->next = NULL;
    
    return true;
}

// Посмотреть элемент с левого конца
int TopLeftDeque(deque *d) {
    if (isEmptyDeque(d))
        return -1;
    return d->left->data;
}

// Посмотреть элемент с правого конца
int TopRightDeque(deque *d) {
    if (isEmptyDeque(d))
        return -1;
    return d->right->data;
}

// Удалить дек
void DeleteDeque(deque *d) {
    while (!isEmptyDeque(d)) {
        PopLeftDeque(d);
    }
    free(d);
}

// Тестирование
int main() {
    deque *d = CreateDeque();
    
    PushLeftDeque(d, 10);
    PushRightDeque(d, 20);
    PushLeftDeque(d, 5);
    PushRightDeque(d, 30);
    
    printf("Left: %d\n", TopLeftDeque(d)); // 5
    printf("Right: %d\n", TopRightDeque(d)); // 30
    
    PopLeftDeque(d);
    printf("After pop left: %d\n", TopLeftDeque(d)); // 10
    
    PopRightDeque(d);
    printf("After pop right: %d\n", TopRightDeque(d)); // 20
    
    DeleteDeque(d);
    return 0;
}