/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    // start: 15:50
    // end: 16:06
    // [start_prev, start ... end, end_next]
    // reverse(start, end)
    // start_prev->next = end
    // start->next = end_next
    // 总结：
    // 1. 在纸上画出算法过程会让思路更加清晰
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *start_prev = nullptr, *start = head;

        int pos = 1;
        while (pos < left) {
            start_prev = start;
            start = start->next;
            pos++;
        }

        ListNode *curr = start, *prev = nullptr;
        while (pos <= right) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            pos++;
        }

        ListNode *end = prev, *end_next = curr;
        if (start_prev) {
            start_prev->next = end;
        }
        start->next = end_next;

        return start_prev ? head : end;
    }
};
// @lc code=end

