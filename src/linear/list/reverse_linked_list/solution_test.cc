#include "solution.h"

#include <sstream>
#include <vector>

#include "gtest/gtest.h"

template <typename T>
static Node* BuildList(const std::vector<T>& elems) {
  Node* head = nullptr;
  Node* tail = nullptr;
  for (auto e : elems) {
    Node* node = new Node(e);
    if (!head) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }
  return head;
}

static void ReleaseList(Node* head) {
  Node* cur = head;
  while (cur) {
    Node* next = cur->next;
    delete cur;
    cur = next;
  }
}

static std::string DebugList(Node* head) {
  std::stringstream ss;
  Node* cur = head;
  while (cur) {
    ss << cur->value << "->";
    cur = cur->next;
  }
  ss << "NULL";
  return ss.str();
}

TEST(test, case1) {
  Solution s;
  EXPECT_EQ(nullptr, s.ReverseLinkedList(nullptr));
}

TEST(test, case2) {
  Solution s;
  Node* l1 = BuildList<int>({1});
  std::cout << DebugList(l1) << std::endl;
  Node* reversed_l1 = s.ReverseLinkedList(l1);
  std::string reversed_l1_str = DebugList(reversed_l1);
  std::cout << reversed_l1_str << std::endl;
  EXPECT_EQ("1->NULL", reversed_l1_str);
  ReleaseList(reversed_l1);
}

TEST(test, case3) {
  Solution s;
  Node* l1 = BuildList<int>({1, 2});
  std::cout << DebugList(l1) << std::endl;
  Node* reversed_l1 = s.ReverseLinkedList(l1);
  std::string reversed_l1_str = DebugList(reversed_l1);
  std::cout << reversed_l1_str << std::endl;
  EXPECT_EQ("2->1->NULL", reversed_l1_str);
  ReleaseList(reversed_l1);
}

TEST(test, case4) {
  Solution s;
  Node* l1 = BuildList<int>({1, 2, 3, 4, 5});
  std::cout << DebugList(l1) << std::endl;
  Node* reversed_l1 = s.ReverseLinkedListBetween(l1, 2, 4);
  std::string reversed_l1_str = DebugList(reversed_l1);
  std::cout << reversed_l1_str << std::endl;
  EXPECT_EQ("1->4->3->2->5->NULL", reversed_l1_str);
  ReleaseList(reversed_l1);
}

TEST(test, case5) {
  Solution s;
  Node* l1 = BuildList<int>({1, 2, 3, 4, 5});
  std::cout << DebugList(l1) << std::endl;
  Node* reversed_l1 = s.ReverseLinkedListBetween(l1, 1, 4);
  std::string reversed_l1_str = DebugList(reversed_l1);
  std::cout << reversed_l1_str << std::endl;
  EXPECT_EQ("4->3->2->1->5->NULL", reversed_l1_str);
  ReleaseList(reversed_l1);
}

TEST(test, case6) {
  Solution s;
  Node* l1 = BuildList<int>({1, 2, 3, 4, 5});
  std::cout << DebugList(l1) << std::endl;
  Node* reversed_l1 = s.ReverseLinkedListBetween(l1, 1, 5);
  std::string reversed_l1_str = DebugList(reversed_l1);
  std::cout << reversed_l1_str << std::endl;
  EXPECT_EQ("5->4->3->2->1->NULL", reversed_l1_str);
  ReleaseList(reversed_l1);
}

TEST(test, case7) {
  Solution s;
  Node* l1 = BuildList<int>({1, 2, 3, 4, 5});
  std::cout << DebugList(l1) << std::endl;
  Node* reversed_l1 = s.ReverseLinkedListBetween(l1, 2, 2);
  std::string reversed_l1_str = DebugList(reversed_l1);
  std::cout << reversed_l1_str << std::endl;
  EXPECT_EQ("1->2->3->4->5->NULL", reversed_l1_str);
  ReleaseList(reversed_l1);
}
