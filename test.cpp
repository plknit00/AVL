#include "tree.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

// Test tree insert.
TEST(InsertTreeTest, BasicAssertions) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  ASSERT_TRUE(tree.empty());
  tree.insert(5);
  ASSERT_EQ(tree.print_tree(true), "5 (0,0) ");
  // fails
  ASSERT_FALSE(tree.empty());
}

// Test find.
TEST(FindTreeTest, BasicAssertions) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  ASSERT_FALSE(tree.find(5));
  tree.insert(5);
  ASSERT_TRUE(tree.find(5));
  ASSERT_FALSE(tree.find(2));
}

// Test is_balanced.
TEST(IsBalancedTreeTest, BasicAssertions) {
  tree::Tree tree;
  tree.insert(5);
  tree::Node *root = tree.get_root();
  ASSERT_TRUE(tree.is_balanced());
}

// Test is_balanced.
TEST(IsBalancedTreeTest2, BasicAssertions) {
  tree::Tree tree;
  tree.insert(5);
  tree.insert(4);
  tree::Node *root = tree.get_root();
  ASSERT_TRUE(tree.is_balanced());
}

// Test is_balanced.
TEST(IsBalancedTreeTest3, BasicAssertions) {
  tree::Tree tree;
  tree.insert(5);
  tree.insert(4);
  tree.insert(1);
  tree::Node *root = tree.get_root();
  ASSERT_TRUE(tree.is_balanced());
}

// // Test is_balanced.
TEST(IsBalancedTreeTest4, BasicAssertions) {
  tree::Tree tree;
  tree.insert(6);
  tree.insert(4);
  tree.insert(5);
  tree::Node *root = tree.get_root();
  ASSERT_TRUE(tree.is_balanced());
}

// Test AVL insert.
TEST(AVLInsertTest, BasicAssertions) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  tree.insert(6);
  tree.insert(5);
  tree.insert(4);
  tree.insert(3);
  tree.insert(2);
  tree.insert(1);
  ASSERT_TRUE(tree.is_balanced());
}

// Test AVL insert.
TEST(AVLInsertTest2, BasicAssertions) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  tree.insert(6);
  tree.insert(5);
  tree.insert(4);
  ASSERT_TRUE(tree.is_balanced());
}

// Test print.
TEST(PrintTreeTest, BasicAssertions) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  tree.insert(5);
  ASSERT_EQ(tree.print_tree(true), "5 (0,0) ");
}

// Test print.
TEST(PrintTreeTest2, BasicAssertions) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  tree.insert(5);
  tree.insert(5);
  ASSERT_EQ(tree.print_tree(true), "5 (0,0) ");
}

// Test print.
TEST(PrintTreeTest3, BasicAssertions) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  tree.insert(5);
  tree.insert(3);
  tree.insert(6);
  ASSERT_EQ(tree.print_tree(true), "5 (0,0) \n3 (5,0) 6 (5,0) ");
}

// Test AVL insert.
TEST(AVLPrintInsertTest, BasicAssertions) {
  tree::Tree tree;
  tree.insert(7);
  tree.insert(6);
  tree.insert(5);
  // tree.insert(4);
  // tree.insert(3);
  // tree.insert(2);
  // tree.insert(1);
  ASSERT_EQ(tree.print_tree(true),
            "4 (0,0) \n2 (4,0) 6 (4,0) \n1 (2,0) 3 (2,0) 5 (6,0) 7 (6,0) ");
}