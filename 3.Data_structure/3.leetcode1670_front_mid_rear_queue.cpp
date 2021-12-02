/*************************************************************************
	> File Name: 3.dequeue.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: Tue Nov 23 10:42:41 2021
 ************************************************************************/
 //实现前中后插入删除队列 
 //借助两个双向循环队列实现
 //比如 [1, 2, 3,] [4, 5, 6] 这样在mid插入就可以看做在尾部插入

#include <iostream>
using namespace std;

//用链表实现队列

class Node {
public : 
    int val;
    Node *next, *pre;
    Node(int val = 0, Node *next = nullptr) : val(val), next(next) {}
    void insert_pre(Node *p) {
        p->pre = this->pre;
        p->next = this;
        if (this->pre) this->pre->next = p;
        this->pre = p;
        return ;
    }
    void insert_next(Node *p) {
        p->pre = this;
        p->next = this->next;
        if (this->next) this->next->pre = p;
        this->next = p;
        return ;
    }
    void delete_pre() {
        if (this->pre == nullptr) return ;
        Node *p = this->pre;
        this->pre = p->pre;
        if (p->pre) p->pre->next = this;
        delete p;
        return ;
    }
    
    void delete_next() {
        if (this->next == nullptr) return ;
        Node *p = this->next;
        this->next = p->next;
        if (p->next) p->next->pre = this;
        delete p;
        return ;
    }
};

class Queue {
public : 
    Node head, tail;
    int cnt;
    //head & tail 是虚拟头尾指针
    Queue() : cnt(0){
        head.next = &tail;
        head.pre = nullptr;
        tail.next = nullptr;
        tail.pre = &head;
    }

    void push_back(int val) {
        tail.insert_next(new Node(val));
        cnt += 1;
        return ;
    }

    void push_front(int val) {
        head.insert_next(new Node(val));
        cnt += 1;
        return ;
    }
    int pop_back() {
        if (is_empty()) return -1;
        int ret = tail.pre->val;
        tail.delete_pre();
        cnt -= 1;
        return ret;
    }
    int pop_front() {
        if (is_empty()) return -1;
        int ret = head.next->val;
        head.delete_next();
        cnt -= 1;
        return ret;
    }
    int front() {
        return head.next->val;
    }
    int back() {
        return tail.pre->val;
    }
    bool is_empty() {
        return head.next == &tail;
    }
    int size() {
        return cnt;
    }

};
//完成了上述双端队列的封装
//下面用两个双端实现FrontMiddleBackQueue

class FrontMiddleBackQueue {
public:
    Queue q1, q2;
    FrontMiddleBackQueue() {
    }
    
    void pushFront(int val) {
        q1.push_front(val);
        update();
        return ;
    }
    
    void pushMiddle(int val) {
        //思路：如果q1.size() > q2.size() 
        //就把q1.back() 接到q2.front()
        //再在q1.push_back() 插入
        if (q1.size() > q2.size()) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        q1.push_back(val);
        update();
        return ;
    }
    
    void pushBack(int val) {
        q2.push_back(val);
        update();
        return ;
    }
    
    int popFront() {
        if (q1.is_empty()) return -1;
        int ret = q1.pop_front();
        update();
        return ret;
    }
    
    int popMiddle() { //pop q1.back()
        if (is_empty()) return -1;
        int ret = q1.pop_back();
        update();
        return ret;
    }
    
    int popBack() {
        if (q1.is_empty()) return -1;
        int ret = q2.pop_back();
        update();
        return ret;
    }
    bool is_empty() {
        return (q1.size() == 0);
        //因为规定q1.size() >= q2.size() !!!
    }
    void update() {
        if (q1.size() < q2.size()) {
            q1.push_back(q2.front());
            q2.pop_front();
        }
        if (q1.size() == q2.size() + 2) {
            q2.push_front(q1.back());
            q1.pop_back();
        }
        return ;
    }
};

