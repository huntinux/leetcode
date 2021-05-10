#include "solution.h"

#include <vector>

// recursion
// mem O(1)
// time O(2^n)
uint32_t Solution::FrogJump(uint32_t n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n == 2) return 2;
  return FrogJump(n - 1) + FrogJump(n - 2);
}

// DP
// mem O(1)
// time O(n)
uint32_t Solution::FrogJumpDP(uint32_t n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (n == 2) return 2;
  std::vector<uint32_t> dict{0, 1, 2};
  dict.reserve(n);
  for (int i = 3; i < n; ++i) {
    dict[i] = dict[i - 1] + dict[i - 2];
  }
  return dict[n - 1] + dict[n - 2];
}

// summary
// 将问题拆解为自问题，并避免重复计算
