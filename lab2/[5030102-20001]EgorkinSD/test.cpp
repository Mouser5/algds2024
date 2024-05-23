#include "pch.h"
#include "C:\Users\overw\One Drive1\Рабочий стол\Progs\[5030102-20001]EgorkinSD\Func.c"

int InsTest(int key, int priorit) {
    int keys[] = { 0, 1, 2, 3, 4, 13, 6, 7, 8, 9 };
    int priority[] = { 20, 53, 4, 5, 16, 7, 8, 9, 10, 11 };
    Treap* treap = NULL;
    for (int i = 0; i < 10; i++) {
        insert(&treap, keys[i], priority[i]);
    }
    insert(&treap, key, priorit);
    return(treap->right->left->left->key);
}

int DelTest(int key) {
    int keys[] = { 0, 1, 2, 3, 4, 13, 6, 7, 8, 9 };
    int priority[] = { 20, 53, 4, 5, 16, 7, 8, 9, 10, 11 };
    Treap* treap = NULL;
    for (int i = 0; i < 10; i++) {
        insert(&treap, keys[i], priority[i]);
    }
    Delete(&treap, key);
    return(treap->right->left->key);
}

TEST(TestCaseName, Ins) {
  EXPECT_EQ(3, InsTest(3,10));
  EXPECT_TRUE(true);
}

TEST(TestCaseName, Ins2) {
    EXPECT_EQ(2, InsTest(4, 10));
    EXPECT_TRUE(true);
}

TEST(TestCaseName, Del) {
	EXPECT_EQ(2, DelTest(3));
	EXPECT_TRUE(true);
}

TEST(TestCaseName, Del2) {
    EXPECT_EQ(3, DelTest(13));
    EXPECT_TRUE(true);
}
