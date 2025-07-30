#include <iostream>
#include <string>

#include "tree.h"

int main() { return 0; }

// for test file

// // Test print_tree.
// TEST(PrintTreeTest2, BasicAssertions) {
//   tree::Tree tree;
//   tree.insert(5);
//   tree.insert(3);
//   tree.insert(7);
//   tree.insert(4);
//   tree.insert(1);
//   tree.insert(2);
//   tree.insert(8);
//   tree.insert(6);
//   EXPECT_STREQ("5 (0)
// 3 (5) 7 (5)
// 1 (3) 4 (3) 6 (7) 8 (7)
// 2 (1) %", tree.print_tree());
// }

// left-left balance test case
//   tree::Tree tree;
//   tree.insert(3);
//   tree.insert(2);
//   tree.insert(1);
//   tree.print_tree();
//   ASSERT_FALSE(is_balanced(tree));
//   left_left(tree);
//   tree.print_tree();
//   ASSERT_TRUE(is_balanced(tree));

// left-right balance test case
//   tree::Tree tree;
//   tree.insert(3);
//   tree.insert(1);
//   tree.insert(2);
//   tree.print_tree();
//   ASSERT_FALSE(is_balanced(tree));
//   left_left(tree);
//   tree.print_tree();
//   ASSERT_TRUE(is_balanced(tree));

// right-left balance test case
//   tree::Tree tree;
//   tree.insert(1);
//   tree.insert(3);
//   tree.insert(2);
//   tree.print_tree();
//   ASSERT_FALSE(is_balanced(tree));
//   left_left(tree);
//   tree.print_tree();
//   ASSERT_TRUE(is_balanced(tree));

// right-right balance test case
//   tree::Tree tree;
//   tree.insert(1);
//   tree.insert(2);
//   tree.insert(3);
//   tree.print_tree();
//   ASSERT_FALSE(is_balanced(tree));
//   left_left(tree);
//   tree.print_tree();
//   ASSERT_TRUE(is_balanced(tree));