#include "quick_sort.h"

#include <iostream>

#include "gtest/gtest.h"

TEST(test, case1) {
  std::vector<int> v{5, 3, 2, 7, 6};
  quick_sort(v);
  std::vector<int> v2{2, 3, 5, 6, 7};
  EXPECT_EQ(v2, v);
}

// 中间元素满足 left <= middle <= right 或者 right <= middle <= left
// 循环检测这三个元素是否满足条件即可
int find_middle_in_three_v1(std::vector<int>& nums) {
  int a = nums[0], b = nums[1], c = nums[2];
  if ((b <= a && a <= c) || (c <= a && a <= b)) return a;
  if ((a <= b && b <= c) || (c <= b && b <= a)) return b;
  return c;
}

// 类似冒泡排序
int find_middle_in_three_v2(std::vector<int>& nums) {
  int left = 0, middle = 1, right = 2;
  if (nums[left] > nums[middle]) std::swap(nums[left], nums[middle]);
  if (nums[left] > nums[right]) std::swap(nums[left], nums[right]);
  if (nums[middle] > nums[right]) std::swap(nums[middle], nums[right]);
  return nums[middle];
}

TEST(test, find_middle) {
  {
    std::vector<int> nums{1, 5, 3};
    EXPECT_EQ(3, find_middle_in_three_v1(nums));
  }
  {
    std::vector<int> nums{1, 5, 3};
    EXPECT_EQ(3, find_middle_in_three_v2(nums));
  }
}
