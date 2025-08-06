#include "tree.h"
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(BasicAssertions, HelloTest) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

TEST(BasicAssertions, InsertTest) {
  tree::Tree tree;
  ASSERT_TRUE(tree.empty());
  tree.insert(5);
  ASSERT_EQ(tree.print_tree(true), "5 (0,0) ");
  ASSERT_FALSE(tree.empty());
}

TEST(BasicAssertions, FindTreeTest) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  ASSERT_FALSE(tree.find(5));
  tree.insert(5);
  ASSERT_TRUE(tree.find(5));
  ASSERT_FALSE(tree.find(2));
}

TEST(BasicAssertions, IsAVLTest) {
  tree::Tree tree;
  ASSERT_TRUE(tree.is_avl());
  tree.insert(1);
  ASSERT_TRUE(tree.is_avl());
}

TEST(BasicAssertions, IsBalancedTreeTest) {
  tree::Tree tree;
  tree.insert(5);
  tree::Node *root = tree.get_root();
  ASSERT_TRUE(tree.is_balanced());
}

TEST(BasicAssertions, IsBalancedTreeTest2) {
  tree::Tree tree;
  tree.insert(5);
  tree.insert(4);
  tree::Node *root = tree.get_root();
  ASSERT_TRUE(tree.is_balanced());
}

TEST(BasicAssertions, IsBalancedTreeTest3) {
  tree::Tree tree;
  tree.insert(5);
  tree.insert(4);
  tree.insert(1);
  tree::Node *root = tree.get_root();
  ASSERT_TRUE(tree.is_balanced());
}

TEST(BasicAssertions, IsBalancedTreeTest4) {
  tree::Tree tree;
  tree.insert(6);
  tree.insert(4);
  tree.insert(5);
  tree::Node *root = tree.get_root();
  ASSERT_TRUE(tree.is_balanced());
}

TEST(BasicAssertions, InsertTest2) {
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

TEST(BasicAssertions, InsertTest3) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  tree.insert(6);
  tree.insert(5);
  tree.insert(4);
  ASSERT_TRUE(tree.is_balanced());
}

TEST(BasicAssertions, PrintTreeTest) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  tree.insert(5);
  ASSERT_EQ(tree.print_tree(true), "5 (0,0) ");
}

TEST(BasicAssertions, PrintTreeTest2) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  tree.insert(5);
  tree.insert(5);
  ASSERT_EQ(tree.print_tree(true), "5 (0,0) ");
}

TEST(BasicAssertions, PrintTreeTest3) {
  tree::Tree tree;
  tree::Node *root = tree.get_root();
  tree.insert(5);
  tree.insert(3);
  tree.insert(6);
  ASSERT_EQ(tree.print_tree(true), "5 (0,0) \n3 (5,0) 6 (5,0) ");
}

TEST(BasicAssertions, PrintInsertTest) {
  tree::Tree tree;
  tree.insert(7);
  tree.insert(6);
  tree.insert(5);
  tree.insert(4);
  tree.insert(3);
  tree.insert(2);
  tree.insert(1);
  ASSERT_EQ(tree.print_tree(true),
            "4 (0,0) \n2 (4,0) 6 (4,0) \n1 (2,0) 3 (2,0) 5 (6,0) 7 (6,0) ");
}

TEST(BasicAssertions, InsertLeftLeftTest) {
  tree::Tree tree;
  tree.insert(3);
  tree.insert(2);
  tree.insert(1);
  ASSERT_EQ(tree.print_tree(true), "2 (0,0) \n1 (2,0) 3 (2,0) ");
  ASSERT_TRUE(tree.is_avl());
}

TEST(BasicAssertions, InsertRightRightTest) {
  tree::Tree tree;
  tree.insert(1);
  tree.insert(2);
  tree.insert(3);
  ASSERT_EQ(tree.print_tree(true), "2 (0,0) \n1 (2,0) 3 (2,0) ");
  ASSERT_TRUE(tree.is_avl());
}

TEST(BasicAssertions, InsertLeftRightTest) {
  tree::Tree tree;
  tree.insert(3);
  tree.insert(1);
  tree.insert(2);
  ASSERT_EQ(tree.print_tree(true), "2 (0,0) \n1 (2,0) 3 (2,0) ");
  ASSERT_TRUE(tree.is_avl());
}

TEST(BasicAssertions, InsertRightLeftTest) {
  tree::Tree tree;
  tree.insert(3);
  tree.insert(1);
  tree.insert(2);
  ASSERT_EQ(tree.print_tree(true), "2 (0,0) \n1 (2,0) 3 (2,0) ");
  ASSERT_TRUE(tree.is_avl());
}

