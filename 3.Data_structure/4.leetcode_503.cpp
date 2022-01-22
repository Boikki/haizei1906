/*************************************************************************
	> File Name: 4.leetcode_503.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 三  1/19 21:15:38 2022
 ************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& num) {
        stack<int> s;
        vector<int> ret(num.size());
        for (int i = 0; i < num.size(); i++) ret[i] = -1;
        for (int i = 0; i < num.size(); i++) {
            while (s.size() && num[i] > num[s.top()]) {
                ret[s.top()] = num[i];
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < num.size(); i++) {
            while (s.size() && num[i] > num[s.top()]) {
                ret[s.top()] = num[i];
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};
