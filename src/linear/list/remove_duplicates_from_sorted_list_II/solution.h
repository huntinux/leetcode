#pragma once

#include "src/linear/list/common/list.h"

using list::Node;

// Given the head of a sorted linked list, delete all nodes that have duplicate
// numbers, leaving only distinct numbers from the original list. Return the
// linked list sorted as well.

class Solution {
 public:
  Node* DeleteDuplicates(Node* head);
};
