#include "solution.h"

#include <sstream>
#include <vector>

#include "gtest/gtest.h"

using namespace list;

TEST(test, case1) {
  Solution s;
  EXPECT_EQ(nullptr, s.DeleteDuplicates(nullptr));
}

TEST(test, case2) {
  Solution s;
  Node* l1 = BuildList<int>({1});
  std::cout << DebugList(l1) << std::endl;
  Node* l2 = s.DeleteDuplicates(l1);
  std::string l2_str = DebugList(l2);
  std::cout << "result:" << l2_str << std::endl;
  EXPECT_EQ("1->NULL", l2_str);
}

TEST(test, case3) {
  Solution s;
  Node* l1 = BuildList<int>({1, 1});
  std::cout << DebugList(l1) << std::endl;
  Node* l2 = s.DeleteDuplicates(l1);
  std::string l2_str = DebugList(l2);
  std::cout << "result:" << l2_str << std::endl;
  EXPECT_EQ("1->NULL", l2_str);
}

TEST(test, case4) {
  Solution s;
  Node* l1 = BuildList<int>({1, 1, 2});
  std::cout << DebugList(l1) << std::endl;
  Node* l2 = s.DeleteDuplicates(l1);
  std::string l2_str = DebugList(l2);
  std::cout << "result:" << l2_str << std::endl;
  EXPECT_EQ("1->2->NULL", l2_str);
}

TEST(test, case5) {
  Solution s;
  Node* l1 = BuildList<int>({1, 1, 2, 2});
  std::cout << DebugList(l1) << std::endl;
  Node* l2 = s.DeleteDuplicates(l1);
  std::string l2_str = DebugList(l2);
  std::cout << "result:" << l2_str << std::endl;
  EXPECT_EQ("1->2->NULL", l2_str);
}

TEST(test, case6) {
  Solution s;
  Node* l1 = BuildList<int>({1, 1, 1, 2, 2});
  std::cout << DebugList(l1) << std::endl;
  Node* l2 = s.DeleteDuplicates(l1);
  std::string l2_str = DebugList(l2);
  std::cout << "result:" << l2_str << std::endl;
  EXPECT_EQ("1->2->NULL", l2_str);
}

TEST(test, case7) {
  Solution s;
  Node* l1 = BuildList<int>({1, 1, 1, 2, 2, 2, 3});
  std::cout << DebugList(l1) << std::endl;
  Node* l2 = s.DeleteDuplicates(l1);
  std::string l2_str = DebugList(l2);
  std::cout << "result:" << l2_str << std::endl;
  EXPECT_EQ("1->2->3->NULL", l2_str);
}
