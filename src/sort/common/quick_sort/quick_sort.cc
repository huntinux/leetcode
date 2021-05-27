#include "quick_sort.h"

static int partition(std::vector<int>& vec, int low, int high) {
  int pivot = low;
  int pivot_val = vec[pivot];
  while (low < high) {
    // 在右边找到第一个小于pivot_val的元素，与pivot交换位置(这里没必要每次都交换
    // 最后得到pivot最终位置再赋值即可
    while (low < high && vec[high] >= pivot_val) --high;
    if (low < high) {
      vec[low++] = vec[high]; // low指向的位置即为pivot的原位置，即为high的目标
                              // 位置，且下次从low后面开始比较即可，因此low++
                              // high的位置变为pivot的位置, 即为空缺位置
    }
    while (low < high && vec[low] <= pivot_val) ++low;
    if (low < high) {
      vec[high--] = vec[low];
    }
  }
  pivot = low;  // 最后low与high相遇的位置几位pivot的最终位置
  vec[pivot] = pivot_val;  // 回复pivot位置的值
  return pivot;
}

void quick_sort_helper(std::vector<int>& vec, int low, int high) {
  if (low < high) {
    int pivot = partition(vec, low, high);  // 确定了一个元素的位置后
    quick_sort_helper(vec, low, pivot - 1);  // 分别对左右两部分进行同样的操作
    quick_sort_helper(vec, pivot + 1, high);
  }
}

void quick_sort(std::vector<int>& vec) {
  int low = 0;
  int high = vec.size() - 1;
  quick_sort_helper(vec, low, high);
}
