#include "TreeNode.hpp"

int
CharBinaryTreeNode::depth() const
{
    int numAncestors=0;
    CharBinaryTreeNode *parentPtr = _parent;

    while(parentPtr!=nullptr)
    {
        numAncestors++;
        parentPtr = parentPtr->parent();
    }

    return numAncestors;
}

std::ostream&
CharBinaryTreeNode::print(std::ostream &toStream) const
{
    toStream << _data;
    return toStream;
}
