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
        while(q != NULL && p->val == q->val) q = q->next;

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
