#include <iostream>
#include <sstream>

#include "test_utils.hpp"
#include "tree.hpp"

int main() {
  {
    Tree tree;

    tree.insert(7);
    tree.insert(4);
    tree.insert(9);
    tree.insert(1);
    tree.insert(6);
    tree.insert(8);
    tree.insert(10);

    CHECK(tree.find(10));
    CHECK(tree.find(100) == false);

    CHECK(tree.treverse_pre_order() == "74169810");
    CHECK(tree.treverse_in_order_ascending() == "14678910");
    CHECK(tree.treverse_in_order_descending() == "10987641");
    CHECK(tree.treverse_post_order() == "16481097");

    CHECK(tree.height() == 2);
    CHECK(tree.min() == 1);

    std::cout << tree;

    {
      Tree tree2;
      auto exp = tree == tree2;
      CHECK(exp == false);
      tree2.insert(7);
      tree2.insert(4);
      tree2.insert(9);
      tree2.insert(1);
      tree2.insert(6);
      tree2.insert(8);
      auto exp2 = tree == tree2;
      CHECK(exp2 == false);
      tree2.insert(10);
      CHECK(tree == tree2);
    }
  }

  return test::exit_with_summary("tree");
}
