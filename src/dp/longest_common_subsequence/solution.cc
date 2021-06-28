#include "solution.h"

// 分析
// 典型的二维动态规划
//
// 设dp[i][j]表示text1[0,i]和text2[0,j]的LCS值
//
// i = 0时，text1[0,i]为空串，空串与任意串的LCS=0, 即dp[0,j]=0
// 同理j = 0时，dp[i,0]=0
//
// 当text1[i] == text2[j]时
//  dp[i][j] = dp[i-1][j-1] + 1
// 否则
//  dp[i][j] = max(dp[i][j-1], dp[i-1][j])
//
//  例如：text1 = abcde text2 = ace, 下面用'_'表示空字符
//  则dp的初始状体为：
//    _ a b c d e
//  _ 0 0 0 0 0 0
//  a 0
//  c 0
//  e 0
//
//  循环i = 1; j = 1
//
//  * text1[1] == text2[1] == 'a'
//    dp[1][1] = dp[0][0] + 1 = 0 + 1 = 1
//  * text1[1] != text2[2]
//    dp[2][1] = max(dp[1][1], dp[2][0]) = max(1, 0) = 1
//  * ...
int Solution::longestCommonSubsequence(string text1, string text2) {
  int len1 = text1.length(), len2 = text2.length();
  int dp[len1 + 1]
        [len2 + 1];  // 注意申请的二维数组大小，为空字符串额外申请了一个位置
  for (int i = 0; i <= len1; ++i) {
    dp[i][0] = 0;
  }
  for (int j = 0; j <= len2; ++j) {
    dp[0][j] = 0;
  }

  int max_lcs = 0;
  for (int i = 1; i <= len1; ++i) {
    for (int j = 1; j <= len2; ++j) {
      if (text1[i - 1] == text2[j - 1]) {  // 注意这里的下标
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
      }
      if (dp[i][j] > max_lcs) max_lcs = dp[i][j];
    }
  }

  return max_lcs;
}
