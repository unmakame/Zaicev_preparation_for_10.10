#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 50
 
typedef struct {
    int data[MAX_SIZE];
    int size;  // количество элементов в стеке
} Stack;

// 1. СОЗДАТЬ: инициализация стека
void create(Stack *s) {
    s->size = 0;
}

// 2. ПУСТО: проверка, пуст ли стек
bool is_empty(Stack *s) {
    return s->size == 0;
}

// 3. ГЛУБИНА: возвращает количество элементов в стеке
int depth(Stack *s) {
    return s->size;
}

// 4. В СТЕК: добавляет элемент на вершину стека
bool push(Stack *s, int value) {
    if (s->size >= MAX_SIZE) {
        // стек переполнен
        return false;
    }
    s->data[s->size++] = value;
    return true;
}

// 5. ИЗ СТЕКА: удаляет элемент с вершины стека и возвращает его через указатель
bool pop(Stack *s, int *value) {
    if (s->size == 0) {
        // стек пуст
        return false;
    }
    s->size--;
    *value = s->data[s->size];
    return true;
}

// 6. ВЕРХ: возвращает элемент на вершине стека без удаления
bool top(Stack *s, int *value) {
    if (s->size == 0) {
        return false;
    }
    *value = s->data[s->size - 1];
    return true;
}

// 7. УНИЧТОЖИТЬ: делает стек пустым
void destroy(Stack *s) {
    s->size = 0;
}

// Для теста
int main() {
    Stack s;
    create(&s);

    printf("Стек пуст? %s\n", is_empty(&s) ? "Да" : "Нет");

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Глубина стека: %d\n", depth(&s));

    int val;
    if (top(&s, &val)) printf("Вершина стека: %d\n", val);

    if (pop(&s, &val)) printf("Извлечено из стека: %d\n", val);
    if (pop(&s, &val)) printf("Извлечено из стека: %d\n", val);

    printf("Глубина после извлечений: %d\n", depth(&s));

    destroy(&s);
    printf("Стек пуст после уничтожения? %s\n", is_empty(&s) ? "Да" : "Нет");

    return 0;
}
