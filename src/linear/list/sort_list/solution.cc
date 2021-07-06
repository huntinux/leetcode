#include "solution.h"

// 「147.对链表进行插入排序」要求使用插入排序的方法对链表进行排序，插入排序的时间复杂度是
// O(n^2)其中 n
// 是链表的长度。这道题考虑时间复杂度更低的排序算法。题目的进阶问题要求达到
// O(nlogn) 的时间复杂度和 O(1)O(1) 的空间复杂度，时间复杂度是 O(nlogn)
//  的排序算法包括归并排序、堆排序和快速排序（快速排序的最差时间复杂度是O(n^2)，
//  其中最适合链表的排序算法是归并排序。
//
// 归并排序基于分治算法。最容易想到的实现方式是自顶向下的递归实现，考虑到递归调用的栈空间，
// 自顶向下归并排序的空间复杂度是 O(logn)。
// 如果要达到 O(1)的空间复杂度，则需要使用自底向上的实现方式。
//
// 方法一：自顶向下归并排序
//  对链表自顶向下归并排序的过程如下。
//  找到链表的中点，以中点为分界，将链表拆分成两个子链表。
//  寻找链表的中点可以使用快慢指针的做法，快指针每次移动 2 步，慢指针每次移动
//  1步， 当快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。
//  对两个子链表分别排序。
//  将两个排序后的子链表合并，得到完整的排序后的链表。可以使用「21.
//  合并两个有序链表」的做法，将两个有序的子链表进行合并。
//
//  复杂度分析
//    时间复杂度：O(nlogn)，其中 n 是链表的长度。
//    空间复杂度：O(logn)，其中 n
//    是链表的长度。空间复杂度主要取决于递归调用的栈空间。

// 递归合并两个有序链表
Node* merge(Node* l1, Node* l2) {
  if (!l1 && !l2) return nullptr;
  if (l1 && !l2) return l1;
  if (!l1 && l2) return l2;
  if (l1->value < l2->value) {
    l1->next = merge(l1->next, l2);
    return l1;
  }
  l2->next = merge(l1, l2->next);
  return l2;
}

Node* Solution::sortList(Node* begin, Node* end) {
  if (begin == nullptr) {
    return nullptr;
  }

  if (begin->next == end) {
    begin->next = nullptr;  // 注意这里, 把list分为独立的list, 方便后面进行merge
    return begin;
  }

  Node *fast = begin, *slow = begin;
  while (fast != end && fast->next != end) {
    fast = fast->next->next;
    slow = slow->next;
  }

  Node* mid = slow;
  Node* left = sortList(begin, mid);
  Node* right = sortList(mid, end);
  return merge(left, right);
}

Node* Solution::sortList(Node* head) { return sortList(head, nullptr); }

/*
方法二：自底向上归并排序
使用自底向上的方法实现归并排序，则可以达到 O(1) 的空间复杂度。
首先求得链表的长度 length，然后将链表拆分成子链表进行合并。
具体做法如下。
用 subLength 表示每次需要排序的子链表的长度，初始时 subLength=1。
每次将链表拆分成若干个长度为 subLength
的子链表（最后一个子链表的长度可以小于subLength），按照每两个子链表一组进行合并，
合并后即可得到若干个长度为
subLength×2 的有序子链表（最后一个子链表的长度可以小于
subLength×2。合并两个子链表仍然使用「 合并两个有序链表」的做法。 将 subLength
的值加倍，重复第 2
步，对更长的有序子链表进行合并操作，直到有序子链表的长度大于或等于
length，整个链表排序完毕。
*/

/**
 * Merge sort use bottom-up policy,
 * so Space Complexity is O(1)
 * Time Complexity is O(NlgN)
 * stable sort
 */
class Solution2 {
 public:
  Node* sortList(Node* head) {
    if (!head || !(head->next)) return head;

    // get the linked list's length
    Node* cur = head;
    int length = 0;
    while (cur) {
      length++;
      cur = cur->next;
    }

    Node dummy(0);
    dummy.next = head;
    Node *left, *right, *tail;
    for (int step = 1; step < length; step <<= 1) {
      cur = dummy.next;
      tail = &dummy;
      while (cur) {
        left = cur;
        right = split(left, step);
        cur = split(right, step);
        tail = merge(left, right, tail);
      }
    }
    return dummy.next;
  }

 private:
  /**
   * Divide the linked list into two lists,
   * while the first list contains first n ndoes
   * return the second list's head
   */
  Node* split(Node* head, int n) {
    // if(!head) return NULL;
    for (int i = 1; head && i < n; i++) head = head->next;

    if (!head) return NULL;
    Node* second = head->next;
    head->next = NULL;
    return second;
  }
  /**
   * merge the two sorted linked list l1 and l2,
   * then append the merged sorted linked list to the node head
   * return the tail of the merged sorted linked list
   */
  Node* merge(Node* l1, Node* l2, Node* head) {
    Node* cur = head;
    while (l1 && l2) {
      if (l1->value > l2->value) {
        cur->next = l2;
        cur = l2;
        l2 = l2->next;
      } else {
        cur->next = l1;
        cur = l1;
        l1 = l1->next;
      }
    }
    cur->next = (l1 ? l1 : l2);
    while (cur->next) cur = cur->next;
    return cur;
  }
};
