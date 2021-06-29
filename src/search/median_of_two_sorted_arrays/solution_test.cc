#include "solution.h"
#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  int A[] = {1, 3, 4, 9};
  int B[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  EXPECT_EQ(4, s.findMedianSortedArrays(A, 4, B, 9));
}

TEST(test, case2) {
  Solution s;
  int A[] = {1, 2};
  int B[] = {2, 3};
  EXPECT_EQ(2, s.findMedianSortedArrays(A, 2, B, 2));
}

TEST(test, case3) {
  Solution s;
  int A[] = {1};
  int B[] = {2, 3};
  EXPECT_EQ(2, s.findMedianSortedArrays(A, 1, B, 2));
}

TEST(test, case4) {
  Solution s;
  int A[] = {2, 2, 4, 4};
  int B[] = {2, 2, 4, 4};
  EXPECT_EQ(3, s.findMedianSortedArrays(A, 4, B, 4));
}

TEST(test, case5) {
  Solution s;
  int A[] = {1, 2};
  int B[] = {3, 4};
  EXPECT_EQ(2.5, s.findMedianSortedArrays(A, 2, B, 2));
}

TEST(test, case6) {
  Solution s;
  int A[] = {1};
  int B[] = {2, 3, 4, 5, 6};
  EXPECT_EQ(3.5, s.findMedianSortedArrays(A, 1, B, 5));
}
