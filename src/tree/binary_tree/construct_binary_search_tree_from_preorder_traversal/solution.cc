#include "solution.h"

// 分析
// 二叉搜索树：对于任意节点 left < root < right
// 它的先序遍历，第一个节点肯定时root，那么怎么找到左右呢？
// 根据BST树的性质，左边节点 < root, 那么我们可以找到第一个大于root的元素
// 把数组分为左右两部分分别递归处理即可
//
// 优化，结合二分查找优化
// 类似实现std::lower_bound
// example: [8,5,1,7,10,12]
//  root = 9
//  剩下的元素可以分成两部分 [5,1,7] [10,12]
//  取中间元素，如果arr[mid] > root, 说明mid位于右边区间，把范围缩小：high = mid
//  否则说明mid位于左边区间，把范围缩小：low = mid + 1
//
// 目标：找到第一个大于root->val的元素下表，如果没有，返回end
//
// 具体例子
//
// 0 1 2 3  4  5
// 8 5 1 7 10 12
// r l   m     h   r > m(7) l = mid + 1 = 4
// r       l/m h   r < m(10) h = mid - 1 = 3
//       h l       不满足l <= h，l即为结果
//
// example [4,2]
// 0   1   2
// 4   2
// r   l/h/m  r > m(2) l = mid + 1 = 2
//     h   l       不满足l <= h, l即为结果
//
// 时间复杂度：O(Nlog(N))
// 空间复杂度：O(log(N)) 递归深度

TreeNode* Solution::bstFromPreorder(vector<int>& preorder) {
  return build(preorder, 0, preorder.size());
}

TreeNode* Solution::build(vector<int>& preorder, int begin, int end) {
  if (begin >= end) return nullptr;
  TreeNode* root = new TreeNode(preorder[begin]);

  int low = begin + 1, high = end - 1;
  while (low <= high) {  // 注意这里的等号
    int mid = low + (high - low) / 2;
    if (preorder[mid] < root->val) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  int pivot = low;
  root->left = build(preorder, begin + 1, pivot);
  root->right = build(preorder, pivot, end);
  return root;
}

// 未使用二分查找优化，时间复杂度 O(N*N)
// TreeNode* Solution::build(vector<int>& preorder, int begin, int end) {
//  if (begin >= end) return nullptr;
//  TreeNode* root = new TreeNode(preorder[begin]);
//  int pivot = begin + 1;
//  while (pivot < end) {
//    if (preorder[pivot] < root->val) {
//      pivot++;
//    } else {
//      break;
//    }
//  }
//  root->left = build(preorder, begin + 1, pivot);
//  root->right = build(preorder, pivot, end);
//  return root;
//}

// 使用迭代器，并利用标准库的upper_bound
TreeNode* Solution::build(
    vector<int>::iterator begin vector<int>::iterator end) {
  if (begin == end) return nullptr;
  TreeNode* root = new TreeNode(*begin);
  auto pos = std::upper_bound(begin + 1, end, *begin);
  root->left = build(begin + 1, pos);
  root->right = build(pos, end);
  return root;
}

// 还有O(N)的解法, 非常巧妙
/*
class Solution
{
public:
    int idx = 0;
    TreeNode *bstFromPreorder(vector<int> &preorder, int parent_value = INT_MAX)
    {
        if (idx == preorder.size() || preorder[idx] > parent_value)
            return NULL;
        int current_value = preorder[idx++];
        TreeNode *temp = new TreeNode(current_value);
        temp->left = bstFromPreorder(preorder, current_value);
        temp->right = bstFromPreorder(preorder, parent_value);
        return temp;
    }
};
*/
