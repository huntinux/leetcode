#include "quick_sort.h"

static int partition_normal(std::vector<int>& vec, int low, int high) {
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

static int sort_three_and_return_median_index(std::vector<int>& vec, int low, int high, int middle) {
  if (vec[low] > vec[middle]) std::swap(vec[low], vec[middle]);
  if (vec[low] > vec[high]) std::swap(vec[low], vec[high]);
  if (vec[middle] > vec[high]) std::swap(vec[middle], vec[high]);
  return middle;
}

// 三数取中，避免快排退化成冒泡排序
// 也可以用rand随机取pivot的位置
static int partition(std::vector<int>& vec, int low, int high) {
  int median_index = sort_three_and_return_median_index(vec, low, low + (high - low) / 2, high);
  std::swap(vec[low], vec[median_index]);
  return partition_normal(vec, low, high);
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
