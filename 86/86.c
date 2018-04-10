/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 一定要用笔在纸上分析，写出步骤，然后给出初步实现，进而优化

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode dummy;
    
    dummy.next = head; // 一个额外的头节点，让头部插入的情况也与其他位置插入一致化
    struct ListNode* insert_pos = &dummy; //插入位置
    struct ListNode* cur = head, *prev = &dummy; //如果需要移动元素时，需要前趋
    int flag = 0; // 记录是否可以进行插入操作
    while(cur != NULL) {
        if(cur->val >= x) { // 找到一个元素比x大，那么后续如果发现比x小的元素，则执行换位操作
            flag = 1;
            prev = cur;
            cur = cur->next;
        } else {
            if(flag == 1) {
                struct ListNode* t1 = cur->next;
                cur->next = insert_pos->next;
                prev->next = t1;
                insert_pos->next = cur;
                cur = t1;
                insert_pos = insert_pos->next;
            } else {
                insert_pos = cur; // 插入位置后移,保证相对位置不变 
                prev = cur;
                cur = cur->next;
            }
        }
    }
    return dummy.next;
}