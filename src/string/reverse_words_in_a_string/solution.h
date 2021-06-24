#pragma once

#include <string>

using std::string;

const char kSpace(' ');

class Solution {
 public:
  string reverseWords(string s);
 private:
  string& reverse(string& s) {
    int len = s.length();
    for (int i = 0; i < len / 2; ++i) {
      //char ch = s[i];
      //s[i] = s[len - i - 1];
      //s[len - i - 1] = ch;
      std::swap(s[i], s[len - i - 1]);
    }
    return s;
  }
};
