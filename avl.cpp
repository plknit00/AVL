#include "avl.h"
#include "tree.h"

bool AVL::is_balanced(tree::Node *root) {
  // ****** TO DO **********
}

void AVL::balance_avl_tree(tree::Node *root) {
  // ****** TO DO **********
}

tree::Node *AVL::left_left(tree::Node *root) {
  tree::Node *new_root = root->left;
  root->left = new_root->right;
  new_root->right = root;
  return new_root;
}

tree::Node *AVL::left_right(tree::Node *root) {
  tree::Node *a = root->left;
  tree::Node *b = a->right;
  root->left = b;
  b->left = a;
  a->left = nullptr;
  return left_left(root);
}

tree::Node *AVL::right_left(tree::Node *root) {
  tree::Node *a = root->right;
  tree::Node *b = a->left;
  root->right = b;
  b->right = a;
  a->right = nullptr;
  return right_right(root);
}

tree::Node *AVL::right_right(tree::Node *root) {
  tree::Node *new_root = root->right;
  root->right = new_root->left;
  new_root->left = root;
  return new_root;
}