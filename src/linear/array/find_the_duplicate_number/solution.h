#pragma once

#include <vector>

using std::vector;

/*
给定一个包含 n + 1 个整数的数组 nums ，其数字都在 1 到 n 之间（包括 1 和
n），可知至少存在一个重复的整数。
假设 nums 只有 一个重复的整数 ，找出 这个重复的数 。
你设计的解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。

nums 中 只有一个整数 出现 两次或多次 ，其余整数均只出现 一次
你设计的解决方案必须不修改数组 nums 且只用常量级 O(1) 的额外空间。
*/

class Solution {
 public:
  int findDuplicate(vector<int>& nums);
};
