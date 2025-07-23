#pragma once

#include "tree.h"

class AVL {
public:
  bool check_balance();

  void balance_avl_tree();

  tree::Node *left_left();

  tree::Node *left_right();

  tree::Node *right_left();

  tree::Node *right_right();
};
