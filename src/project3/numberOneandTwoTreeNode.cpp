#include "numberOneandTwoTreeNode.hpp"

int
IntBinaryTreeNode::depth() const
{
    int numAncestors=0;
    IntBinaryTreeNode *parentPtr = _parent;

    while(parentPtr!=nullptr)
    {
        numAncestors++;
        parentPtr = parentPtr->parent();
    }

    return numAncestors;
}

std::ostream&
IntBinaryTreeNode::print(std::ostream &toStream) const
{
    toStream << _data;
    return toStream;
}
