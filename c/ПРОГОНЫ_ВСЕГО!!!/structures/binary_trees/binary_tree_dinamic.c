#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
    int data;
    Node *first_child;  // первый потомок
    Node *next_sibling; // следующий брат
};

typedef struct {
    Node *root;
    int size;
} Tree;
bool add_child(Node *parent, int val) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    
    if (parent->first_child == NULL) {
        parent->first_child = new_node;
    } else {
        Node *current = parent->first_child;
        while (current->next_sibling != NULL) {
            current = current->next_sibling;
        }
        current->next_sibling = new_node;
    }
    return true;
}
bool insert_root(Tree *t, int val) {
    if (!is_empty(t)) return false;
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = val;
    new_node->first_child = NULL;
    new_node->next_sibling = NULL;
    t->root = new_node;
    t->size++;
    return true;
}
bool insert_child(Tree *t, int parent_val, int val) {
    if (is_empty(t)) return false;
    Node *stack[100];
    int top = 0;
    stack[top++] = t->root;
    while (top > 0) {
        Node *current = stack[--top];
        if (current->data == parent_val) {
            add_child(current, val);
            t->size++;
            return true;
        }
        Node *child = current->first_child;
        while (child != NULL) {
            stack[top++] = child;
            child = child->next_sibling;
        }
    }
    return false;
}

// Поиск
bool search(Node *node, int val) {
    if (node == NULL) return false;
    if (node->data == val) return true;
    
    Node *child = node->first_child;
    while (child != NULL) {
        if (search(child, val)) return true;
        child = child->next_sibling;
    }
    return false;
}

bool find(Tree *t, int val) {
    return search(t->root, val);
}

// Вывод дерева
void print_tree(Node *node, int level) {
    if (node == NULL) return;
    
    for (int i = 0; i < level; i++) printf("  ");
    printf("%d\n", node->data);
    
    Node *child = node->first_child;
    while (child != NULL) {
        print_tree(child, level + 1);
        child = child->next_sibling;
    }
}

void print(Tree *t) {
    print_tree(t->root, 0);
}

// Очистка
void clear(Node *node) {
    if (node == NULL) return;
    
    Node *child = node->first_child;
    while (child != NULL) {
        Node *next = child->next_sibling;
        clear(child);
        child = next;
    }
    free(node);
}

void destroy(Tree *t) {
    clear(t->root);
    t->root = NULL;
    t->size = 0;
}