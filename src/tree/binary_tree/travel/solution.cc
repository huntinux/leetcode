#include "solution.h"

#include <queue>
#include <stack>
#include <unordered_set>

vector<int> Solution::PreorderTraversalRecursion(TreeNode *root) {
  vector<int> result;
  PreorderTraversalRecursionHelper(root, &result);
  return result;
}

void Solution::PreorderTraversalRecursionHelper(TreeNode *root,
                                                vector<int> *result) {
  if (!root) return;
  result->push_back(root->val);
  PreorderTraversalRecursionHelper(root->left, result);
  PreorderTraversalRecursionHelper(root->right, result);
}

// 非递归实现
// 递归算法改造为非递归实现，通常会借助stack
// 使用queue似乎不能解决此问题
vector<int> Solution::PreorderTraversalNonRecursion(TreeNode *root) {
  vector<int> result;
  if (!root) return result;

  std::stack<TreeNode *> s;
  s.push(root);

  while (!s.empty()) {
    TreeNode *top = s.top();
    s.pop();
    result.push_back(top->val);          // 先访问根节点
    if (top->right) s.push(top->right);  // 右子树后访问，因此先入栈
    if (top->left) s.push(top->left);
  }

  return result;
}

// 这个方法有点思维定势了，照搬先序遍历当非递归实现，带来不必要当麻烦
vector<int> Solution::InorderTraversalNonRecursion(TreeNode *root) {
  vector<int> result;
  if (!root) return result;

  std::stack<TreeNode *> s;
  std::unordered_set<TreeNode *>
      history;  // 增加一个记录节点是否访问过的history，
                // 避免死循环
  s.push(root);

  while (!s.empty()) {
    TreeNode *cur = s.top();
    while (cur->left && history.find(cur->left) == history.end()) {
      cur = cur->left;
      s.push(cur);
    }
    result.push_back(cur->val);
    s.pop();
    history.insert(cur);
    if (cur->right) s.push(cur->right);
  }

  return result;
}

// leetcode上面的解法
// 把null也当作元素统一处理
// 时间复杂度O(n)
// 空间复杂度O(n)
vector<int> inorderTraversal(TreeNode *root) {
  vector<int> nodes;
  std::stack<TreeNode *> todo;

  // 判断条件很科学，当root不为空，或者栈不为空时继续循环
  // 根不为空，那么就把根入栈, 并调跳转到左子树的根
  while (root || !todo.empty()) {
    while (root) {
      todo.push(root);
      root = root->left;
    }

    // 此时栈顶元素为下个可以访问的元素了
    root = todo.top();
    todo.pop();
    nodes.push_back(root->val);

    // 同样的方法处理右子树
    root = root->right;
  }
  return nodes;
}

// morris travesal
// 时间：O(n)
// 空间：O(1)
vector<int> morrisInorderTraversal(TreeNode *root) {
  vector<int> nodes;
  while (root) {
    if (root->left) {
      TreeNode *pre = root->left;
      while (pre->right && pre->right != root) {
        pre = pre->right;
      }
      if (!pre->right) {
        pre->right = root;
        root = root->left;
      } else {
        pre->right = NULL;
        nodes.push_back(root->val);
        root = root->right;
      }
    } else {
      nodes.push_back(root->val);
      root = root->right;
    }
  }
  return nodes;
}

vector<int> postorderTraversal(TreeNode *root) {
  vector<int> nodes;
  std::stack<TreeNode *> todo;
  TreeNode *last = NULL;
  while (root || !todo.empty()) {
    if (root) {
      todo.push(root);
      root = root->left;
    } else {
      TreeNode *node = todo.top();  // 栈顶元素可能就是下一个输出元素
      // 右边不空，且右边子树的跟之前没有遍历过(防止死循环)
      if (node->right && last != node->right) {
        root = node->right;  // 遍历指针root，指向这个节点
      } else {  // 右子树为空 或者 右子树已经被访问过了, 当前节点可以输出
        nodes.push_back(node->val);
        last = node;  // 记录最近一次访问的节点
        todo.pop();
      }
    }
  }
  return nodes;
}

// 层次遍历
// 借助队列的FIFO特性
// 102. Binary Tree Level Order Traversal
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
vector<vector<int>> Solution::LevelorderTraversal(TreeNode *root) {
  vector<vector<int>> result;
  if (!root) return result;
  std::queue<std::pair<TreeNode *, int>> q; // 记录node和它对应的level
  int level = 1;    // 根节点level为1
  q.push(std::make_pair(root, level));
  while (!q.empty()) {
    const std::pair<TreeNode *, int> &p = q.front();
    TreeNode *node = p.first;
    int level = p.second;
    q.pop();
    if (result.size() < level) {
      result.resize(level);
    }
    vector<int> &sub_result = result[level - 1];
    sub_result.push_back(node->val);
    if (node->left) q.push(std::make_pair(node->left, level + 1)); // 子节点level为父节点level+1
    if (node->right) q.push(std::make_pair(node->right, level + 1));
  }
  return result;
}
