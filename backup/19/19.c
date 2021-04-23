/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode dummy;
    
    dummy.next = head; // 引入额外头节点dummy，让删除头节点与删除其他节点没什么不同
    struct ListNode *p, *q, *r;
    
    p = &dummy; // 两个指针，距离为n，先出发的到达尾部时，后面的即为删除的合适位置
    while(n-->0) p = p->next;
    
    q = &dummy;
    while(p->next != NULL) {
        p = p->next;
        q = q->next;
    }
    
    r = q->next;
    q->next = r->next;
    free(r);
    return dummy.next;
}