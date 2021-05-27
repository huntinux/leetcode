#include "heap_sort.h"

namespace heap {
// 这里实现的为大根堆
// 底层数据结构是一维数组表示的一棵完全二叉树
// 对应编号为i的节点，它的左右子树根节点分别为 2*i+1 2*i+2
// 有n个节点的完全二叉树，它的第一个非叶子节点为 n/2-1

// 创建堆
// 从第一个非叶子节点开始调整, 到根节点结束
void make(std::vector<int>& vec) {
  int n = vec.size();
  for (int i = n / 2 - 1; i >= 0; --i) {
    adjust(vec, n, i);
  }
}

// 调整
// 判断root left right 三个节点，最大的调整为root
// 如果没有发生交换则此次调整结束
// 如果发生了交换，则继续调整左子树或右子树
//  如果是left与root发生了交换，则继续调整left为root的左子树
//  如果是right与root发生了交换，则继续调整right为root的右子树
void adjust(std::vector<int>& vec, int n, int i) {
  int l = 2 * i + 1; // 左孩子
  int r = 2 * i + 2; // 右孩子
  int largest = i;   // 一开始假设根节点最大

  if (l < n && vec[l] > vec[largest]) largest = l;
  if (r < n && vec[r] > vec[largest]) largest = r;

  if (largest != i) { // 根节点不是最大节点，则需要进行交换并继续调整堆
    std::swap(vec[i], vec[largest]);
    adjust(vec, n, largest); // 元素个数为n， 调整起始位置为largest
  }
}

// 堆排序
void sort(std::vector<int>& vec) {
  // 首先创建堆
  make(vec);
  
  // 每次把对顶输出，然后调整剩余的元素，最后得到有序序列
  int n = vec.size();
  for (int i = n - 1; i >= 0; --i) {
    std::swap(vec[i], vec[0]);
    adjust(vec, i, 0); // 剩余元素个数为i (每次少一个)， 起始调整位置为0
  }
}

}  // namespace heap
