#pragma once

#include <queue>
#include <string>

namespace tree {

struct Node {
  int value = 0;
  Node *left = nullptr;
  Node *right = nullptr;
  int height = 1;
};

class Tree {

public:
  bool empty();

  Node *get_root();

  int get_height(Node *node);

  int get_balance_factor(Node *node);

  Node *find(int value);

  // add a value to the tree, if it is not duplicate
  bool insert(int value);

  // remove a value from the tree, if it exists
  bool remove(int value);

  // bfs algorithm, prints tree with parent node, right/left child,
  // and balance factor specified
  // if return string, returns string version of output
  // otherwise, prints to terminal
  std::string print_tree(bool return_string);

  bool is_avl();

  bool is_balanced();

  bool is_sorted(Node *node);

private:
  Node *root = nullptr;

  Node *left_left(Node *node);

  Node *left_right(Node *node);

  Node *right_left(Node *node);

  Node *right_right(Node *node);

  Node *insert(Node *node, int value);

  Node *delete_node(Node *node, int value);

  Node *remove(Node *node, int value);
};

}; // namespace tree
