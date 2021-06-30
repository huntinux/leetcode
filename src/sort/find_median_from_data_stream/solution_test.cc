#include "solution.h"

#include <iostream>

#include "gtest/gtest.h"

void debug_vector(const std::vector<int>& nums) {
  for (auto n : nums) {
    std::cout << n << " ";
  }
  std::cout << std::endl;
}

TEST(test, case1) {
  MedianFinder finder;
  finder.addNum(1);
  //debug_vector(finder.getNums());
  finder.addNum(2);
  //debug_vector(finder.getNums());
  EXPECT_EQ(1.5, finder.findMedian());
}


TEST(test, case2) {
  MedianFinder finder;
  finder.addNum(-1);
  finder.addNum(-2);
  EXPECT_EQ(-1.5, finder.findMedian());
  finder.addNum(-3);
  EXPECT_EQ(-2, finder.findMedian());
  finder.addNum(-4);
  EXPECT_EQ(-2.5, finder.findMedian());
  finder.addNum(-5);
  EXPECT_EQ(-3, finder.findMedian());
}
