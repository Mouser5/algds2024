#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


typedef struct Treap {
    int key;
    int priority;
    struct Treap* left;
    struct Treap* right;
} Treap;

Treap* create_treap(int key, int priority) {
    Treap* temp_treap = malloc(sizeof(Treap));
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

void delete(Treap** root, int key) {
    if (*root == NULL) {
        return;
    }

    if (key < (*root)->key) {
        delete(&(*root)->left, key);
    }
    else if (key > (*root)->key) {
        delete(&(*root)->right, key);
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
                delete(&(*root)->right, key);
            }
            else {
                *root = rotate_left(*root);
                delete(&(*root)->left, key);
            }
        }
    }
}

int x = 0, temp = 0;
int PrintTree(Treap* tree, int y)
{
    if (tree != NULL)
    {
        PrintTree(tree->left, y + 1);
        if (y > temp)
            temp = y;
        gotoxy(x, y);
        printf("(%d, %d)", tree->key,tree->priority);

        x+=8;
        PrintTree(tree->right, y + 1);
    }
    return (temp);
}

int main() {
    int keys[] = { 0, 1, 2, 3, 4, 13, 6, 7, 8, 9 };
    int priority[] = { 20, 53, 4, 5, 16, 7, 8, 9, 10, 11 };
    Treap* treap = NULL;
    for (int i = 0; i < 10; i++) {
        insert(&treap, keys[i], priority[i]);
    }
    insert(&treap, 3, 12);
    delete(&treap, 8);
    //printf("%d",treap->right->left->key);
    int temp = PrintTree(treap, 1);
    x = 0;
    gotoxy(0, temp);
    return 0;
}
