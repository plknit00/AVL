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
  return 1 + std::max(left_height, right_height);
}

int Tree::get_balance_factor(Node *node) {
  if (node == nullptr) {
    return 0;
  }
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

bool Tree::insert(int value) {
  // return false if value already exists in tree
  Node *result = insert(root, value);
  // if (result == nullptr) {
  //   return false;
  // }
  root = result;
  return true;
}

Node *Tree::insert(Node *node, int value) {
  if (node == nullptr) {
    return new Node({.value = value});
  }
  if (value < node->value) {
    node->left = insert(node->left, value);
  } else if (value > node->value) {
    node->right = insert(node->right, value);
  } else {
    return node;
  }
  node->height = get_height(node);
  int balance_factor = get_balance_factor(node);
  if (balance_factor > 1) {
    if (value < node->left->value) {
      return left_left(node);
    } else {
      return left_right(node);
    }
  }
  if (balance_factor < -1) {
    if (value > node->right->value) {
      return right_right(node);
    } else {
      return right_left(node);
    }
  }
  return node;
}

bool Tree::remove(int value) {
  // return false if value isnt found in tree
  Node *result = remove(root, value);
  // if (root == nullptr) {
  //   return false;
  // }
  root = result;
  return true;
}

Node *Tree::delete_node(Node *node) {
  Node *left = node->left;
  Node *right = node->right;
  Node *result = nullptr;
  if ((left == nullptr) && (right != nullptr)) {
    result = right;
  } else if ((right == nullptr) && (left != nullptr)) {
    result = left;
  } else if ((right != nullptr) && (left != nullptr)) {
    Node *new_root = find_inorder_successor(right);
    node->value = new_root->value;
    // ********** errorrrrrrrr lineeeeeee **********
    right = remove(right, new_root->value);
    return node;
  }
  delete node;
  return result;
}

Node *Tree::find_inorder_successor(Node *node) {
  Node *curr_node = node;
  while (curr_node->left != nullptr) {
    curr_node = curr_node->left;
  }
  return curr_node;
}

Node *Tree::remove(Node *node, int value) {
  if (node == nullptr) {
    return node;
  }
  if (value < node->value) {
    node->left = remove(node->left, value);
  } else if (value > node->value) {
    node->right = remove(node->right, value);
  } else {
    return delete_node(node);
  }
  node->height = get_height(node);
  int balance_factor = get_balance_factor(node);
  if (balance_factor > 1) {
    if (get_balance_factor(node->left) < 0) {
      return left_right(node);
    } else {
      return left_left(node);
    }
  }
  if (balance_factor < -1) {
    if (get_balance_factor(node->right) > 0) {
      return right_left(node);
    } else {
      return right_right(node);
    }
  }
  return node;
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

bool Tree::is_avl() {
  if (is_balanced() && is_sorted(root)) {
    return true;
  }
  return false;
}

bool Tree::is_balanced() {
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
    if (right != nullptr) {
      right_height = right->height;
      q.push(right);
    }
    int balance_factor = left_height - right_height;
    if ((balance_factor < -1) || (balance_factor > 1)) {
      return false;
    }
  }
  return true;
}

bool Tree::is_sorted(Node *root) {
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

Node *Tree::left_left(Node *old_root) {
  Node *new_root = old_root->left;
  old_root->left = new_root->right;
  new_root->right = old_root;
  old_root->height = get_height(old_root);
  new_root->height = get_height(new_root);
  return new_root;
}

Node *Tree::left_right(Node *old_root) {
  Node *new_root = old_root->left->right;
  Node *a = old_root->left;
  old_root->left = new_root->right;
  Node *temp = new_root->left;
  new_root->left = a;
  a->right = temp;
  new_root->right = old_root;
  old_root->height = get_height(old_root);
  a->height = get_height(a);
  new_root->height = get_height(new_root);
  return new_root;
}

Node *Tree::right_left(Node *old_root) {
  Node *new_root = old_root->right->left;
  Node *a = old_root->right;
  old_root->right = new_root->left;
  Node *temp = new_root->right;
  new_root->right = a;
  a->left = temp;
  new_root->left = old_root;
  old_root->height = get_height(old_root);
  a->height = get_height(a);
  new_root->height = get_height(new_root);
  return new_root;
}

Node *Tree::right_right(Node *old_root) {
  Node *new_root = old_root->right;
  old_root->right = new_root->left;
  new_root->left = old_root;
  old_root->height = get_height(old_root);
  new_root->height = get_height(new_root);
  return new_root;
}

}; // namespace tree