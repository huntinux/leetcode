#include "solution.h"

// 解法1
//  先复制list，然后建立新老节点的映射关系
//  再根据映射关系恢复random指针
// 时间复杂度O(N), 空间复杂度O(N)

Node* Solution::copyRandomList(Node* head) {
  Node *copy_head = nullptr, *copy_tail = nullptr;
  std::unordered_map<Node*, Node*> mapping;
  for (Node* curr = head; curr; curr = curr->next) {
    Node* node = new Node(curr->val);
    mapping[curr] = node;
    if (copy_tail) {
      copy_tail->next = node;
      copy_tail = node;
    } else {
      copy_head = copy_tail = node;
    }
  }
  mapping[nullptr] = nullptr;
  for (Node *curr = head, *copy_curr = copy_head; curr && copy_curr;
       curr = curr->next, copy_curr = copy_curr->next) {
    copy_curr->random = mapping[curr->random];
  }
  return copy_head;
}

// 解法2
//   修改原始链表结构，把新节点放在老节点后面
//   后面恢复random指针就比较方便了
//   ref: https://leetcode-cn.com/problems/copy-list-with-random-pointer/solution/fu-zhi-dai-sui-ji-zhi-zhen-de-lian-biao-by-leetcod/
