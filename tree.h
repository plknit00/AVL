#using namespace Tree {

class Tree {
private:
public:
  struct Node {
    int value;
    Node *left_child;
    Node *right_child;
  };

  void insert();

  void deleete();

  // dfs algorithm
  Node *find(Node *root, int value);

  // bfs algorithm
  void print_tree(Node *root);
};
}
;