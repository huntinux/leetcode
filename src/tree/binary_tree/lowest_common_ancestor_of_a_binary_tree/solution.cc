#include "solution.h"

// 递归写法
//
//     p
//    /
//   .
//  /
// q
//
//     q
//    /
//   .
//  /
// p
//
//    root
//    / \
//   p   q
//
//    root
//    / \
//   a   b
//  /   /
// p   q
//
// lca(root, p, q)->root
//  lca(a, p, q)->p
//   lca(p, p, q)->p
//   lca(nullptr, p, q)->nullptr
//  lca(b, p, q)->q
//   lca(q, p, q)->q
//   lca(nullptr, p, q)->nullptr
//
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root || p == root || q == root) return root;
  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);
  if (left == nullptr && right == nullptr) return nullptr;
  if (left != nullptr && right != nullptr) return root;
  return left == nullptr ? right : left;
}

// 存储父节点
// 我们可以用哈希表存储所有节点的父节点，然后我们就可以利用节点的父节点信息从 p
// 结点开始不断往上跳，并记录已经访问过的节点，再从 q
// 节点开始不断往上跳，如果碰到已经访问过的节点，那么这个节点就是我们要找的最近公共祖先。
class Solution {
 public:
  unordered_map<int, TreeNode*> fa;
  unordered_map<int, bool> vis;
  void dfs(TreeNode* root) {
    if (root->left != nullptr) {
      fa[root->left->val] = root;
      dfs(root->left);
    }
    if (root->right != nullptr) {
      fa[root->right->val] = root;
      dfs(root->right);
    }
  }
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    fa[root->val] = nullptr;
    dfs(root);
    while (p != nullptr) {
      vis[p->val] = true;
      p = fa[p->val];
    }
    while (q != nullptr) {
      if (vis[q->val]) return q;
      q = fa[q->val];
    }
    return nullptr;
  }
};
