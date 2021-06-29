#include "solution.h"

// 分析
//
// 解法1
//  将A和B合并，然后返回kth元素
//  时间复杂度 O(m+n), 空间复杂度O(m+n)
//
// 解法2
//  双指针遍历：p1和p2分别指向A/B两个数组的开头,
//  叫小的往后一同，同时记录扫描的个数，当到达kth时，即为结果
//  时间复杂度 O(k)， 空间复杂度O(1), 最坏时间复杂度情况O(m+n)
//
// 解法3
//  类似二分查找，取A[t], B[t]比较, t = k/2 - 1
//    - A[t] < B[t], 则A[0..t]范围内的元素可以排除掉
//    - A[t] >= B[t], 则B[0..t]范围内的元素可以排除掉
//    - NOTE: A[t] == B[t], 这个可以归类到A[t] >= B[t]中
//    备注，排除元素后，k需要进行调整 k=k-k/2，因为我们排除了k/2个元素
//
//  可以写一个递归函数，则递归终止条件
//    - A 或 B为空，返回A[k-1] 或 B[k-1] 即可
//    - k = 1, 返回min(A[0], B[0]);

double Solution::findMedianSortedArrays(int A[], int m, int B[], int n) {
  int total = m + n;
  if (total & 0x1) {  // 总长度为基数
    return find_kth(A, m, B, n, total / 2 + 1);
  }
  return (find_kth(A, m, B, n, total / 2) +
          find_kth(A, m, B, n, total / 2 + 1)) /
         2.0;
}

int Solution::find_kth(int A[], int m, int B[], int n, int k) {
  if (m == 0) return B[k - 1];
  if (n == 0) return A[k - 1];
  if (k == 1) return std::min(A[0], B[0]);
  int t = k / 2 - 1;
  int ta = std::min(t, m - 1); // 注意下标的合法性
  int tb = std::min(t, n - 1);
  if (A[ta] < B[tb]) { 
    // 排除不可能的元素，缩小查找范围，同时由于元素总个数减少，需要更新k值
    return find_kth(A + ta + 1, m - ta - 1, B, n, k - ta - 1);
  }
  return find_kth(A, m, B + tb + 1, n - tb - 1, k - tb - 1);
  //} else if (A[ta] > B[tb]) {
  //  return find_kth(A, m, B + tb + 1, n - tb - 1, k - tb - 1);
  //}
  //return A[ta];
}
