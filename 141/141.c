

// 链表相关的问题，可以想想用两个指针能否解决
// 两个指针：速度不同， 能够相遇，说明有环

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 8ms
bool hasCycle(struct ListNode *head) {

    struct ListNode * fast , * slow;
    fast = slow = head;
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
    
}

// 优化
// 4ms
bool hasCycle(struct ListNode *head) {

    struct ListNode * fast , * slow;
    fast = slow = head;
    while(fast && fast->next)
    {
        fast = fast->next->next;
        if(slow == fast)
            return true;
        slow = slow->next;
    }
    return false;
    
}
