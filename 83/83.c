/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct ListNode *p , *q, *r, *n;

    p = head;
    q = p->next;
    while(p)
    {
        while(q != NULL && p->val == q->val) 
            q = q->next;

        if ( q != p->next )
        {
            r = p->next;
            p->next = q;
            while( r < q )
            {
                n = r->next;
                free(r);
                r = n;
            }
        }
        p = q;
        if (p != NULL)
            q = p->next;
        else
            break;
    }
    return head;
}

// problem 82
// 1 2 2 3 -> 1 3
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;

    dummy.next = head;
    int flag = 0, val;
    struct ListNode* prev, *cur;

    prev = &dummy;
    cur  = prev->next;

    while(cur && cur->next) {
        if(flag == 0) {
            if(cur->val == cur->next->val) {
                val = cur->val;
                flag = 1;
                prev->next = cur->next->next;
                free(cur);
                free(cur->next);
                cur = prev->next; 
            } else {
                prev = cur;
                cur = cur->next;
            }
        } else {
            if(cur->val == val) {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            } else {
                flag = 0;
            }
        }
    }

    return dummy.next;
}