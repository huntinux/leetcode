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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;

        slow = fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                break;
            }
        }
        if(fast == NULL || fast->next == NULL)
            return NULL;

	// 求环的长度n
        int circle_len = 1;
        slow = slow->next;
        while(slow != fast) {
            circle_len ++;
            slow = slow->next;
        }

	// fast先走n
        slow = fast = head;
        while(circle_len-- > 0) {
            fast = fast->next;
        }

	// 再次相遇时为环开始处。
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
