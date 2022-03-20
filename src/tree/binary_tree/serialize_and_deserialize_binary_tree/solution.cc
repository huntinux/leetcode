#include "solution.h"

string Codec::serialize(TreeNode* root) {

}

vector<string> split(const string& data, char spliter) {
  // TODO
  vector<string> result;
  return result;
}

string next(const string& data, char spliter) {
  // TODO
  string result;
  return result;
}

const char* next(const char* data, char spliter) {
  const char* spliter_pos = strchr(data, spliter);
  if ()
  return pos;
}

// input: data = "1,2,3,N,N,4,5"
// output: root
//
// 分析
//  - data使用逗号进行切割，结果存放到数组nodes中
//  - 
TreeNode* Codec::deserialize_helper(const char* data) {
  //vector<string> nodes = split(data, ',');
  const char* node = next(data, ',');
  if (node.empty() || node == "N") return nullptr;
  TreeNode* root = new TreeNode(atoi(node.c_str()));
  root->left = 
}