TEST(BasicAssertions, RemoveEmptyTest) {
  tree::Tree tree;
  tree.insert(30);
  tree.remove(20);
  ASSERT_FALSE(tree.empty());
  tree.remove(30);
  ASSERT_TRUE(tree.empty());
}

TEST(BasicAssertions, RemoveLeftRightTest) {
  tree::Tree tree;
  tree.insert(3);
  tree.insert(1);
  tree.insert(4);
  tree.insert(2);
  ASSERT_EQ(tree.print_tree(true), "3 (0,1) \n1 (3,-1) 4 (3,0) \n2 (1,0) ");
  ASSERT_TRUE(tree.remove(4));
  ASSERT_EQ(tree.print_tree(true), "2 (0,0) \n1 (2,0) 3 (2,0) ");
}

TEST(BasicAssertions, RemoveRightLeftTest) {
  tree::Tree tree;
  tree.insert(2);
  tree.insert(1);
  tree.insert(4);
  tree.insert(3);
  ASSERT_EQ(tree.print_tree(true), "2 (0,-1) \n1 (2,0) 4 (2,1) \n3 (4,0) ");
  ASSERT_TRUE(tree.remove(1));
  ASSERT_EQ(tree.print_tree(true), "3 (0,0) \n2 (3,0) 4 (3,0) ");
}

TEST(BasicAssertions, RemoveLeftLeftTest) {
  tree::Tree tree;
  tree.insert(3);
  tree.insert(2);
  tree.insert(4);
  tree.insert(1);
  ASSERT_EQ(tree.print_tree(true), "3 (0,1) \n2 (3,1) 4 (3,0) \n1 (2,0) ");
  ASSERT_TRUE(tree.remove(4));
  ASSERT_EQ(tree.print_tree(true), "2 (0,0) \n1 (2,0) 3 (2,0) ");
}

TEST(BasicAssertions, RemoveRightRightTest) {
  tree::Tree tree;
  tree.insert(2);
  tree.insert(1);
  tree.insert(3);
  tree.insert(4);
  ASSERT_EQ(tree.print_tree(true), "2 (0,-1) \n1 (2,0) 3 (2,-1) \n4 (3,0) ");
  ASSERT_TRUE(tree.remove(1));
  ASSERT_EQ(tree.print_tree(true), "3 (0,0) \n2 (3,0) 4 (3,0) ");
}

TEST(BasicAssertions, RemoveLeftLeftTestBig) {
  tree::Tree tree;
  tree.insert(20);
  tree.insert(10);
  tree.insert(30);
  tree.insert(5);
  tree.insert(15);
  tree.insert(25);
  tree.insert(2);
  tree.insert(7);
  tree.insert(12);
  tree.insert(17);
  ASSERT_TRUE(tree.find(5));
  ASSERT_FALSE(tree.find(3));
  ASSERT_TRUE(tree.find(25));
  ASSERT_EQ(tree.print_tree(true),
            "20 (0,1) \n10 (20,0) 30 (20,1) \n5 (10,0) 15 (10,0) 25 (30,0) "
            "\n2 (5,0) 7 (5,0) 12 (15,0) 17 (15,0) ");
  tree.remove(25);
  ASSERT_FALSE(tree.find(25));
  ASSERT_EQ(tree.print_tree(true),
            "10 (0,-1) \n5 (10,0) 20 (10,1) \n2 (5,0) 7 (5,0) 15 (20,0) 30 "
            "(20,0) \n12 (15,0) 17 (15,0) ");
}

TEST(BasicAssertions, RemoveRightRightTestBig) {
  tree::Tree tree;
  tree.insert(44);
  tree.insert(17);
  tree.insert(62);
  tree.insert(32);
  tree.insert(50);
  tree.insert(78);
  tree.insert(48);
  tree.insert(54);
  tree.insert(70);
  tree.insert(88);
  ASSERT_EQ(tree.print_tree(true),
            "44 (0,-1) \n17 (44,-1) 62 (44,0) \n32 (17,0) 50 (62,0) 78 (62,0) "
            "\n48 (50,0) 54 (50,0) 70 (78,0) 88 (78,0) ");
  ASSERT_TRUE(tree.remove(32));
  ASSERT_EQ(
      tree.print_tree(true),
      "62 (0,1) \n44 (62,-1) 78 (62,0) \n17 (44,0) 50 (44,0) 70 (78,0) 88 "
      "(78,0) \n48 (50,0) 54 (50,0) ");
}

