/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    // start: 22:04
    // end: 22:09
    // 总结：借助 dummy 节点简化编码
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode dummy(head->val - 1, head);
        dummy.next = head;
        ListNode *prev = &dummy, *curr = head;
        int prev_value = prev->val;
        while (curr) {
            if (curr->val == prev_value) {
                prev->next = curr->next;
                ListNode* trash = curr;
                curr = curr->next;
                delete trash;
            } else {
                prev_value = curr->val;
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy.next;
    }
};
// @lc code=end

