/**
 * D$ && The Cents 
 * 
 * Project 3 
 * Problem 5 - Huffman Codes
 * 
 * Made by Max Hoffman
 * 
 * Based off of the code we were given for project 5 in CSII
 *  just modified it since we did a binary Tree project
*/

#ifndef _TREE_NODE_HPP_
#define _TREE_NODE_HPP_

#include <string>
#include <utility>

class TreeNode {
private:
    std::pair<std::string, double> _nodeValue; //value of the node 
    //node frequency
    TreeNode* _left;
    TreeNode* _right;
    TreeNode* _parent;
public:
    TreeNode() : _nodeValue(), _left(nullptr), _right(nullptr), _parent(nullptr) {}
    
    TreeNode(const std::string value, const double freq)
        : _nodeValue({value, freq}), _left(nullptr), _right(nullptr), _parent(nullptr) {}

    //get methods
    TreeNode* left() const { return _left; }
    TreeNode* right() const { return _right; }
    TreeNode* parent() const { return _parent; }
    std::pair<std::string, double> value() const {return _nodeValue;}

    //modify the values
    TreeNode*& left() { return _left; }
    TreeNode*& right() { return _right; }
    TreeNode*& parent() { return _parent; }
    std::pair<std::string, double>& value() {return _nodeValue;}
        
    std::ostream& print(std::ostream& toStream) const;
    int depth() const;
    bool isLeaf() const;
};

std::ostream& operator<<(std::ostream& os, const TreeNode& node);

#endif