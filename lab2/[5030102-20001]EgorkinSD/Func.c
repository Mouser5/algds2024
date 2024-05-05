#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "Header.h"
#include <stdlib.h>


Treap* create_treap(int key, int priority) {
    Treap* temp_treap = NULL;
    temp_treap = malloc(sizeof(Treap));
    temp_treap->key = key;
    temp_treap->priority = priority;
    temp_treap->left = NULL;
    temp_treap->right = NULL;
    return temp_treap;
}

Treap* rotate_right(Treap* node) {
    Treap* left_child = node->left;
    node->left = left_child->right;
    left_child->right = node;
    return left_child;
}

Treap* rotate_left(Treap* node) {
    Treap* right_child = node->right;
    node->right = right_child->left;
    right_child->left = node;
    return right_child;
}

void insert(Treap** root, int key, int priority) {
    if (*root == NULL) {
        *root = create_treap(key, priority);
        return;
    }

    if (key < (*root)->key) {
        insert(&(*root)->left, key, priority);
        if ((*root)->left->priority > (*root)->priority) {
            *root = rotate_right(*root);
        }
    }
    else {
        insert(&(*root)->right, key, priority);
        if ((*root)->right->priority > (*root)->priority) {
            *root = rotate_left(*root);
        }
    }
}

void Delete(Treap** root, int key) {
    if (*root == NULL) {
        return;
    }

    if (key < (*root)->key) {
        Delete(&(*root)->left, key);
    }
    else if (key > (*root)->key) {
        Delete(&(*root)->right, key);
    }
    else {
        if ((*root)->left == NULL) {
            *root = (*root)->right;
        }
        else if ((*root)->right == NULL) {
            *root = (*root)->left;
        }
        else {
            if ((*root)->left->priority > (*root)->right->priority) {
                *root = rotate_right(*root);
                Delete(&(*root)->right, key);
            }
            else {
                *root = rotate_left(*root);
                Delete(&(*root)->left, key);
            }
        }
    }
}


int InsTest(int key, int priorit) {
    int keys[] = { 0, 1, 2, 3, 4, 13, 6, 7, 8, 9 };
    int priority[] = { 20, 53, 4, 5, 16, 7, 8, 9, 10, 11 };
    Treap* treap = NULL;
    for (int i = 0; i < 10; i++) {
        insert(&treap, keys[i], priority[i]);
    }
    insert(&treap, key, priorit);
    printf("%d", treap->right->left->left->left->key);
    return(treap->right->left->left->left->key);
}

int DelTest(int key) {
    int keys[] = { 0, 1, 2, 3, 4, 13, 6, 7, 8, 9 };
    int priority[] = { 20, 53, 4, 5, 16, 7, 8, 9, 10, 11 };
    Treap* treap = NULL;
    for (int i = 0; i < 10; i++) {
        insert(&treap, keys[i], priority[i]);
    }
    Delete(&treap, key);
    printf("%d", treap->right->left->key);
    return(treap->right->left->key);
}