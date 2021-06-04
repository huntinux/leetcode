#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  // Input: s = "leetcode", wordDict = ["leet","code"]
  // Output: true
  // Explanation: Return true because "leetcode" can be segmented as "leet code"
  //
  // Input: s = "applepenapple", wordDict = ["apple","pen"]
  // Output: true
  // Explanation: Return true because "applepenapple" can be segmented as "apple
  // pen apple".
  // Note that you are allowed to reuse a dictionary word."
  //
  // Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
  // Output: false
  bool WordBreak(string s, vector<string>& wordDict);
};
