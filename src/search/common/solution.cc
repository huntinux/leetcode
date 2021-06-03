#include "solution.h"

// arr需要已经排序好
int binary_search(const std::vector<int>& arr, int target) {
  int low = 0;
  int high = arr.size() - 1;
  while (low <= high) { // 逻辑表达式有没有等号，可以举例子确认下
    int mid = low + (high - low) / 2; // 避免int结果溢出
    if (arr[mid] == target) return mid;
    if (arr[mid] > target) high = mid - 1;
    if (arr[mid] < target) low = mid + 1;
  }
  return -1;
}
