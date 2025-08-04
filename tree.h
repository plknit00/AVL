#pragma once

#include <queue>
#include <string>

namespace tree {

struct Node {
  int value = 0;
  Node *left = nullptr;
  Node *right = nullptr;
  int height = 0;
};

class Tree {

public:
  bool empty();

  Node *get_root();

  int get_height(Node *node);

  int get_balance_factor(Node *node);

  Node *find(int value);

  // add a value to the tree, if it is not duplicate
  void insert(int value);

  // remove a value from the tree, if it exists
  void remove(int value);

  // bfs algorithm, prints tree with parent node, right/left child,
  // and balance factor specified
  // if return string, returns string version of output
  // otherwise, prints to terminal
  std::string print_tree(bool return_string);

  bool is_avl();

  bool is_balanced();

  bool is_sorted(Node *root);

private:
  Node *root = nullptr;

  Node *left_left(Node *root);

  Node *left_right(Node *root);

  Node *right_left(Node *root);

  Node *right_right(Node *root);

  Node *insert(Node *root, int value);
};

}; // namespace tree
