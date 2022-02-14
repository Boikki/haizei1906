/*************************************************************************
	> File Name: 6.generic_heap.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 二  2/ 8 14:10:21 2022
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
using namespace std;

template<typename T>
class Heap : public vector<T> {
public :
    template<typename Func_T>
    Heap(Func_T cmp) : cmp(cmp) {}
    void push(const T &a) {
        this->push_back(a);
        push_heap(this->begin(), this->end(), cmp);
        return ;
    }
    void pop() {
        pop_heap(this->begin(), this->end(), cmp);
        this->pop_back();
        return ;
    }
    T &top() {
        return this->at(0);
    }
private : 
    function<bool(T, T)> cmp;
};


int main() {
    Heap<int> h1{less<int>()};
    h1.push(3), h1.push(4);
    while (h1.size()) {
        cout << h1.top() << " ";
        h1.pop();
    }

    return 0;
}
