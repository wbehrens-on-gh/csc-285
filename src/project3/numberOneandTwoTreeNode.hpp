#ifndef _NUMBER_ONE_AND_TWO_TREE_NODE_HPP_
#define _NUMBER_ONE_AND_TWO_TREE_NODE_HPP_

#include <iostream>

class IntBinaryTreeNode
{
private:
    int _data;
    IntBinaryTreeNode *_left;
    IntBinaryTreeNode *_right;
    IntBinaryTreeNode *_parent;
public:
    IntBinaryTreeNode() : _data(0), _left(nullptr), _right(nullptr), _parent(nullptr) {}
    IntBinaryTreeNode(int value) : _data(value), _left(nullptr), _right(nullptr), _parent(nullptr) {}

    int data() const {return _data;}
    int& data() {return _data;}

    IntBinaryTreeNode* left() const {return _left;}
    IntBinaryTreeNode* &left() {return _left;}

    IntBinaryTreeNode* right() const {return _right;}
    IntBinaryTreeNode* &right() {return _right;}

    IntBinaryTreeNode* parent() const {return _parent;}
    IntBinaryTreeNode* &parent() {return _parent;}

    bool isLeaf() const { return !_left && !_right; }//{return ( (_left==nullptr) && (_right==nullptr) );}
    bool isRoot() const { return !_parent; } // (_parent==nullptr)

    int depth() const;

    std::ostream& print(std::ostream &toStream) const;
};
