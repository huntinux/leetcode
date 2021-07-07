#include "solution.h"

// You must solve the problem in O(1) extra space complexity and O(n) time
// complexity.
//
// 分析
//  题目要求了O(1)的空间复杂度和O(N)的时间复杂度
//
//  Input: head = [1,2,3,4,5]
//  Output: [1,3,5,2,4]
//
//  先分成两个list：odd_list / even_list
//  最后把odd_list和even_list合并即可

ListNode* Solution::oddEvenList(ListNode* head) {
  ListNode *odd_head = nullptr, *odd_tail = nullptr;
  ListNode *even_head = nullptr, *even_tail = nullptr;
  ListNode* curr = head;
  bool is_odd = true;
  while (curr) {
    if (is_odd) {
      if (odd_tail) {
        odd_tail->next = curr;
        odd_tail = curr;
      } else {
        odd_head = odd_tail = curr;
      }
      curr = curr->next;
      odd_tail->next = nullptr;
    } else {
      if (even_tail) {
        even_tail->next = curr;
        even_tail = curr;
      } else {
        even_head = even_tail = curr;
      }
      curr = curr->next;
      even_tail->next = nullptr;
    }
    is_odd = !is_odd;
  }
  if (odd_tail) {
    odd_tail->next = even_head;
  } else {
    odd_head = even_head;
  }
  return odd_head;
}

/*
// 扩展：根据节点value来判断奇偶性
ListNode* Solution::oddEvenList(ListNode* head) {
  ListNode* odd_head = nullptr, *odd_tail = nullptr;
  ListNode* even_head = nullptr, *even_tail = nullptr;
  ListNode* curr = head;
  while (curr) {
    if (curr->val & 0x1) { // odd
      if (odd_tail) {
        odd_tail->next = curr;
        odd_tail = curr;
      } else {
        odd_head = odd_tail = curr;
      }
      curr = curr->next;
      odd_tail->next = nullptr;
    } else {
      if (even_tail) {
        even_tail->next = curr;
        even_tail = curr;
      } else {
        even_head = even_tail = curr;
      }
      curr = curr->next;
      even_tail->next = nullptr;
    }
  }
  if (odd_tail) {
    odd_tail->next = even_head;
  } else {
    odd_head = even_head;
  }
  return odd_head;
}
*/

// 官方的代码比较简洁
ListNode* Solution::oddEvenList(ListNode* head) {
  if (head == nullptr || head->next == nullptr) return head;
  ListNode* odd = head;
  ListNode* even_head = head->next;
  ListNode* even = even_head;
  while (even != nullptr && even->next != nullptr) { 
    // 注意结束条件, 剩余节点个数小于等于2个时，结束即可
    odd->next = even->next;
    odd = odd->next;
    even->next = odd->next;
    even = even->next;
  }
  odd->next = even_head;
  return head;
}

