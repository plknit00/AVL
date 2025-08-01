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

Node *Tree::get_root() { return root; }

int Tree::get_height(Node *node) {
  int left_height = 0;
  int right_height = 0;
  if (node->left != nullptr) {
    left_height = node->left->height;
  }
  if (node->right != nullptr) {
    right_height = node->right->height;
  }
  return std::max(left_height, right_height);
}

int Tree::get_balance_factor(Node *node) {
  int left_height = 0;
  int right_height = 0;
  if (node->left != nullptr) {
    left_height = node->left->height;
  }
  if (node->right != nullptr) {
    right_height = node->right->height;
  }
  return left_height - right_height;
}

Node *Tree::find(int value) {
  if (root == nullptr) {
    return root;
  }
  Node *curr_node = root;
  while (curr_node != nullptr) {
    if (curr_node->value == value) {
      return curr_node;
    }
    if (value < curr_node->value) {
      curr_node = curr_node->left;
    } else if (value > curr_node->value) {
      curr_node = curr_node->right;
    }
  }
  return nullptr;
}

Node *Tree::insert(Node *root, int value) {
  if (root == nullptr) {
    return new Node({.value = value});
  }
  if (value < root->value) {
    root->left = insert(root->left, value);
  } else if (value > root->value) {
    root->right = insert(root->right, value);
  } else {
    // do nothing if value = root value
    // does this have loop potential ???????
    return root;
  }
  root->height = 1 + get_height(root);
  int balance_factor = get_balance_factor(root);
  if (balance_factor > 1) {
    if (value < root->left->value) {
      left_left(root);
    } else {
      left_right(root);
    }
  }
  if (balance_factor < -1) {
    if (value > root->right->value) {
      right_right(root);
    } else {
      right_left(root);
    }
  }
}

void Tree::remove(int value) {
  if (root == nullptr) {
    return;
  }
  /*Node *curr_node = root;
  Node *parent = nullptr;
  bool is_left_child;
  while (curr_node != nullptr) {
    if (curr_node->value == value) {
      // ********* POTENTIAL LOGIC ERROR, update with tree balance *********
      if (is_left_child) {
        parent->left = curr_node->left;
        curr_node->left->right = curr_node->right;
      } else {
        parent->right = curr_node->right;
        curr_node->right->left = curr_node->left;
      }
    }
    if (value < curr_node->value) {
      parent = curr_node;
      is_left_child = true;
      curr_node = curr_node->left;
    } else if (value > curr_node->value) {
      parent = curr_node;
      is_left_child = false;
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
  return;*/
}

std::string Tree::print_tree(bool return_string) {
  std::string result;
  struct PrintVal {
    Node *node;
    int depth;
    int parent_value;
  };
  if (root == nullptr) {
    if (!return_string) {
      std::cout << "Empty Tree" << std::endl;
    }
    result = "empty";
    return result;
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
      if (return_string) {
        result = result + "\n";
      } else {
        std::cout << std::endl;
      }
    }
    if (return_string) {
      int bf = get_balance_factor(curr_print_val.node);
      result = result + std::to_string(curr_node_ptr->value) + " (" +
               std::to_string(curr_print_val.parent_value) + "," +
               std::to_string(bf) + ") ";
    } else {
      std::cout << curr_node_ptr->value << " (" << curr_print_val.parent_value
                << ") ";
    }
  }
  return result;
}

}; // namespace tree