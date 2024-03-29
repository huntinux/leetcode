#include "solution.h"

// ref:
// https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/trie-tree-de-shi-xian-gua-he-chu-xue-zhe-by-huwt/

class Trie {
 private:
  bool isEnd;
  Trie* next[26];

 public:
  Trie() {
    isEnd = false;
    memset(next, 0, sizeof(next));
  }

  ~Trie() { clear(root); }

  void insert(string word) {
    Trie* node = this;
    for (char c : word) {
      if (node->next[c - 'a'] == NULL) {
        node->next[c - 'a'] = new Trie();
      }
      node = node->next[c - 'a'];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    Trie* node = this;
    for (char c : word) {
      node = node->next[c - 'a'];
      if (node == NULL) {
        return false;
      }
    }
    return node->isEnd;
  }

  bool startsWith(string prefix) {
    Trie* node = this;
    for (char c : prefix) {
      node = node->next[c - 'a'];
      if (node == NULL) {
        return false;
      }
    }
    return true;
  }

  void clear(Trie* root) {
    for (int i = 0; i < 26; i++) {
      if (root->next[i] != nullptr) {
        clear(root->next[i]);
      }
    }
    delete root;
  }
};
