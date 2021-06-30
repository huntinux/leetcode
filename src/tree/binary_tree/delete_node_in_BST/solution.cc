#include "solution.h"

// BST相关知识点
// 二叉搜索树的三个特性：
//  1. 二叉搜索树的中序遍历的序列是递增排序的序列。中序遍历的遍历次序：
//    Left -> Node -> Right
//    LinkedList<Integer> inorder(TreeNode root, LinkedList<Integer> arr)
//    {
//      if (root == null) return arr;
//      inorder(root.left, arr);
//      arr.add(root.val);
//      inorder(root.right, arr);
//      return arr;
//    }
//
//  2. Successor
//    代表的是中序遍历序列的下一个节点。即比当前节点大的最小节点，简称后继节点。
//    先取当前节点的右节点，然后一直取该节点的左节点，直到左节点为空，则最后指向的节点为后继节点。
//    int successor(TreeNode root) {
//      root = root.right;
//      while (root.left != null) root = root.left;
//      return root;
//    }
//
//  3. Predecessor
//    代表的是中序遍历序列的前一个节点。即比当前节点小的最大节点，简称前驱节点。
//    先取当前节点的左节点，然后取该节点的右节点，直到右节点为空，则最后指向的节点为前驱节点。
//    int predecessor(TreeNode root) {
//      root = root.left;
//      while (root.right != null) root = root.right;
//      return root;
//    }
//
//  以上面的3个特性为基础，可以得到解法：
//
//  递归
//    分情况讨论：
//      - 要删除的为叶子节点，可以直接删除(递归的终止条件)
//      -
//      待删除的节点不是叶子节点，且拥有右子树，则可以用该节点的后继节点（Successor）代替(交换value)
//        问题转化为删除它的后继节点，此问题可以重复这个流程，即递归的进行删除。
//      -待删除的节点不是叶子节点，且没有右子树，但是有左子树，同理可以用它的前驱节点代替.
//
//  具体步骤
//    1. 在BST中搜索此节点，注意要有它的父节点信息
//    2. 根据节点的类型，执行不同的操作

TreeNode* Solution::deleteNode(TreeNode* root, int key) {
  if (!root) return nullptr;
  if (key < root->val) {
    // 这里有个思考卡点，在删除一个节点时，其实需要它的父节点信息, 一开始想着再
    // 传递一个遍历，但是对于递归算法，当前栈就是下游栈的父亲，所以这里直接在
    // 父节点做赋值，子节点返回新的root即可，root可以为空也可以不为空
    root->left = deleteNode(root->left, key); 
    return root;
  }
  if (key > root->val) {
    root->right = deleteNode(root->right, key);
    return root;
  }

  // 叶子节点，可以直接删除
  if (!root->left && !root->right) {  
    delete root;
    return nullptr;  // 返回空节点，递归的上一层，父节点会把左/右置空
  }

  if (root->right) {
    // 右子树不空，找到它的后继节点进行替换,
    // 问题转化为删除它的后继节点
    TreeNode* successor = root->right;
    while (successor->left) successor = successor->left;
    root->val = successor->val;
    root->right = deleteNode(root->right, successor->val);
  } else if (root->left) {
    TreeNode* predecessor = root->left;
    while (predecessor->right) predecessor = predecessor->right;
    root->val = predecessor->val;
    root->left = deleteNode(root->left, predecessor->val);
  }
  return root;
}

