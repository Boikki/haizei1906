/*************************************************************************
	> File Name: 2.LinkList_array.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四 11/18 11:31:23 2021
 ************************************************************************/

// 数组实现链表操作
// next[i]存储的是下标为i的node 的next是谁
#include <iostream>

int data[10];
int next[10];

// ind node 后边添加data 为 val的node p
void add(int ind, int p, int val) {
    next[ind] = p;
    data[p] = val;
    return ;
}

int main() {
    // 头节点为next3
    int head = 3;
    data[3] = 0;
    add(3, 5, 1);
    add(5, 2, 2);
    add(2, 7, 100);
    int p = head;
    while (p) {
        printf("%d->", data[p]);
        p = next[p];
    }
    printf("\n");
    return 0;
}
