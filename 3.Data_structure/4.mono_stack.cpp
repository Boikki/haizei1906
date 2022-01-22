/*************************************************************************
	> File Name: 4.mono_stack.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 六  1/ 8 11:36:45 2022
 ************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> pre(n), nex(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n; i++) { //每个元素依次压入s，pre和nex存前边后边比他小的最近元素的下标.所以维护递增栈
        while (s.size() && arr[i] < arr[s.top()]) { //是否违反单调性
            nex[s.top()] = i;//arr[i]是当前是你违反单调性的，也就是你能打动的所有元素的后边最近的最小值
            s.pop();
        }
        //那么当前到的i位置即为不能打动的即不违反单调性的位置了，这里对于s为空的情况处理下
        if (s.size() == 0) pre[i] = 1;
        else pre[i] = s.top();
        s.push(i);
    }
    while (s.size()) nex[s.top()] = n, s.pop();

    return 0;
}

