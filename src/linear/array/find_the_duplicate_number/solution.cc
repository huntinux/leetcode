#include "solution.h"

// 分析
//
// nums中只有一个整数出现两次或多次，其余整数只出现一次
// nums.size=n+1
// 1<=nums[i]<=n
//
// Input: nums = [1,3,4,2,2]
// Output: 2
//
// 方法1：暴力搜索
// 对nums中的每个元素，查找是否在其他位置出现
// 时间复杂度O(N*N) 空间复杂度O(1)
//
// 方法2：hashmap
// 扫描nums，使用hashmap记录某个元素出现次数
// 时间复杂度O(N), 空间复杂度O(N)
//
// 方法3：充分利用已知条件
// 每个元素的value为1~n，那它可以作为下表
// 其中1<=n<=10^5
// int表示范围 2147483647 -2147483647
// int最大21亿
// 可以利用最高bit位代替hashmap的功能，最后再恢复即可

#define SET(x) (x |= (1 << 31))
#define CLEAR(x) (x &= ~(1 << 31))
#define CHECK(x) (x & (1 << 31))

int Solution::findDuplicate(vector<int>& nums) {
  int result = 0;
  int i = 0;
  for (; i < nums.size(); ++i) {
    int v = nums[i];
    CLEAR(v);
    if (CHECK(nums[v])) {
      result = v;
      break;
    }
    SET(nums[v]);
  }
  for (int j = 0; j <= i; ++j) {  // 避免不必要的CLEAR
    int v = nums[j];
    CLEAR(v);
    CLEAR(nums[v]);
  }
  return result;
}

// 解法4
// 联想list中的环检测题目, 又学到了...
// 其实，快慢指针法，就是一种 映射 操作， 链表 里面的 一次映射操作，就是 求
// next，且 将位置 更新到 这里； 数组 这里，就是 根据 下标 i 求 nums[i]
// 这个元素值，且 将 下标 更新到这里。
// 链表里面 有环，即 一个节点 被不同的 节点指向（映射）； 而 这里说的 数组
// 有环，即 数组中的一个元素值 被不同的 index 指向（映射）； 所以，求解方法
// 一样可以 使用 快慢指针法。
//
// The main idea is the same with problem Linked List
// Cycle II,https://leetcode.com/problems/linked-list-cycle-ii/. Use two
// pointers the fast and the slow. The fast one goes forward two steps each
// time, while the slow one goes only step each time. They must meet the same
// item when slow==fast. In fact, they meet in a circle, the duplicate number
// must be the entry point of the circle when visiting the array from nums[0].
// Next we just need to find the entry point. We use a point(we can use the fast
// one before) to visit form begining with one step each time, do the same job
// to slow. When fast==slow, they meet at the entry point of the circle. The
// easy understood code is as follows.
int findDuplicate(vector<int>& nums) {
  if (nums.size() > 1) {
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast) {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    fast = 0;
    while (fast != slow) {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
  return -1;
}

// 解法5：
// 二分查找，cnt[i]为小于等于i的个数统计
// cnt[i] 为递增序列，只需要找到以一个不连续的点
//
// 时间复杂度 O(NlogN) 空间复杂度O(1)
// ref:
// https://leetcode-cn.com/problems/find-the-duplicate-number/solution/xun-zhao-zhong-fu-shu-by-leetcode-solution/
int findDuplicate2(vector<int>& nums) {
  int n = nums.size();
  int l = 1, r = n - 1, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += nums[i] <= mid;
    }
    if (cnt <= mid) {  // 答案在右边
      l = mid + 1;
    } else {
      r = mid - 1;
      ans = mid;
    }
  }
  return ans;
}
