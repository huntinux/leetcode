#pragma once

/*
输入一个数组,求出这个数组中的逆序对的总数P。

题目保证输入的数组中没有的相同的数字

input: [1,2,3,4,5,6,7,0]
output: 7
*/

#include <vector>

using std::vector;

class Solution {
 public:
  int ReversePairs(vector<int>& nums);
  void ReverseHelper(vector<int>& nums, int start, int end);
  void ReverseHelperImpl(vector<int>& nums, int start, int mid, int end);

 private:
  int reverse_pair_count_ = 0;
};
