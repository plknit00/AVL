#pragma once

namespace tree {

struct Node {
  int value;
  Node *left = nullptr;
  Node *right = nullptr;
};

class Tree {
private:
  Node *root = nullptr;

public:
  bool empty();

  // add a value to the tree, if it is not duplicate
  void insert(int value);

  // remove a value from the tree, if it exists
  void remove(int value);

  // find if a value exists in the tree
  Node *find(int value);

  // bfs algorithm, prints tree with parent node specified
  void print_tree();
};

}; // namespace tree