TEST(BasicAssertions, RemoveLeftRightTestBig) {
  tree::Tree tree;
  tree.insert(30);
  tree.insert(15);
  tree.insert(40);
  tree.insert(10);
  tree.insert(22);
  tree.insert(35);
  tree.insert(45);
  tree.insert(20);
  tree.insert(25);
  ASSERT_TRUE(tree.is_avl());
  ASSERT_EQ(
      tree.print_tree(true),
      "30 (0,1) \n15 (30,-1) 40 (30,0) \n10 (15,0) 22 (15,0) 35 (40,0) 45 "
      "(40,0) \n20 (22,0) 25 (22,0) ");
  ASSERT_TRUE(tree.remove(40));
  ASSERT_TRUE(tree.is_avl());
  ASSERT_EQ(tree.print_tree(true),
            "30 (0,1) \n15 (30,-1) 45 (30,1) \n10 (15,0) "
            "22 (15,0) 35 (45,0) \n20 (22,0) 25 (22,0) ");
  // ASSERT_TRUE(tree.remove(45));
  // ASSERT_TRUE(tree.is_avl());
  // ASSERT_EQ(tree.print_tree(true),
  //           "22 (0,0) \n15 (22,0) 30 (22,0) \n10 (15,0) 20 (15,0) 25 (30,0)
  //           35 "
  //           "(30,0) ");
}

// TEST(BasicAssertions, RemoveRightLeftTestBig) {
//   tree::Tree tree;
//   tree.insert(4);
//   ASSERT_TRUE(tree.is_avl());
//   ASSERT_EQ(tree.print_tree(true), " ");
// }

// TEST(BasicAssertions, InsertLeftRightTestBig) {
//   tree::Tree tree;
//   tree.insert(4);
//   ASSERT_TRUE(tree.is_avl());
//   ASSERT_EQ(tree.print_tree(true), " ");
// }

// TEST(BasicAssertions, InsertRightLeftTestBig) {
//     tree::Tree tree;
//   tree.insert(4);
//   ASSERT_TRUE(tree.is_avl());
//   ASSERT_EQ(tree.print_tree(true), " ");
// }

// TEST(BasicAssertions, InsertLeftLeftTestBig) {
//     tree::Tree tree;
//   tree.insert(4);
//   ASSERT_TRUE(tree.is_avl());
//   ASSERT_EQ(tree.print_tree(true), " ");
// }

// TEST(BasicAssertions, InsertRightRightTestBig) {
//     tree::Tree tree;
//   tree.insert(4);
//   ASSERT_TRUE(tree.is_avl());
//   ASSERT_EQ(tree.print_tree(true), " ");
// }

TEST(BasicAssertions, RemoveMiddleEltTestBig) {
  tree::Tree tree;
  tree.insert(40);
  tree.insert(20);
  tree.insert(60);
  tree.insert(10);
  tree.insert(30);
  tree.insert(50);
  tree.insert(70);
  tree.insert(5);
  tree.insert(15);
  tree.insert(25);
  tree.insert(35);
  tree.insert(45);
  tree.insert(55);
  tree.insert(65);
  tree.insert(75);
  ASSERT_EQ(tree.print_tree(true),
            "40 (0,0) \n20 (40,0) 60 (40,0) \n10 (20,0) 30 (20,0) 50 (60,0) 70 "
            "(60,0) \n5 (10,0) 15 (10,0) 25 (30,0) 35 (30,0) 45 (50,0) 55 "
            "(50,0) 65 (70,0) 75 (70,0) ");
  tree.remove(60);
  ASSERT_TRUE(tree.is_avl());
  ASSERT_EQ(tree.print_tree(true),
            "40 (0,0) \n20 (40,0) 65 (40,0) \n10 (20,0) 30 (20,0) 50 (65,0) 70 "
            "(65,-1) \n5 (10,0) 15 (10,0) 25 (30,0) 35 (30,0) 45 (50,0) 55 "
            "(50,0) 75 (70,0) ");
}

// TEST(BasicAssertions, RemoveMiddleEltLLTestBig) {
//     tree::Tree tree;
//   tree.insert(4);
//   ASSERT_TRUE(tree.is_avl());
//   ASSERT_EQ(tree.print_tree(true), " ");
// }

// TEST(BasicAssertions, RemoveMiddleEltLRTestBig) {
//     tree::Tree tree;
//   tree.insert(4);
//   ASSERT_TRUE(tree.is_avl());
//   ASSERT_EQ(tree.print_tree(true), " ");
// }

// TEST(BasicAssertions, RemoveMiddleEltRLTestBig) {
//     tree::Tree tree;
//   tree.insert(4);
//   ASSERT_TRUE(tree.is_avl());
//   ASSERT_EQ(tree.print_tree(true), " ");
// }

// TEST(BasicAssertions, RemoveMiddleEltRRTestBig) {
//     tree::Tree tree;
//   tree.insert(4);
//   ASSERT_TRUE(tree.is_avl());
//   ASSERT_EQ(tree.print_tree(true), " ");
// }