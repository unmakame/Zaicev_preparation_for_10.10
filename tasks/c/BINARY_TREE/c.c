#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node{
    Node *left;
    Node *right;
    int data;
};

typedef struct{
    int size;
    Node *root;
}Tree;

void init(Tree *t){
    t->size = 0;
    t->root = NULL;
}

bool is_empty(Tree *t){
    return t->root == NULL;
}

bool insert_root(Tree *t, int val){
    if (!is_empty(t)){
        return false;
    }
    
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;

    t->root = newnode;
    t->size++;
    return true;
}

bool insert_lest(Tree *t,Node *parent, int val){
    if (parent == NULL || parent->left != NULL){
        return false;
    }
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    parent->left = newnode;

    t->size++;
    return true;
}

bool insert_right(Tree *t, Node *parent, int val){
    if (parent == NULL || parent->right != NULL){
        return false;
    }
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->left = NULL;
    newnode->right = NULL;
    parent->right = newnode;

    t->size++;
    return true;
}

void destroy_subtree(Node *node){
    if (node == NULL){
        return;
    }
    destroy_subtree(node->left);
    destroy_subtree(node->right);
    free(node);
}

void destroy_tree(Tree *t){
    destroy_subtree(t->root);
    t->root = NULL;
    t->size = 0;
}

void preorder(Node *node){
    if (node == NULL){
        return;
    }
    printf("%d",node->data);
    preorder(node->left);
    preorder(node->right);
}