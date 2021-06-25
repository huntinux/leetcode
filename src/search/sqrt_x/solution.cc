#include "solution.h"

// 在 [0, x]的有序空间中进行二分查找
int Solution::mySqrt(int x) {
  int low = 0, high = x;
  while (low <= high) {
    int64_t mid = low + (high - low) / 2; // 注意溢出问题
    int64_t n = mid * mid;
    if (n == x) {
      return mid;
    } else if (n > x) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return high;
}

int Solution::mySqrt(int x) {
  if (x == 0) return 0; // 避免除数为0的情况，对0 特殊处理
  if (x <= 3) return 1;
  int low = 2, high = x / 2; // 查找范围就变成了 [2, x/2]
  while (low <= high) {
    int mid = low + (high - low) / 2; // 注意溢出问题
    int n = x / mid;                  // 注意除数为0的情况
    if (n == mid) {
      return mid;
    } else if (n > mid) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return high;
}
