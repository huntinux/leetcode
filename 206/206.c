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

/*
与非递归方法类似，只不过前一个节点prev和当前节点cur通过递归函数的参数来传递。思维方式不太一样。
*/

struct ListNode* helper(struct ListNode* cur, struct ListNode* pre) {
    if(cur == NULL) return pre;
    struct ListNode* n = cur->next; // 记录下一个节点
    cur->next = pre;
    return helper(n, cur); // 递归
}

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    return helper(head, NULL); // 初始时，cur为head，prev为NULL
}


