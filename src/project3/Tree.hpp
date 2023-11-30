#ifndef _TREE_HPP_
#define _TREE_HPP_

#include "TreeNode.hpp"

#include <iostream>

class CharBinaryTree
{
private:
    CharBinaryTreeNode *_root;
public:
    CharBinaryTree() : _root(nullptr) {}

    CharBinaryTreeNode* find(char valToFind) const;

    void insert(char newVal);
    void remove(char existingVal);

    std::ostream& print(std::ostream &os) const;
};

#endif
