#pragma once

#include "src/linear/list/common/list.h"

using list::Node;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  // Input: head = [4,2,1,3]
  // Output: [1,2,3,4]
  //
  // Can you sort the linked list in O(n logn) time and O(1) memory (i.e.
  // constant space)?
  Node* sortList(Node* head);

  Node* sortList(Node* begin, Node* end);
};
