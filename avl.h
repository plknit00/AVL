#pragma once

#include "tree.h"

class AVL {
public:
  static bool is_avl(tree::Node *root);

  static bool is_balanced(tree::Node *root);

  static bool is_sorted(tree::Node *root);

  static void *left_left(tree::Node *root);

  static void *left_right(tree::Node *root);

  static void *right_left(tree::Node *root);

  static void *right_right(tree::Node *root);

  // add a value to the tree, if it is not duplicate
  static void insert(tree::Node *root, int value);
};
