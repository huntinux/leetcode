#include "solution.h"

#include <sstream>
#include <vector>

#include "gtest/gtest.h"

using namespace list;

TEST(test, case1) {
  Solution s;
  Node n1(4);
  Node n2(3);
  Node n3(2);
  Node n4(1);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  s.sortList(&n1);
}
