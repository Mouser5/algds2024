#pragma once

typedef struct Treap {
    int key;
    int priority;
    struct Treap* left;
    struct Treap* right;
} Treap;

int InsTest(int key, int priorit);
int DelTest(int key);