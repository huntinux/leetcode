#pragma once

#include <string>

class Solution {
 public:
  // Input: s = "42"
  // Output: 42
  //
  // Input: s = "   -42"
  // Output: -42
  //
  // Input: s = "4193 with words"
  // Output: 4193
  //
  // Input: s = "words and 987"
  // Output: 0
  //
  // Input: s = "-91283472332"
  // Output: -2147483648
  // Explanation:
  // Step 1: "-91283472332" (no characters read because there is no leading
  // whitespace)
  //         ^
  // Step 2: "-91283472332" ('-' is read, so the result should be
  // negative)
  // ^
  // Step 3: "-91283472332" ("91283472332" is read in)
  //         ^
  //         The parsed integer is -91283472332.
  //         Since -91283472332 is less than the
  //         lower bound of the range [-2^31, 2^31- 1], the final result is clamped to
  //         -2^31 = -2147483648.
  //
  // 0 <= s.length <= 200
  // s consists of English letters (lower-case and upper-case), digits
  // (0-9), ' ', '+', '-', and '.'.
  // 
  // Input: "  0000000000012345678"
  // Output: 12345678 
  int atoi(const std::string& s);
};

