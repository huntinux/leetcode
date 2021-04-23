/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *prev, *curr, *next;

        prev = NULL;
        curr = head;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head)
    {

        if (head == NULL ||
            head->next == NULL ||
            head->next->next == NULL)
            return;

        // 找到后半段
        ListNode *fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // 后半段进行reverse
        ListNode *right_half_head = slow->next;
        slow->next = NULL;
        right_half_head = reverse(right_half_head);

        // 合并得到最后结果
        ListNode *p = head, *q = right_half_head, *n, *m;
        while(q) {
            n = p->next;
            m = q->next;
            p->next = q;
            q->next = n;
            p = n;
            q = m;
        }
    }
};

void PrintList(ListNode *head)
{
    while(head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Solution s;
    PrintList(&n1);
    s.reorderList(&n1);
    PrintList(&n1);
}

// 看似复杂的问题，可以分解为常规操作的组合
