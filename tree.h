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

  void insert(int value);

  void remove(int value);

  // dfs algorithm BAD
  Node *find(int value);

  // bfs algorithm
  void print_tree();
};

}; // namespace tree
