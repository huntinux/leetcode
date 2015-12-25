/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    
    if (head == NULL || head->next == NULL)
        return head;
    
    struct ListNode * pre, * cur, * pos;

    pre = NULL;
    cur = head;
    while(cur != NULL)
    {
        pos = cur->next;
        cur->next = pre;
        pre = cur;
        cur = pos;
    }
    
    return pre;
}
