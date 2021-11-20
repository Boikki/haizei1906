/*************************************************************************
	> File Name: 2.leetcode83.cpp
	> Author: 任博宇 
	> Mail: renboyu@hrbeu.edu.cn / renboyu2333@gmail.com
	> Created Time: 五 11/19 14:15:13 2021
 ************************************************************************/
/** delete value same node
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ret, *p, *q;
        ret.next = head;
        p = &(ret), q = head;
        while (q && q->next) {
            if (q->val - q->next->val) q = q->next;
            else {
                p = q->next;
                q->next = p->next;
                free(p);
            }
        }
        return ret.next;
    }

};
