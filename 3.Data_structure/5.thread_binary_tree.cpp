/*************************************************************************
	> File Name: 5.thread_binary_tree.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 日  2/ 6 11:50:52 2022
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define NORMAL 0
#define THREAD 1
using namespace std;


typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->ltag = p->rtag = NORMAL;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (root->key == key) return root;
    if (root->key < key) root->rchild = insert(root->rchild, key);
    else root->lchild = insert(root->lchild, key);
    return root;
}

void build_thread(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL; //trick : 记录上一个处理的最后一个节点，方便建立前驱后继关系
    build_thread(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAD;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAD;
    }
    pre = root;
    build_thread(root->rchild);
    return ;
}

void inorder(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) inorder(root->lchild);
    printf("%d ", root->key);
    if (root->rtag == NORMAL) inorder(root->rchild);
    return ;
}

Node *findLeft(Node *p) {
    while (p && p->ltag == NORMAL && p->lchild) p = p->lchild;
    return p;
}

void output(Node *root) {
    Node *p = findLeft(root);
    while (p) {
        printf("%d ", p->key);
        if (p->rtag == THREAD) {
            p = p->rchild;
        } else {
            p = findLeft(p->rchild);
        }
    }
    printf("\n");
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    if (root->ltag == NORMAL) clear(root->lchild);
    if (root->rtag == NORMAL) clear(root->rchild);
    free(root);
    return ;
}

int main() {
    srand(time(0));
    #define MAX_OP 20
    Node *root = NULL;
    for (int i = 0; i < MAX_OP; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    inorder(root);
    printf("\n");
    output(root);
    clear(root);
    return 0;
}

