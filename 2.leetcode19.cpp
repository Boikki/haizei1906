/*************************************************************************
	> File Name: 2.leetcode19.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 四 11/18 14:59:34 2021
 ************************************************************************/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode ret(0, head), *p, *q;
        p = q = &ret;
        while (n--) p = p->next;
        while (p) p = p->next, q = q->next;
        q->next = q->next->next;
        return ret.next;
    }
};
