#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
    Node *next;
    Node *prev;
    int data;
};

typedef struct {
    Node *head;
    Node *tail;
    Node *current;
    int size;
} List;

void init(List *l) {
    l->head = NULL;
    l->tail = NULL;
    l->current = NULL;
    l->size = 0;
}

bool is_empty(List *l) {
    return l->head == NULL;
}

int first(List *l) {
    if (is_empty(l)) return -1;
    return l->head->data;
}

int last(List *l) {
    if (is_empty(l)) return -1;
    return l->tail->data;
}

void next(List *l) {
    if (is_empty(l)) return;
    l->current = l->current->next;
}

void prev(List *l) {
    if (is_empty(l)) return;
    l->current = l->current->prev;
}

int return_next_to_target(List *l, int target) {
    if (is_empty(l)) return -1;
    
    Node *temp = l->head;
    do {
        if (temp->data == target) {
            return temp->next->data;
        }
        temp = temp->next;
    } while (temp != l->head);
    
    return -1;
}

int return_prev_to_target(List *l, int target) {
    if (is_empty(l)) return -1;
    
    Node *temp = l->head;
    do {
        if (temp->data == target) {
            return temp->prev->data;
        }
        temp = temp->next;
    } while (temp != l->head);
    
    return -1;
}

void insert_in_front(List *l, int val, int target) {
    if (is_empty(l)) return;
    
    Node *temp = l->head;
    do {
        if (temp->data == target) {
            Node *newnode = (Node*)malloc(sizeof(Node));
            newnode->data = val;
            
            // Вставка ПЕРЕД target
            newnode->prev = temp->prev;
            newnode->next = temp;
            
            temp->prev->next = newnode;
            temp->prev = newnode;
            
            if (temp == l->head) {
                l->head = newnode;
            }
            
            l->size++;
            return;
        }
        temp = temp->next;
    } while (temp != l->head);
}

void insert_behind(List *l, int val, int target) {
    if (is_empty(l)) return;
    
    Node *temp = l->head;
    do {
        if (temp->data == target) {
            Node *newnode = (Node*)malloc(sizeof(Node));
            newnode->data = val;
            
            // Вставка ПОСЛЕ target
            newnode->prev = temp;
            newnode->next = temp->next;
            
            temp->next->prev = newnode;
            temp->next = newnode;
            
            if (temp == l->tail) {
                l->tail = newnode;
            }
            
            l->size++;
            return;
        }
        temp = temp->next;
    } while (temp != l->head);
}

void delete(List *l, int target) {
    if (is_empty(l)) return;
    
    Node *temp = l->head;
    do {
        if (temp->data == target) {
            if (l->size == 1) {
                // Единственный элемент
                free(temp);
                l->head = NULL;
                l->tail = NULL;
                l->current = NULL;
            } else {
                // Обновляем связи соседей
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                
                if (temp == l->head) l->head = temp->next;
                if (temp == l->tail) l->tail = temp->prev;
                if (temp == l->current) l->current = temp->next;
                
                free(temp);
            }
            
            l->size--;
            return;
        }
        temp = temp->next;
    } while (temp != l->head);
}

// Вставка в пустой список
void insert_first(List *l, int val) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = newnode;
    newnode->prev = newnode;
    
    l->head = newnode;
    l->tail = newnode;
    l->current = newnode;
    l->size = 1;
}

// Пример использования
void print_list(List *l) {
    if (is_empty(l)) {
        printf("Список пуст\n");
        return;
    }
    
    Node *temp = l->head;
    printf("Список: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != l->head);
    printf("\n");
}

int main() {
    List list;
    init(&list);
    
    insert_first(&list, 10);
    insert_behind(&list, 20, 10);  // 10 → 20
    insert_behind(&list, 30, 20);  // 10 → 20 → 30
    insert_in_front(&list, 5, 10); // 5 → 10 → 20 → 30
    
    print_list(&list);
    
    printf("Следующий после 10: %d\n", return_next_to_target(&list, 10));
    printf("Предыдущий для 10: %d\n", return_prev_to_target(&list, 10));
    
    delete(&list, 10);
    print_list(&list);
    
    return 0;
}