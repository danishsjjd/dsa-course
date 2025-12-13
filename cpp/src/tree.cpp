#include "tree.hpp"

Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
  delete root;
  root = nullptr;
}

void Tree::insert(int value) {
  auto node = new Node(value);

  if (this->root == nullptr) {
    this->root = node;
    return;
  }

  auto current = this->root;

  while (current) {
    if (value == current->value) {
      return;
    }

    Node* next = nullptr;
    if (value > current->value) {
      next = current->right_child;
    } else {
      next = current->left_child;
    }

    if (next == nullptr) {
      break;
    }

    current = next;
  };

  if (value > current->value) {
    current->right_child = node;
  } else {
    current->left_child = node;
  }
}

bool Tree::find(int value) const {
  auto current = this->root;

  while (current) {
    if (current->value == value) {
      return true;
    }

    if (value > current->value) {
      current = current->right_child;
    } else {
      current = current->left_child;
    }
  };

  return false;
}

std::string Tree::treverse_pre_order() const {
  return this->treverse_pre_order(this->root);
}

std::string Tree::treverse_in_order_ascending() const {
  return this->treverse_in_order_ascending(this->root);
}

std::string Tree::treverse_in_order_descending() const {
  return this->treverse_in_order_descending(this->root);
}

std::string Tree::treverse_post_order() const {
  return this->treverse_post_order(this->root);
}

int Tree::height() const {
  return height(this->root);
}

int Tree::height(Node* node) {
  if (node == nullptr) {
    return -1;
  }

  if (node->left_child == nullptr && node->right_child == nullptr) {
    return 0;
  }

  return 1 + std::max(height(node->left_child), height(node->right_child));
}

int Tree::min() const {
  auto current = this->root;

  if (current == nullptr) {
    throw std::out_of_range("Tree is empty");
  }

  while (current) {
    auto next = current->left_child;

    if (!next) {
      break;
    }

    current = next;
  }

  return current->value;
}

bool Tree::operator==(const Tree& tree) const {
  return equals(tree.root, this->root);
}

std::string Tree::treverse_pre_order(Node* from) {
  if (from == nullptr) {
    return "";
  }

  std::string results = "";
  results += std::to_string(from->value);

  if (from->left_child) {
    results += treverse_pre_order(from->left_child);
  }

  if (from->right_child) {
    results += treverse_pre_order(from->right_child);
  }

  return results;
}

std::string Tree::treverse_in_order_ascending(Node* from) {
  if (from == nullptr) {
    return "";
  }

  std::string results = "";
  if (from->left_child) {
    results += treverse_in_order_ascending(from->left_child);
  }

  results += std::to_string(from->value);

  if (from->right_child) {
    results += treverse_in_order_ascending(from->right_child);
  }

  return results;
}

std::string Tree::treverse_in_order_descending(Node* from) {
  if (from == nullptr) {
    return "";
  }

  std::string results = "";
  if (from->right_child) {
    results += treverse_in_order_descending(from->right_child);
  }

  results += std::to_string(from->value);

  if (from->left_child) {
    results += treverse_in_order_descending(from->left_child);
  }

  return results;
}

std::string Tree::treverse_post_order(Node* from) {
  if (from == nullptr) {
    return "";
  }

  std::string results = "";
  if (from->left_child) {
    results += treverse_post_order(from->left_child);
  }

  if (from->right_child) {
    results += treverse_post_order(from->right_child);
  }

  results += std::to_string(from->value);

  return results;
}

bool Tree::equals(Node* first, Node* second) {
  if (first == nullptr && second == nullptr) {
    return true;
  }

  if (first != nullptr && second != nullptr) {
    return first->value == second->value &&
           equals(first->left_child, second->left_child) &&
           equals(first->right_child, second->right_child);
  }

  return false;
}
