#include "solution.h"

#include <bits/stdc++.h>

#include <iostream>

int Solution::atoi(const std::string& s) {
  // 先忽略开头的连续空格
  // 判断第一个字符是否合法： + - digit
  // 忽略开头连续的0
  // 接着逐位转换
  //  判断是否达到最大位数，如果超过了可以提前break
  // 转换结果先用int64_t存储，最后检查是否超过int32_t的范围

  static const char kSpace(' ');
  static const char kZero('0');
  static const int8_t kInt32MaxSlotNum = 10;

  int64_t result = 0;

  bool minus_flag = false;
  size_t start_pos = s.find_first_not_of(kSpace);
  size_t i_start = ((start_pos != std::string::npos) ? start_pos : 0);
  char ch = s[i_start];
  if (ch == '-') {
    minus_flag = true;
    ++i_start;
  } else if (ch == '+') {
    minus_flag = false;
    ++i_start;
  }

  start_pos = s.find_first_not_of(kZero, i_start);
  i_start = ((start_pos != std::string::npos) ? start_pos : i_start);

  int8_t slot_num = 0;
  size_t length = s.length();
  for (size_t i = i_start; i < length; ++i) {
    char ch = s[i];
    // std::cout << ch << std::endl;
    if (!std::isdigit(ch)) break;
    result = result * 10 + (ch - '0');
    if (++slot_num > kInt32MaxSlotNum)
      break;  // when remove thie leetcode return error:
              // runtime error: signed integer overflow:
              // 2000000000000000000 * 10 cannot be represented
              // in type 'long' (solution.cpp)
              // SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior
              // prog_joined.cpp:25:25
  }

  result *= (minus_flag ? -1 : 1);
  if (result < INT_MIN) return INT_MIN;
  if (result > INT_MAX) return INT_MAX;
  return result;
}

// from leetcode
int myAtoi(std::string str) {
  long result = 0;
  int indicator = 1;
  for (int i = 0; i < str.size();) {
    i = str.find_first_not_of(' ');
    if (str[i] == '-' || str[i] == '+') indicator = (str[i++] == '-') ? -1 : 1;
    while ('0' <= str[i] && str[i] <= '9') {
      result = result * 10 + (str[i++] - '0');
      if (result * indicator >= INT_MAX) return INT_MAX;
      if (result * indicator <= INT_MIN) return INT_MIN;
    }
    return result * indicator;
  }
}

int myAtoi2(std::string str) {
  int i = str.find_first_not_of(' ');

  if (str.empty() || i == -1) return 0;

  int ret = 0;
  int sign = 1;

  int base = INT_MAX / 10;

  if (str[i] == '+' || str[i] == '-') sign = str[i++] == '+' ?: -1;

  while (isdigit(str[i])) {
    if (ret > base || (ret == base && str[i] - '0' > 7))
      return sign > 0 ? INT_MAX : INT_MIN;
    ret = 10 * ret + (str[i++] - '0');
  }

  return sign * ret;
}
