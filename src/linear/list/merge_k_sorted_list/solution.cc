#include "solution.h"

// from leetcode
ListNode *mergeKLists(vector<ListNode *> &lists) {
  if (lists.empty()) {
    return nullptr;
  }
  while (lists.size() > 1) {  // 每次合并前两个
    lists.push_back(
        mergeTwoLists(lists[0], lists[1]));  // 把合并的结果push到后面
    lists.erase(lists.begin());  // 删除已经被合并的两个list
    lists.erase(lists.begin());
  }
  return lists.front();
}

// 合并两个list
//
// 递归版本实现
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
  if (l1 == nullptr) {
    return l2;
  }
  if (l2 == nullptr) {
    return l1;
  }
  if (l1->val <= l2->val) {
    l1->next = mergeTwoLists(l1->next, l2);
    return l1;
  } else {
    l2->next = mergeTwoLists(l1, l2->next);
    return l2;
  }
}

// 另外一个版本
// 有点精妙
// 前后配对，然后个数每次减半
ListNode *mergeKLists(vector<ListNode *> &lists) {
  if (lists.empty()) return NULL;
  int len = lists.size();
  while (len > 1) {
    for (int i = 0; i < len / 2; ++i) {
      lists[i] = mergeTwoLists(lists[i], lists[len - 1 - i]);
    }
    len = (len + 1) / 2;
  }
  return lists.front();
}
