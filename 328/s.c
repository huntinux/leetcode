
/*
328. Odd Even Linked List
Total Accepted: 26671 Total Submissions: 71456 Difficulty: Medium

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* oddEvenList(struct ListNode* head) {
	if(!head) return head;

	struct ListNode *oddList, *evenList, *evenListHead;

	oddList = head;
	evenList = evenListHead = head->next;
	while(evenList && evenList->next)
	{
		oddList->next = evenList->next;
		oddList = oddList->next;

		evenList->next = oddList->next;
		evenList = evenList->next;
	}
	oddList->next = evenListHead;
	return head;

}

struct ListNode* oddEvenList(struct ListNode* head) {
	if(!head || !head->next) return head;

	struct ListNode *oddListTail = head, *evenListTail = head->next, *p = head->next->next;
	struct ListNode *evenListHead = head->next;

	while(p && p->next)
	{
		oddListTail->next  = p;
		evenListTail->next = p->next;
		p = p->next->next;
		oddListTail  = oddListTail->next;
		evenListTail = evenListTail->next;
	}
	if(p) 
	{
		oddListTail->next = p;
		oddListTail  = oddListTail->next;
	}
	evenListTail->next = NULL;
	oddListTail->next = evenListHead;
	
	return head;
}
