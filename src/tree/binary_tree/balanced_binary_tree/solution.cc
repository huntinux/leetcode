#include "solution.h"

#include <cstdlib>
#include <queue>

// The first method checks whether the tree is balanced strictly according to
// the definition of balanced binary tree: the difference between the heights of
// the two sub trees are not bigger than 1, and both the left sub tree and right
// sub tree are also balanced. With the helper function depth(), we could easily
// write the code;
//
// NOTE
// 自上而下的方式，depth有重复调用
// 时间复杂度O(n^2), 空间复杂度等于递归深度O(n)
class solution {
 public:
  int depth(TreeNode* root) {
    if (root == NULL) return 0;
    return max(depth(root->left), depth(root->right)) + 1;
  }

  bool isBalanced(TreeNode* root) {
    if (root == NULL) return true;

    int left = depth(root->left);
    int right = depth(root->right);

    return abs(left - right) <= 1 && isBalanced(root->left) &&
           isBalanced(root->right);
  }
};

// The second method is based on DFS. Instead of calling depth() explicitly for
// each child node, we return the height of the current node in DFS recursion.
// When the sub tree of the current node (inclusive) is balanced, the function
// dfsHeight() returns a non-negative value as the height. Otherwise -1 is
// returned. According to the leftHeight and rightHeight of the two children,
// the parent node could check if the sub tree is balanced, and decides its
// return value.
//
// NOTE:
// 自下而上的方式
// 定义dfsHeight，它的返回值
//    -1 表示左子树或右子树不平衡，或者左右子树高度差大于1，
//    这些情况root都不平衡
//    >=0 表示root的左右子树都平衡，且root也平衡，返回root的高度即可
//
// 可以看到，借助求树高时，同时判断平衡性，返回一个特殊的值-1表示底层子树不平衡，
// 上层拿到这个信息后，可以快速结束，效率比自上而下的方式要高
// 时间复杂度：O(n) 空间复杂度：O(n)
class solution {
 public:
  int dfsHeight(TreeNode* root) {
    if (root == NULL) return 0; // 叶子节点高度为0

    int leftHeight = dfsHeight(root->left); // 左子树高度
    if (leftHeight == -1) return -1;        // 发现左子树不平衡，则此root代表的树也不平衡
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1; // 左右子树高度差大于1， 则此root代表的树也不平衡
    return max(leftHeight, rightHeight) + 1; // 经过上面的判断，root平衡，则放回它的高度，给上层使用
  }
  bool isBalanced(TreeNode* root) { return dfsHeight(root) != -1; }
};
