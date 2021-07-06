#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string validIPAddress(string IP);

  bool validIPv4Address(const string& IP);
  bool validIPv6Address(const string& IP);
  vector<string> split(const string& s, char delimiter);
};
