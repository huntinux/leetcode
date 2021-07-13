#include "solution.h"

// 分析，BST树的中序遍历是有序的，中序遍历即可
//
//   回忆中序遍历的实现，出栈时访问，避免死循环
//
int Solution::kthSmallest(TreeNode* root, int k) {
  int rank = 0;
  std::stack<TreeNode*> s;
  while (root || !s.empty()) {
    if (root) {  // 不为空入栈
      s.push(root);
      root = root->left;
    } else {
      // 无需再次判断s.empty()
      // 栈顶元素即为下一个可以访问的元素
      TreeNode* node = s.top();
      s.pop();
      if (++rank == k) {  // 如果此元素的rank满足条件，直接返回它的val
        return node->val;
      }
      if (node->right) { // 如果右子树不为空，对右子树执行相同的过程
        root = node->right;
      }
    }
  }
  return -1;
}
