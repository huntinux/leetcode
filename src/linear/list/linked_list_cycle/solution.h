#pragma once

#include "src/linear/list/common/list.h"

using list::Node;

class Solution {
 public:
  bool HasCycle(Node* head);
  Node* DetectCycle(Node* head);
};
