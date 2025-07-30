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
    // if ((curr_node->balance_factor > 1) || (curr_node->balance_factor < -1))
    // {
    //   return false;
    // }
    if (curr_node->left != nullptr) {
      q.push(curr_node->left);
    }
    if (curr_node->right != nullptr) {
      q.push(curr_node);
    }
    return true;
  }
}

void *AVL::left_left(tree::Node *root) {
  tree::Node *new_root = root->left;
  root->left = new_root->right;
  new_root->right = root;
}

void *AVL::left_right(tree::Node *root) {
  tree::Node *new_root = root->left->right;
  tree::Node *a = root->left;
  root->left = new_root->right;
  tree::Node *temp = new_root->left;
  new_root->left = a;
  a->right = temp;
  new_root->right = root;
}

void *AVL::right_left(tree::Node *root) {
  tree::Node *new_root = root->right->left;
  tree::Node *a = root->right;
  root->right = new_root->left;
  tree::Node *temp = new_root->right;
  new_root->right = a;
  a->left = temp;
  new_root->left = root;
}

void *AVL::right_right(tree::Node *root) {
  tree::Node *new_root = root->right;
  root->right = new_root->left;
  new_root->left = root;
}

void AVL::insert(tree::Node *root, int value) {
  if (root == nullptr) {
    root = new tree::Node({.value = value});
    return;
  }
  if (value < root->value) {
    insert(root->left, value);
  } else if (value > root->value) {
    insert(root->right, value);
  } else {
    // do nothing if value = root value
    return;
  }
  root->height++;
  int left_height = 0;
  int right_height = 0;
  if (root->left != nullptr) {
    left_height = root->left->height;
  }
  if (root->right != nullptr) {
    right_height = root->right->height;
  }
  int balance_factor = left_height - right_height;
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