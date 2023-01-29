/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* head = &dummy, *tail = &dummy;
        ListNode* h1 = l1;
        ListNode* h2 = l2;
        int carry = 0;
        while (h1 || h2 || carry > 0) {
            int n = (h1 ? h1->val : 0) + (h2 ? h2->val : 0) + carry;
            carry = n / 10;
            n = n % 10;
            ListNode* node = new ListNode(n);
            tail->next = node;
            tail = node;
            if (h1) h1 = h1->next;
            if (h2) h2 = h2->next;
        }
        return head->next;
    }
};
// @lc code=end

