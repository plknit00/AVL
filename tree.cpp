#include "tree.h"
#include <iostream>
#include <stack>

namespace tree {

bool Tree::empty() {
  if (root != nullptr) {
    return false;
  }
  return true;
}

void Tree::insert(int value) {
  if (root == nullptr) {
    root = new Node({.value = value});
    return;
  }
  Node *curr_node = root;
  Node *parent = nullptr;
  while (curr_node != nullptr) {
    if (value < curr_node->value) {
      parent = curr_node;
      curr_node = curr_node->left;
    } else if (value > curr_node->value) {
      parent = curr_node;
      curr_node = curr_node->right;
    }
  }
  curr_node = new Node({.value = value});
  if (parent != nullptr) {
    if (value < parent->value) {
      parent->left = curr_node;
    } else if (value > parent->value) {
      parent->right = curr_node;
    }
  }
  return;
}

void Tree::remove(int value) {
  // ****** TO DO **********
}

Node *Tree::find(int value) {
  if (root == nullptr) {
    return root;
  }
  std::stack<Node *> s;
  s.push(root);
  while (!s.empty()) {
    Node *curr_node_ptr = s.top();
    s.pop();
    if (curr_node_ptr->value == value) {
      return curr_node_ptr;
    }
    if (curr_node_ptr->left != nullptr) {
      s.push(curr_node_ptr->left);
    }
    if (curr_node_ptr->right != nullptr) {
      s.push(curr_node_ptr->right);
    }
  }
  return nullptr;
}

void Tree::print_tree() {
  struct PrintVal {
    Node *node;
    int depth;
    int parent_value;
  };
  if (root == nullptr) {
    std::cout << "Empty Tree" << std::endl;
    return;
  }
  PrintVal pv_root = {.node = root, .depth = 0, .parent_value = 0};
  std::queue<PrintVal> q;
  q.push(pv_root);
  int depth = 0;
  while (!q.empty()) {
    PrintVal curr_print_val = q.front();
    q.pop();
    Node *curr_node_ptr = curr_print_val.node;
    int curr_depth = curr_print_val.depth;
    if (curr_node_ptr->left != nullptr) {
      q.push({curr_node_ptr->left, curr_depth + 1, curr_node_ptr->value});
    }
    if (curr_node_ptr->right != nullptr) {
      q.push({curr_node_ptr->right, curr_depth + 1, curr_node_ptr->value});
    }
    if (curr_depth != depth) {
      depth++;
      std::cout << std::endl;
    }
    std::cout << curr_node_ptr->value << " (" << curr_print_val.parent_value
              << ") ";
  }
}

}; // namespace tree