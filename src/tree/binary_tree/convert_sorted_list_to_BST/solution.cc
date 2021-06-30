#include "solution.h"

// 链表是排序好的
// 那么每次我们找到中间元素构建根，然后再对链表左右两部分递归执行此操作

// 快慢指针法
// 以为可能是某个子区间，所以需要两个输入参数，而不是一个
ListNode* FindMedian(ListNode* begin, ListNode* end) { 
  ListNode *fast = begin, *slow = begin; 
  while (fast != end && fast->next != end) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

TreeNode* BuildBST(ListNode* begin, ListNode* end) {
  if (begin == end) return nullptr; // 递归终止条件
  ListNode* mid = FindMedian(begin, end);
  TreeNode* root = new TreeNode(mid->val);
  root->left = BuildBST(begin, mid);
  root->right = BuildBST(mid->next, end); // 注意这里：是mid->next
  return root;
}

TreeNode* Solution::sortedListToBST(ListNode* head) {
  // 分治的过程需要两个参数作为范围参数，所以需要另外一个接口
  return BuildBST(head, nullptr);
}
