/*
   Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

   Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function. 

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {

    public:
        void deleteNode(ListNode* node) 
        {
            if (node == nullptr || node->next == nullptr) return; 

            ListNode *cur, *pre;
            pre = nullptr;
            cur = node;

            while(cur->next)
            {
                cur->val = cur->next->val;
                pre = cur;
                cur = cur->next;
            }

            pre->next = nullptr;
            free(cur);
        }

};
