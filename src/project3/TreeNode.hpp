#ifndef _TREE_NODE_HPP_
#define _TREE_NODE_HPP_

#include <iostream>

class CharBinaryTreeNode
{
private:
    char _data;
    CharBinaryTreeNode *_left;
    CharBinaryTreeNode *_right;
    CharBinaryTreeNode *_parent;
public:
    CharBinaryTreeNode() : _data(0), _left(nullptr), _right(nullptr), _parent(nullptr) {}
    CharBinaryTreeNode(char value) : _data(value), _left(nullptr), _right(nullptr), _parent(nullptr) {}

    char data() const {return _data;}
    char& data() {return _data;}

    CharBinaryTreeNode* left() const {return _left;}
    CharBinaryTreeNode* &left() {return _left;}

    CharBinaryTreeNode* right() const {return _right;}
    CharBinaryTreeNode* &right() {return _right;}

    CharBinaryTreeNode* parent() const {return _parent;}
    CharBinaryTreeNode* &parent() {return _parent;}

    bool isLeaf() const { return !_left && !_right; }//{return ( (_left==nullptr) && (_right==nullptr) );}
    bool isRoot() const { return !_parent; } // (_parent==nullptr)

    int depth() const;

    std::ostream& print(std::ostream &toStream) const;
};

#endif
