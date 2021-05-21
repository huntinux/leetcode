#include "solution.h"

#include <unordered_set>

// 借助hashmap
// bool Solution::HasCycle(Node* head) {
//  if (head == nullptr || head->next == nullptr)
//    return false;
//  std::unordered_set<Node*> s;
//  Node* cur = head;
//  while (cur) {
//    if (s.find(cur) != s.end()) {
//      return true;
//    } else {
//      s.insert(cur);
//    }
//    cur = cur->next;
//  }
//  return false;
//}

// 快慢指针
// 如果有环，快慢指针一定会相遇
bool Solution::HasCycle(Node* head) {
  if (head == nullptr || head->next == nullptr) return false;
  Node *fast, *slow;
  fast = slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) return true;
  }
  return false;
}

// 如果有环，返回起始节点，否则返回null
// 还是快慢指针
// 假设存在环，当fast与slow相遇时，slow肯定还没有走完一圈，fast走了好几圈。
// 设 slow走了s步，则fast走了2s, 环长r, fast走了n圈
// 2s = s + nr
// 则 s = nr
// 设整个链表长L， 环入口与相遇点距离为a，起始点到环入口点距离为x， 则
// x + a = s = nr = (n-1)r + r = (n-1)r + L - x
// x = (n-1)r + L - x - a
// L - x - a 为相遇点到环入口的距离。
// 由此可知，从链表头到环入口点等于 （n-1）圈内环 + 相遇点到环入口点
// 于是，我们可以从head设置一个slow2，
// 两个慢指针每次前进一步，最后相遇处就是环入口处
Node* Solution::DetectCycle(Node* head) {
  //if (head == nullptr || head->next == nullptr) return nullptr;
  Node *fast, *slow;
  fast = slow = head;
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      Node* slow2 = head;
      while (slow != slow2) {
        slow = slow->next;
        slow2 = slow2->next;
      }
      return slow;
    }
  }
  return nullptr;
}

