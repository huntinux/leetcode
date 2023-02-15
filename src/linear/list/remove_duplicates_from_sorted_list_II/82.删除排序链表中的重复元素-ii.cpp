/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

// @lc code=start
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
    // start: 22:11
    // end:
    // [prev start .. end ..]
    // 总结：循环套小循环
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode dummy(head->val - 1, head);
        ListNode *prev = &dummy, *curr = head;
        int val = curr->val;
        while (curr) {
            // prev | val ... val | curr ...
            ListNode *scope_begin = curr;
            while (curr && curr->val == val) {
                curr = curr->next;
            }
            if (scope_begin->next != curr) {
                prev->next = curr;
                if (curr) val = curr->val;
            } else {
                prev = scope_begin;
                if (curr) val = curr->val;
            }
        }
        return dummy.next;
    }
};
// @lc code=end

