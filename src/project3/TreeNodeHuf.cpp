/**
 * D$ && The Cents 
 * 
 * Project 3 
 * Problem 5 - Huffman Codes
 * 
 * Made by Max Hoffman
 * 
 * 
 * Based off of the code we were given for project 5 in CSII
 *  just modified it since we did a binary Tree project
 * 
 * 
*/

#include "TreeNodeHuf.hpp"

int TreeNode::depth() const {   
    int ancestors=0;
    TreeNode* curr = (TreeNode*) this; // This removes const, not good but whatever
    while(curr) {
        curr=curr->parent();
        ancestors++;
    }

    return ancestors;
}

std::ostream&
TreeNode::print(std::ostream& toStream) const
{
    toStream << (std::string) _nodeValue.first << (std::string) ":" << std::to_string(_nodeValue.second);
    return toStream;
}

std::ostream& operator<<(std::ostream& os, const TreeNode& tn)
{
    return tn.print(os);
}

bool TreeNode::isLeaf() const {
    if(!this->left() && !this->right()) {
        return true;
    } else {
        return false;
    }
}
