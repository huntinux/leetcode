#include "solution.h"

// 分析
// 先扫描word，做一个反转，同时去掉多余的空格
// 最后对整体结果再做一次反转即可

string Solution::reverseWords(string s) {
  string result;
  size_t search_pos = 0;
  while (true) {
    // 找到一个合法的word起始位置，如果则结束循环
    // 注意search_pos每次要更新
    auto word_start_pos = s.find_first_not_of(kSpace, search_pos);
    if (word_start_pos == string::npos) {
      break;
    }
    auto word_end_pos = s.find_first_of(kSpace, word_start_pos);
    string word;
    if (word_end_pos == string::npos) { // 没有找到word结尾，有可能是到达string结尾了
      word = s.substr(word_start_pos);
    } else {
      word = s.substr(word_start_pos, word_end_pos - word_start_pos);
    }
    search_pos = word_end_pos;
    // std::cout << reverse(word) << std::endl;
    result.append(reverse(word)).append(" ");
  }
  // 注意去掉结尾多余的空格
  if (result.length() > 0 && result[result.length() - 1] == kSpace) {
    result.pop_back();
  }
  // 最后整体做一次反转
  return reverse(result);
}
