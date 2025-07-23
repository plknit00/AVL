#include "avl.h"

using namespace Tree{

    void Tree::insert(){
        // ****** TO DO **********
    }

    void Tree::deleete(){
        // ****** TO DO **********
    }

    Node *
    Tree::find(Node * root, int value){if (root == nullptr){return root;
}
std::stack<Node *> s;
s.push(root);
while (!s.empty()) {
  Node *curr_node_ptr = s.pop();
  if (s.value == value) {
    return curr_node_ptr;
  }
  if (curr_node_ptr.left != nullptr) {
    q.push(curr_node_ptr.left);
  }
  if (curr_node_ptr.right != nullptr) {
    q.push(curr_node_ptr.right);
  }
}
return nullptr;
}

void Tree::print_tree(Node *root) {
  struct PrintVal {
    Node *node;
    int depth;
    int parent_value;
  } if (root == nullptr) {
    std::cout << "Empty Tree" << std::endl;
    return;
  }
  pv_root = {root, 0, 0};
  std::queue<pv_root> q;
  q.push(root);
  int curr_depth = 0;
  while (!q.empty()) {
    PrintVal curr_print_val = q.pop();
    Node *curr_node_ptr = curr_print_val.node;
    int curr_depth = curr_print_val.depth;
    if (curr_node_ptr.left != nullptr) {
      q.push(curr_node_ptr.left);
    }
    if (curr_node_ptr.right != nullptr) {
      q.push(curr_node_ptr.right);
    }
    if (curr_depth != depth) {
      depth++;
      std::cout << std::endl;
    }
    std::cout << curr_node_ptr.value << " (" << curr_print_val.Node.value
              << ") ";
  }
}
}
;