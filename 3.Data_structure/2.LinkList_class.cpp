/*************************************************************************
	> File Name: 2.LinkList_class.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四 11/18 10:54:46 2021
 ************************************************************************/
 //LinkList cpp类的思想实现

#include <iostream>
using namespace std;

struct Node {
    Node (int data) : data(data), next(NULL) {}
    int data;
    Node *next;
};

int main() {
    Node *head = NULL;
    head = new Node(1);
    head->next =  new Node(2);
    head->next->next =  new Node(3);
    head->next->next->next =  new Node(4);
    Node *p = head;
    while (p) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
    return 0;
}
