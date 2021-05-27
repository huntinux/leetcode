#include "solution.h"

#include <sstream>
#include <vector>

#include "gtest/gtest.h"

TEST(test, case1) {
  LruCache cache(2);
  cache.put(1, 10);
  EXPECT_EQ(10, cache.get(1));
  EXPECT_EQ(1, cache.size());
  cache.put(1, 10);
  EXPECT_EQ(10, cache.get(1));
  EXPECT_EQ(1, cache.size());
  cache.put(2, 20);
  EXPECT_EQ(10, cache.get(1));
  EXPECT_EQ(20, cache.get(2));
  EXPECT_EQ(2, cache.size());
  cache.put(3, 30);
  EXPECT_EQ(2, cache.size());
  EXPECT_EQ(30, cache.get(3));
  EXPECT_EQ(20, cache.get(2));
  EXPECT_EQ(-1, cache.get(1));
}
