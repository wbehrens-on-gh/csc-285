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

#include "TreeNode.hpp"

std::ostream&
TreeNode::print(std::ostream& toStream) const
{
    toStream << _nodeValue;
    return toStream;
}

std::ostream& operator<<(std::ostream& os, const TreeNode& tn)
{
    return tn.print(os);
}