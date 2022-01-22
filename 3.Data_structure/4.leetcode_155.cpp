/*************************************************************************
	> File Name: 4.leetcode_155.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三  1/19 07:42:10 2022
 ************************************************************************/

#include <iostream>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> min_s;
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if (min_s.size() == 0 || val <= min_s.top()) {
            min_s.push(val);
        }
        return ;
    }
    
    void pop() {
        if (min_s.top() == s.top()) min_s.pop();
        s.pop();    
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();


    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
