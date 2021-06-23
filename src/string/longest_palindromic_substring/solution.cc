#include "solution.h"

#include <vector>

using std::vector;

// 分析
// 解法1：暴力搜索，遍历所有字串，判断是否为回文，同时记录最大长度，
//        时间复杂度为O(n^3)
//
// 解法2：动态规划 (空间换时间，充分利用之前的结果)
//
//  dp[i][j] : s[i..j] 是否为回文，值为true或false
//  dp[i][j] = true if s[i] == s[j] and dp[i+1][j-1] == true;
//           = false s[i] != s[j] or dp[i+1][j-1] == false;
//
//  最后任务转化为填写二维表格的过程
// 
string Solution::longestPalindrome(const string& s) {
  int len = s.length();
  if (len <= 1) return s;
  //vector<vector<bool>> dp(len, vector<bool>(len, false));
  bool dp[len][len];
  for (int i = 0; i < len; ++i) {
    dp[i][i] = true; // 对角线数据单个字符，肯定是回文
  }

  int max_start = 0, max_size = 0;
  for (int j = 1; j < len; ++j) { // 从第一列开始
    for (int i = 0; i < len; ++i) {
      if (s[i] == s[j]) {
        if (j - i <= 2) { // s[i..j] 范围内只有2个活以内的字符，这种情况肯定是回文
          dp[i][j] = true;
        } else {
          dp[i][j] = dp[i + 1][j - 1];
        }
        if (dp[i][j]) {
          int size = j - i + 1;
          if (size > max_size) {
            max_start = i;
            max_size = size;
          }
        }
      } else {
        dp[i][j] = false;
      }
    }
  }

  return s.substr(max_start, max_size);
}

