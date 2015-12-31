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
        // hashmap
        // 效率低
        bool hasCycle(ListNode *head) {
            set<ListNode *> s;
            ListNode * p = head;
            while(p)
            {
                if (s.find(p) != s.end())
                    return true;
                s.insert(p);
                p = p->next;
            }
            return false;

        }

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
};

