#pragma once
#include <iomanip>
#include <ostream>
#include <string>

class Tree {
  struct Node {
    int value;
    Node* left_child;
    Node* right_child;

    Node(int val) : value(val), left_child(nullptr), right_child(nullptr) {}
  };

 public:
  Tree();
  ~Tree();
  void insert(int value);
  bool find(int value) const;
  std::string treverse_pre_order() const;
  std::string treverse_in_order_ascending() const;
  std::string treverse_in_order_descending() const;
  std::string treverse_post_order() const;
  int height() const;
  int min() const;
  bool operator==(const Tree& tree) const;

  friend std::ostream& operator<<(std::ostream& stream, const Tree& tree);

 private:
  Node* root;
  static std::string treverse_pre_order(Node* from);
  static std::string treverse_in_order_ascending(Node* from);
  static std::string treverse_in_order_descending(Node* from);
  static std::string treverse_post_order(Node* from);
  static bool equals(Node* first, Node* second);
  static int height(Node* node);

  static void print_tree(std::ostream& stream, Node* node,
                         const std::string& prefix, bool is_left) {
    if (node == nullptr) return;

    stream << prefix;
    stream << (is_left ? "├── " : "└── ");
    stream << node->value << "\n";

    print_tree(stream, node->left_child, prefix + (is_left ? "│   " : "    "),
               true);
    print_tree(stream, node->right_child, prefix + (is_left ? "│   " : "    "),
               false);
  }
};

inline std::ostream& operator<<(std::ostream& stream, const Tree& tree) {
  if (tree.root == nullptr) {
    stream << "(empty tree)\n";
    return stream;
  }

  stream << tree.root->value << "\n";
  Tree::print_tree(stream, tree.root->left_child, "", true);
  Tree::print_tree(stream, tree.root->right_child, "", false);

  return stream;
}
