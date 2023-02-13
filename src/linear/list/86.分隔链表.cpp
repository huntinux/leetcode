/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
// start: 22:34
// end: 22:55
// 总结：借助dummy节点，纸上分析
class Solution {
public:
    // 分拆成两个链表最后再合并
    // 有些精妙, 在纸上面画一下就明白了
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy, right_dummy;
        ListNode *l = &left_dummy, *r = &right_dummy;
        for (ListNode* curr = head; curr; curr = curr->next) {
            if (curr->val < x) {
                l->next = curr;
                l = curr;
            } else {
                r->next = curr;
                r = curr;
            }
        }
        r->next = nullptr;
        l->next = right_dummy.next;
        return left_dummy.next;
    }

    // 找到变大变小的边界
    ListNode* partition2(ListNode* head, int x) {
        ListNode dummy(x-1, head);
        ListNode* curr = &dummy;
        while (curr) {
            ListNode* big_prev = nullptr; 
            while (curr && curr->val < x) {
                big_prev = curr;
                curr = curr->next;
            }
            ListNode* small_prev = nullptr;
            while (curr && curr->val >= x) {
                small_prev = curr;
                curr = curr->next;
            }
            if (curr && big_prev && small_prev) {
                small_prev->next = curr->next;
                curr->next = big_prev->next;
                big_prev->next = curr;
            }
        }
        return dummy.next;
    }
};
// @lc code=end

