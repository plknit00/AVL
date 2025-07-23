#include "avl.h"
#include "tree.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

// Test insert.
TEST(InsertTreeTest, BasicAssertions) {
  tree::Tree tree;
  ASSERT_TRUE(tree.empty());
  tree.insert(5);
  ASSERT_FALSE(tree.empty());
}

// Test find.
TEST(FindTreeTest, BasicAssertions) {
  tree::Tree tree;
  ASSERT_FALSE(tree.find(5));
  tree.insert(5);
  ASSERT_TRUE(tree.find(5));
  ASSERT_FALSE(tree.find(2));
}

// // Test print.
// TEST(PrintTreeTest, BasicAssertions) {
//   tree::Tree tree;
//   tree.insert(5);
//   ASSERT_EQ(tree.print_tree(), "5 (0) ");
// }