#ifndef _TREE_HPP_
#define _TREE_HPP_
#include <iostream>

#include "TreeNode.hpp"

class Tree {
public:
  Tree() : _root(nullptr) {}
  // locate
  // returns node found
  TreeNode *locate(const std::string &find) const;

  // insert
  // normal binary tree insert
  void insert(const std::string &value);

  // remove
  // returns node removed
  void remove(const std::string &toDel);

  // print (in-order, pre-order, post-order)
  void printPreOrder();
  void printPostOrder();
  void printInOrder();

  // get root
  const TreeNode *root() const { return this->_root; }
  TreeNode *&root() { return this->_root; }

private:
  TreeNode *_root;
};

#endif // _TREE_HPP_
