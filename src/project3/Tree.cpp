#include "Tree.hpp"

using namespace std;

CharBinaryTreeNode* findHelper(CharBinaryTreeNode *inSubTree, char valToFind)
{
    if (!inSubTree)
        return nullptr;

    if (inSubTree->data() == valToFind)
        return inSubTree;

    if (inSubTree->data() < valToFind)
        return findHelper(inSubTree->right(), valToFind);

    // must be in left subtree (or we would already have returned)
    return findHelper(inSubTree->left(), valToFind);
}

CharBinaryTreeNode*
CharBinaryTree:: find(char valToFind) const
{
    return findHelper(_root, valToFind);
}

// intoSubTree -- the subtree into which we want to insert
// returns : updated version of subtree
CharBinaryTreeNode* insertHelper(CharBinaryTreeNode *intoSubTree, char valToAdd)
{
    if (intoSubTree == nullptr) // empty tree!
    {
        CharBinaryTreeNode *newTree = new CharBinaryTreeNode(valToAdd);
        return newTree;
    }
    if (valToAdd < intoSubTree->data() )
    {
        // want to insert in left subtree
        CharBinaryTreeNode *newSubTree = insertHelper(intoSubTree->left(), valToAdd);
        intoSubTree->left() = newSubTree;
        newSubTree->parent() = intoSubTree;
        return intoSubTree;
    }
    else if (valToAdd > intoSubTree->data() )
    {
        // want to insert into right subtree
        CharBinaryTreeNode *newSubTree = insertHelper(intoSubTree->right(), valToAdd);
        intoSubTree->right() = newSubTree;
        newSubTree->parent() = intoSubTree;
        return intoSubTree;
    }
    else // == ... so already found in subtree!!
    {
        return intoSubTree;
    }

}


void
CharBinaryTree::insert(char newVal)
{
    _root=insertHelper(_root, newVal);
}




void
CharBinaryTree::remove(char existingVal)
{
    CharBinaryTreeNode *toDel = find(existingVal);
    if (!toDel)
    {
        cerr << "Sorry, \"" << existingVal << "\" is not in tree!"
            << endl;
        return;
    }
    // case 1: no children ...
    if (toDel->isLeaf())
    {
        // special case
        if (toDel == _root)
        {
            _root=nullptr;
            return;
        }
        CharBinaryTreeNode *parent = toDel->parent();

        if (parent->left() == toDel)
            parent->left() = nullptr;
        else // must be on the right
            parent ->right() = nullptr;

        // following is not strictly necessary ...
        //    .. but lets "clean up" toDel
        toDel->parent() = nullptr;
        delete toDel;  // depending on application, don't do this
        return;
    }
    // case 2: one children
    else if ( ( toDel->right() && !toDel->left() ) ||
              ( toDel->left() && !toDel->right() )
            )
    {
        if (toDel==_root)
        {
            if (toDel->left())
                _root=toDel->left();
            else
                _root=toDel->right();

            _root->parent() = nullptr;
            return;
        }

        CharBinaryTreeNode *subTree;
        if (toDel->left())
            subTree=toDel->left();
        else
            subTree=toDel->right();

        CharBinaryTreeNode *parent = toDel->parent();
        if (parent->left() == toDel)
            parent->left() = subTree;
        else
            parent->right() = subTree;

        subTree->parent() = parent;

        // following is not strictly necessary ...
        //    .. but lets "clean up" toDel
        toDel->left() = toDel->right() = nullptr;
        toDel->parent() = nullptr;
        delete toDel;  // depending on application, don't do this
    }
    // case 3: two children
    else
    {
        // hop once to the right
        CharBinaryTreeNode *curr = toDel->right();
        // go as far left as you can ...
        while (curr->left() )
            curr=curr->left();

        int valToSave = curr->data();
        remove(valToSave);
        toDel->data() = valToSave;
        return;
    }

}


void inOrderPrint(CharBinaryTreeNode *currNode, ostream &os)
{
    if (currNode==nullptr)
        return;

    inOrderPrint(currNode->right(), os);

    // indent the node properly to display as tree
    for (int indentCount=0; indentCount<currNode->depth(); indentCount++)
        os << "    ";
    currNode->print(os);
    os << endl;

    inOrderPrint(currNode->left(), os);
}

std::ostream&
CharBinaryTree::print(std::ostream &someStream) const
{
    inOrderPrint(_root, someStream);
    return someStream;
}
