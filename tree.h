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
  Node *insert(Node *root, int value);

  // remove a value from the tree, if it exists
  void remove(int value);

  // bfs algorithm, prints tree with parent node, right/left child,
  // and balance factor specified
  // if return string, returns string version of output
  // otherwise, prints to terminal
  std::string print_tree(bool return_string);

private:
  Node *root = nullptr;

  bool is_avl() {
    if (is_balanced() && is_sorted(root)) {
      return true;
    }
    return false;
  }

  bool is_balanced() {
    if (root == nullptr) {
      return true;
    }
    std::queue<tree::Node *> q;
    q.push(root);
    while (!q.empty()) {
      tree::Node *curr_node = q.front();
      q.pop();
      tree::Node *left = curr_node->left;
      tree::Node *right = curr_node->right;
      int left_height = 0;
      int right_height = 0;
      if (left != nullptr) {
        left_height = left->height;
        q.push(left);
      }
      if (left != nullptr) {
        left_height = left->height;
        q.push(left);
      }
      int balance_factor = left_height - right_height;
      if ((balance_factor < -1) || (balance_factor > 1)) {
        return false;
      }
    }
    return true;
  }

  bool is_sorted(Node *root) {
    if (root == nullptr) {
      return true;
    }
    Node *left = root->left;
    Node *right = root->right;
    if (left != nullptr) {
      if (root->value < left->value) {
        return false;
      }
      is_sorted(left);
    }
    if (right != nullptr) {
      if (root->value > right->value) {
        return false;
      }
      is_sorted(right);
    }
    return true;
  }

  // ********* FIX **********
  void left_left(Node *root) {
    Node *new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;
  }

  // ********* FIX **********
  void left_right(Node *root) {
    Node *new_root = root->left->right;
    Node *a = root->left;
    root->left = new_root->right;
    Node *temp = new_root->left;
    new_root->left = a;
    a->right = temp;
    new_root->right = root;
  }

  // ********* FIX **********
  void right_left(Node *root) {
    Node *new_root = root->right->left;
    Node *a = root->right;
    root->right = new_root->left;
    Node *temp = new_root->right;
    new_root->right = a;
    a->left = temp;
    new_root->left = root;
  }

  // ********* FIX **********
  void right_right(Node *root) {
    Node *new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;
  }
};

}; // namespace tree
