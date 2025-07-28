#pragma once

#include <string>

namespace tree {

struct Node {
  int value;
  Node *left = nullptr;
  Node *right = nullptr;
  int height = 0;
  int balance_factor = 0;
};

class Tree {
private:
  Node *root = nullptr;

public:
  bool empty();

  Node *get_root();

  // add a value to the tree, if it is not duplicate
  // not balanced
  void insert(int value);

  // remove a value from the tree, if it exists
  void remove(int value);

  // find if a value exists in the tree
  Node *find(int value);

  // bfs algorithm, prints tree with parent node, right/left child,
  // and balance factor specified
  // if return string, returns string version of output
  // otherwise, prints to terminal
  std::string print_tree(bool return_string);
};

}; // namespace tree
