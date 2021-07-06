#include "solution.h"

#include <vector>

using std::vector;

string Solution::validIPAddress(string IP) {
  return validIPv4Address(IP) ? "IPv4"
                              : (validIPv6Address(IP) ? "IPv6" : "Neither");
}

vector<string> Solution::split(const string& s, char delimiter) {
  vector<string> res;
  size_t search_pos = 0;
  size_t delimiter_pos = std::string::npos;
  while ((delimiter_pos = s.find_first_of(delimiter, search_pos)) !=
         std::string::npos) {
    res.push_back(s.substr(search_pos, delimiter_pos - search_pos));
    search_pos = delimiter_pos + 1;
  }
  res.push_back(s.substr(search_pos));
  return res;
}

bool Solution::validIPv4Address(const string& IP) {
  vector<string> items = split(IP, '.');
  if (items.size() != 4) return false;
  for (const auto& item : items) {
    if (item.empty() || item.size() > 3 ||
        (item.size() > 1 && item[0] == '0')) {
      return false;
    }
    for (auto c : item) {
      if (!isdigit(c)) return false;
    }
    int n = atoi(item.c_str());
    if (n > 255) return false;
  }
  return true;
}

bool Solution::validIPv6Address(const string& IP) {
  vector<string> items = split(IP, ':');
  if (items.size() != 8) return false;
  for (const auto& item : items) {
    if (item.empty() || item.size() > 4) return false;
    for (auto c : item) {
      if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')) return false; 
    }
  }
  return true;
}
/*
参考：
https://leetcode.com/problems/validate-ip-address/discuss/689995/C%2B%2B-Regex-Solution-4-lines-of-code-Time-and-Space-O(1)-beats-100
讲解了c++正则表达式的使用
*/
