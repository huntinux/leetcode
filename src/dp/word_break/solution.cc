#include "solution.h"

#include <unordered_set>

using std::unordered_set;

// 分析
//
// Input: s = "leetcode", wordDict = ["leet","code"]
//
// n为字符串长度
// f[i]: s[0,i) 的substring是否可以wordbreak
// 1 <= i < n
// f[0] = true, 长度为0的子串默认可以wordbreak, 这是个初始条件
//
// 那么状态转移方程为：
// f[i] = f[i - j] + s[j, i]
// 其中 1 <= j <= i
// f[i - j] 为true 且 s[j,i] 在dict中出现
bool Solution::WordBreak(string s, vector<string>& wordDict) {
  int n = s.length();
  unordered_set<string> word_set(wordDict.begin(), wordDict.end());
  vector<bool> dp(n + 1, false);
  dp[0] = true;
  for (int i = 1; i <= n; ++i) {
    for (int j = i - 1; j >= 0; --j) {
      if (dp[j]) {
        string sub = s.substr(j, i - j);
        if (word_set.find(sub) != word_set.end()) {
          dp[i] = true;
          break;  // try next i;
        }
      }
    }
  }
  return dp[s.size()];
}

// from leetcode
// We use a boolean vector dp[]. dp[i] is set to true if a valid word (word
// sequence) ends there. The optimization is to look from current position i
// back and only substring and do dictionary look up in case the preceding
// position j with dp[j] == true is found.)]]
//
// NOTE: 解读，正常时从后往前分析，这里利用dp算法，需要从后往前分析，复用利用前面的结果

bool wordBreak(string s, unordered_set<string>& dict) {
  if (dict.size() == 0) return false;

  vector<bool> dp(s.size() + 1, false);
  dp[0] = true;

  for (int i = 1; i <= s.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (dp[j]) {
        string word = s.substr(j, i - j);
        if (dict.find(word) != dict.end()) {
          dp[i] = true;
          break;  // next i
        }
      }
    }
  }

  return dp[s.size()];
}

