#include "avl.h"
#include "tree.h"
#include <queue>

bool AVL::is_balanced(tree::Node *root) {
  if (root == nullptr) {
    return true;
  }
  std::queue<tree::Node *> q;
  q.push(root);
  int depth = 0;
  while (!q.empty()) {
    tree::Node *curr_node = q.front();
    q.pop();
    if ((curr_node->balance_factor > 1) || (curr_node->balance_factor < -1)) {
      return false;
    }
    if (curr_node->left != nullptr) {
      q.push(curr_node->left);
    }
    if (curr_node->right != nullptr) {
      q.push(curr_node);
    }
    return true;
  }
}

void AVL::balance_avl_tree(tree::Node *root) {
  // ****** TO DO **********
}

void *AVL::left_left(tree::Node *root) {
  tree::Node *new_root = root->left;
  root->left = new_root->right;
  new_root->right = root;
  // return new_root;
}

void *AVL::left_right(tree::Node *root) {
  tree::Node *new_root = root->left->right;
  tree::Node *a = root->left;
  root->left = new_root->right;
  tree::Node *temp = new_root->left;
  new_root->left = a;
  a->right = temp;
  new_root->right = root;
  // return new_root;
}

void *AVL::right_left(tree::Node *root) {
  tree::Node *new_root = root->right->left;
  tree::Node *a = root->right;
  root->right = new_root->left;
  tree::Node *temp = new_root->right;
  new_root->right = a;
  a->left = temp;
  new_root->left = root;
  // return new_root;
}

void *AVL::right_right(tree::Node *root) {
  tree::Node *new_root = root->right;
  root->right = new_root->left;
  new_root->left = root;
  // return new_root;
}

void AVL::insert(tree::Node *root, int value) {
  if (root == nullptr) {
    root = new tree::Node({.value = value});
    return;
  }
  tree::Node *curr_node = root;
  tree::Node *parent = nullptr;
  while (curr_node != nullptr) {
    if (value < curr_node->value) {
      parent = curr_node;
      curr_node = curr_node->left;
    } else if (value > curr_node->value) {
      parent = curr_node;
      curr_node = curr_node->right;
    }
  }
  curr_node = new tree::Node({.value = value});
  if (parent != nullptr) {
    if (value < parent->value) {
      parent->left = curr_node;
    } else if (value > parent->value) {
      parent->right = curr_node;
    }
  }
  int left_bf = curr_node->left->balance_factor;
  int right_bf = curr_node->right->balance_factor;
  curr_node->balance_factor = left_bf - right_bf;
  int curr_bf = curr_node->balance_factor;
  if (curr_bf > 1) {
    // check this condition
    if (curr_bf > curr_node->left->balance_factor) {
      left_left(curr_node);
    } else {
      left_right(curr_node);
    }
  }
  if (curr_bf < -1) {
    // check this condition
    if (curr_bf > curr_node->right->balance_factor) {
      right_right(curr_node);
    } else {
      right_left(curr_node);
    }
  }
  return;
}