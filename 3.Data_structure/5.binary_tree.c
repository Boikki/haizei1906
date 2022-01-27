/*************************************************************************
	> File Name: 5.binary_tree.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三  1/26 11:19:45 2022
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->rchild = p->lchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->n = 0;
    tree->root = NULL;
    return tree;
}

Node *insertNode(Node *root, int val, int *ret) {
    if (root == NULL) {
        *ret = 1;
        return getNewNode(val);
    }
    if (root->val == val) return root;
    if (root->val > val) root->lchild = insertNode(root->lchild, val, ret);
    else root->rchild = insertNode(root->rchild, val, ret);
    return root;
}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insertNode(tree->root, val, &flag);
    tree->n += flag;
    return ;
}

void clearNode(Node *node) {
    if (node == NULL) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
}

void clearTree(Tree *tree) {
    clearNode(tree->root);
    free(tree);
    return ;
}

void outputNode(Node *node) {
    if (node == NULL) return ;
    printf("%d", node->val);
    if (node->rchild == NULL && node->lchild == NULL) return ;
    printf("(");
    outputNode(node->lchild);
    printf(",");
    outputNode(node->rchild);
    printf(")");
    return ;
}

void outputTree(Tree *tree) {
    printf("tree(%d) = ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return ;
}

void preorderNode (Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->val);
    preorderNode(root->lchild);
    preorderNode(root->rchild);
    return ;
}

void preorder(Tree *tree) {
    printf("pre order : ");
    preorderNode(tree->root);
    printf("\n");
    return ;
}


int main() {
    srand(time(0));
    Tree *tree = getNewTree();
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        insert(tree, val);
        outputTree(tree);
    }
    preorder(tree);
    return 0;
}
