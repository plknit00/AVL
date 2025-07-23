#pragma once

#include "tree.h"

class AVL {
public:
  // check if AVL tree is balanced
  bool is_balanced(tree::Node *root);

  void balance_avl_tree(tree::Node *root);

  tree::Node *left_left(tree::Node *root);

  tree::Node *left_right(tree::Node *root);

  tree::Node *right_left(tree::Node *root);

  tree::Node *right_right(tree::Node *root);
};
