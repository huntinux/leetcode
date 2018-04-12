/*
Given a list, rotate the list to the right by k places, where k is non-negative.

Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    if(head == NULL || head->next == NULL) return head;
    
    // 求链表长度
    int length = 2;
    struct ListNode* p = head->next;
    while(p->next) {
        length++;
        p = p->next;
    }
    
    // 根据长度取于，去掉重复周期
    k = k % length;
    if(k == 0) return head;
    
    // 首位相连成为一个圈，然后寻找新的起点，最后合适位置断开，变得到新的链表
    int forward = length - k - 1;
    p->next = head;
    struct ListNode* q = head;
    while(forward-- > 0) {
        q = q->next;
    }
    struct ListNode* new_head = q->next;
    q->next = NULL;
    return new_head;
}