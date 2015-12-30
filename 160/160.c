
/*
   Write a program to find the node at which the intersection of two singly linked lists begins.

   For example, the following two linked lists:

A:          a1 → a2
↘
c1 → c2 → c3
↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/


// 先求两个链表的长度 len1 len2
// 两个指针， 较长的链表的指针，先走 |len1 - len2|
// 然后... hehe
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int listlen(struct ListNode * p)
{
    int len = 0;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    int len1 = listlen(headA), len2 = listlen(headB); 
    struct ListNode * p = headA, * q = headB;
    int step = 0;

    if (len1 > len2)
    {
        step = len1 - len2;
        while(step--)
            p=p->next;
    }
    else
    {
        step = len2 - len1;
        while(step--)
            q=q->next;
    }

    while(p && q)
    {
       if (p->val == q->val) 
           return p;
       p = p->next;
       q = q->next;
    }
    return NULL;

}
