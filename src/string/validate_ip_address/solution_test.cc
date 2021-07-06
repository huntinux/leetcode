#include "solution.h"

#include "gtest/gtest.h"

TEST(test, case1) {
  Solution s;
  string ip("1.2.3.4");
  vector<string> items = s.split(ip, '.');
  EXPECT_EQ(4, items.size());
  EXPECT_EQ("1", items[0]);
  EXPECT_EQ("2", items[1]);
  EXPECT_EQ("3", items[2]);
  EXPECT_EQ("4", items[3]);
}

TEST(test, case2) {
  Solution s;
  string ip("1.2.3.4");
  EXPECT_EQ(true, s.validIPv4Address(ip));
}

TEST(test, case3) {
  Solution s;
  string ip("1.2.3.");
  EXPECT_EQ(false, s.validIPv4Address(ip));
}

TEST(test, case4) {
  Solution s;
  string ip("1.2.3.04");
  EXPECT_EQ(false, s.validIPv4Address(ip));
}

TEST(test, case5) {
  Solution s;
  string ip("1.2.3.256");
  EXPECT_EQ(false, s.validIPv4Address(ip));
}

TEST(test, case6) {
  Solution s;
  string ip("1.2.3");
  EXPECT_EQ(false, s.validIPv4Address(ip));
}

TEST(test, case7) {
  Solution s;
  string ip("2001:0db8:85a3:0:0:8A2E:0370:7334");
  EXPECT_EQ("IPv6", s.validIPAddress(ip));
}

TEST(test, case8) {
  Solution s;
  string ip("2001:0db8:85a3:0:0:8A2E:0370:7334:");
  EXPECT_EQ("Neither", s.validIPAddress(ip));
}
