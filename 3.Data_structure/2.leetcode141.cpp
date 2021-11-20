/*************************************************************************
	> File Name: 2.leetcode141.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 五 11/19 14:36:07 2021
 ************************************************************************/



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode ret, *p, *q;
        ret.next = head;
        p = &ret, q = head;
        for (; p && q; p = p->next, q = q->next) {
            if (p == q) return true;
        }
    }
    return false;
};
