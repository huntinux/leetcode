/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    // start: 09点27分
    // design-end:
    // coding-end: 
    // 题目要求的时间复杂度为 O(log(m+n)), 显然应该基于二分查找的思路实现
    // example
    //  1 3 | 2   -> 2
    //  1 3 | 2 4 -> (2+3) / 2 -> 2.5
    // 基本思路：借鉴二分查找的思路，不断缩小范围，用递归实现
    // 
    // 递归终止条件
    // - 两个数组任意一个为空，返回不空数组的第k个元素即可
    // - 两个数组都不空且只有一个元素，返回两数的平均值即可
    // 否则继续递归求解
    //  m = 2 n = 1 -> k = (2 + 1) / 2 = 1 -> find a[k] -> a[1]
    //  m = 2 n = 2 -> k = (2 + 2) / 2 = 2 -> find (a[k-1] + a[k]) / 2
    //
    // 经验：打不开思路是时候，举例子，一步一步找思路
    // example
    // A: 1 3 4* 9
    // B: 1 2 3* 4 5 6 7 8 9
    // LengthA = 4
    // LengthB = 9
    // Total = 13
    // k 表示第几个元素，主意k与数组下标的区别，k是从1开始，不是从0开始
    // k = Total / 2 + 1 = 7
    // 也就是找第 7 位的数字
    // k / 2 - 1 = 7 / 2 - 1 = 3 - 1 = 2 
    // A[2] = 4 > B[2] = 3
    // B[0..2] 不可能是第k位数字，删除掉缩小范围, 同时更新k（减去删掉的元素数量）
    // 
    // k = k - 3 = 4 
    // k / 2 - 1 = 1
    // A:         1 3* 4 9
    // B: [1 2 3] 4 5* 6 7 8 9
    // A[1] < B[1]
    // 删除 A[0,1]
    //
    // k = k - 2 = 2
    // k / 2 - 1 = 0 
    // A:   [1 3] 4* 9
    // B: [1 2 3] 4* 5 6 7 8 9
    // A[0] = B[0] return A[0]
    // 
    // 不断删除前面的元素，并且更新 K
    /*
    int find_kth(int A[], int len1, int B[], int len2, int k) {
        if (len1 == 0) return A[k - 1];
        if (len2 == 0) return B[k - 1];
        if (k == 1) return std::min(A[0], B[0]);
        int n = k / 2 - 1;
        int t1 = std::min(n, len1 - 1);
        int t2 = std::min(n, len2 - 1);
        int check1 = A[t1];
        int check2 = B[t2];
        if (check1 < check2) {
            return find_kth(A + t1 + 1, len1 - t1 - 1, B, len2, k - t1 - 1);
        } 
        return find_kth(A, len1, B + t2 + 1, len2 - t2 - 1, k - t2 - 1);
    }
    */

    // ref: https://leetcode.cn/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
    int find_kth(int A[], int m, int B[], int n, int k) {
      if (m > n) return find_kth(B, n, A, m, k); // 保证 A 比 B 短，后面好处理
      if (m == 0) return B[k - 1];               // A 为空，返回 B 中的第 K 个数即可
      if (k == 1) return std::min(A[0], B[0]);   // k = 1, 直接比较两个数组的首元素即可, 后面无法兼容这个边界情况

      // NOTE: 特别注意这里，A 比 B 短，k / 2 有可能比 m 大
      // ia + ib = k
      int ia = std::min(k / 2, m); // 防止下标溢出
      int ib = k - ia;
      if (A[ia - 1] < B[ib - 1]) { 
        // 排除不可能的元素，缩小查找范围，同时由于元素总个数减少，需要更新k值
        return find_kth(A + ia, m - ia, B, n, k - ia);
      } else if (A[ia - 1] > B[ib - 1]) {
        return find_kth(A, m, B + ib, n - ib, k - ib);
      }
      return A[ia - 1];
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int k = len / 2 + 1; // k 表示第几位元素，从1开始, 注意与数组下标不同
        if (len & 0x1) { // 奇数个元素
            return find_kth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), k);
        }  // 偶数个元素
        return (find_kth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), k - 1) +
                find_kth(nums1.data(), nums1.size(), nums2.data(), nums2.size(), k)) / 2.0;
    }
};
// @lc code=end

