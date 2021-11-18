/*************************************************************************
	> File Name: 2.LinkList.c
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四 11/18 09:37:28 2021
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1.结构定义
// 链表应该有两层封装
// 节点本身是一种结构
// 节点穿起来形成的链表又是一种结构

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct LinkList {
    ListNode head;
    // 这里head叫做虚拟头节点
    // 没有采用指针的形式
    // haed的下一位才是第0位
    // 不像*head里存的是0位的地址
    // 这里head->next里存的是0位的地址
    // head->0->1->2->...->n
    // p一开始指向head 那么要是在第0位插入 p不用动
    int length;
} LinkList;

ListNode *init_listnode(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

LinkList *init_linklist() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

void clear_listnode(ListNode *p) {
    if (p == NULL) return ;
    free(p);
    return ;
}

void clear_linklist(LinkList *l) {
    if (l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_listnode(p);
        p = q;
    }
    free(l);
    return ;
}

int insert(LinkList *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind > l->length || ind < 0) return 0;
    ListNode *p = &(l->head), *node = init_listnode(val);
    while (ind--) {
        p = p->next;
    }
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(LinkList *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while (ind--) {
        p = p->next;
    }
    q = p->next->next;
    clear_listnode(p->next);
    p->next = q;
    l->length -= 1;
    return 1;
}

void output(LinkList *l) {
    printf("LinkList(%d) : ", l->length);
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
    return ;
}

#define MAX_OP 20

int main() {
    srand(time(0));
    LinkList *l = init_linklist();
    for (int i = 0; i < MAX_OP; i++) {
        int op = rand() % 4;
        int ind = rand() % (l->length + 1); 
        int val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d to LinkList = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 3: {
                printf("erase item at %d from LinkList = %d\n", ind, erase(l, ind));
            } break;
        }
        output(l);
        printf("\n");
    }
    return 0;
}
