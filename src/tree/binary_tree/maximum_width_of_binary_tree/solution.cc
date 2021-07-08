#include "solution.h"

// 分析
// 看清楚题目关于width的定义
// 假设层数从0开始，i层的最大节点数量为 2^i
// i层中最左边节点和最右边节点的跨度为width
// 如何得到每一层中的边界节点的编号呢？
//
// 结合二叉树的层次遍历，空节点也当作正常节点访问
// 第一个非空节点即为左边界，最后一个非空节点即为右边界
// 空节点也有两个子节点，只不过他们为空
//
// 这个版本对于较复杂的树耗时较长
//
/*
int Solution::widthOfBinaryTree(TreeNode* root) {
  if (!root) return 0;
  int width = 0;
  std::queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    int n = q.size();
    int left = -1, right = -1;
    for (int i = 0; i < n; ++i) {
      TreeNode* curr = q.front();
      q.pop();
      if (curr) {
        if (left == -1) {
          left = right = i;
        } else {
          right = i;
        }
        q.push(curr->left);
        q.push(curr->right);
      } else {
        q.push(nullptr);
        q.push(nullptr);
      }
    }
    if (left == -1) break;  // 本层节点都为空
    int local_width = right - left + 1;
    if (local_width > width) {
      width = local_width;
    }
  }
  return width;
}
*/

// 优化版本
// 其实没有必要加入空节点，可以加入队列时，同时设置它的编号，父节点编号为i(从0开始）
// ，则左右子树为2i + 1 和 2i + 2
int Solution::widthOfBinaryTree(TreeNode* root) {
  if (!root) return 0;
  int width = 0;
  std::queue<std::pair<TreeNode*, uint64_t>> q;  // 用int64_t或int会有溢出问题
  q.push(std::make_pair(root, 0));  // 从1开始也会有溢出问题...
  while (!q.empty()) {
    uint64_t n = q.size();
    uint64_t left = -1, right = -1;
    for (int i = 0; i < n; ++i) {
      std::pair<TreeNode*, uint64_t>& curr = q.front();
      TreeNode* node = curr.first;
      uint64_t tag = curr.second;
      if (i == 0) {
        left = right = tag;
      } else if (i == n - 1) {
        right = tag;
      }
      if (node) {
        if (node->left) q.push(std::make_pair(node->left, 2 * tag + 1));
        if (node->right) q.push(std::make_pair(node->right, 2 * tag + 2));
      }
      q.pop();
    }
    if (left == -1) break;  // 本层节点都为空
    uint64_t local_width = right - left + 1;
    if (local_width > width) {
      width = local_width;
    }
  }
  return width;
}

// 再次优化版本
// queue可以取front和back
int Solution::widthOfBinaryTree(TreeNode* root) {
  if (!root) return 0;
  int width = 0;
  std::queue<std::pair<TreeNode*, int>> q;
  q.push(std::make_pair(root, 0));
  while (!q.empty()) {
    int left = q.front().second, right = q.back().second;
    int n = q.size();
    for (int i = 0; i < n; ++i) {
      std::pair<TreeNode*, int>& curr = q.front();
      TreeNode* node = curr.first;
      int tag = curr.second;
      if (node->left) {
        // tag-left 避免溢出问题
        q.push(std::make_pair(node->left, 2 * (tag - left) + 1));
      }
      if (node->right) {
        q.push(std::make_pair(node->right, 2 * (tag - left) + 2));
      }
      q.pop();
    }
    int local_width = right - left + 1;
    if (local_width > width) {
      width = local_width;
    }
  }
  return width;
}
