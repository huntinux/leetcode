/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {

    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct ListNode * head = NULL;
    if(l1->val < l2->val)
    {
        head = l1;
        head->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        head = l2;
        head->next = mergeTwoLists(l1, l2->next);
    }

    return head;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    struct ListNode * head = NULL, * tail = NULL , * n = NULL;

    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            n = l1;
            l1 = l1->next;
        }
        else
        {
            n = l2;
            l2 = l2->next;
        }

        if (head)
        {
            tail->next = n;
            tail = tail->next;
        }
        else
        {
            head = n; 
            tail = head;
        }
    }

    if (l1)
    {
        tail->next = l1;
    }
    else if (l2)
    {
        tail->next = l2;
    }
    else
    {
        tail->next = NULL;
    }
    return head;
}
