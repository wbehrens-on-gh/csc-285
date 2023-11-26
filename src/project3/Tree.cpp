/*
D$ && The Cents - Project 3

Based on Project 5 code from Computer Science II

Tree Class Code

Made by Will and Max
*/


#include "Tree.hpp"
#include "TreeNode.hpp"

using namespace std;

TreeNode* Tree::locate(const std::string &find) const {
    TreeNode* curr = this->_root;
    while(curr) {
        if(find < curr->value()) {
            curr = curr->left();
        } else if (find > curr->value()) {
            curr = curr->right();
        } else { // equal
            return curr;
        }
    }

    return nullptr;
}





// intoSubTree -- The subtree we want to insert into
// new_value -- the new value we want to insert into the subtree
//
// returns the update subtree
TreeNode* insertHelper(TreeNode* intoSubTree, const string& value) {
    if(!intoSubTree) {
        return new TreeNode(value);
    }
    
    // if we get here, we have at least one node in our tree.
    if(value < intoSubTree->value()) {
        intoSubTree->left() = insertHelper(intoSubTree->left(), value);
        intoSubTree->left()->parent() = intoSubTree;    
    } else if(value > intoSubTree->value()) {
        intoSubTree->right() = insertHelper(intoSubTree->right(), value);    
        intoSubTree->right()->parent() = intoSubTree;    
    }

    return intoSubTree; 
}

void Tree::insert(const std::string &value) {
    this->_root = insertHelper(this->_root, value);
}

void Tree::remove(const std::string &toDel) {
    TreeNode* toDelNode = this->locate(toDel);

    // Value doesn't exist
    if(!toDelNode) {
        cerr << "Value `" << toDel << "` was not found so no value was deleted" << endl;
        return;
    }

    // No children
    if(toDelNode->isLeaf()) {
        // If the only node is root.
        if(toDelNode == this->_root) {
            this->_root = nullptr;
            return;
        }

        // Find parent then decide which child to remove.
        TreeNode* parent = toDelNode->parent();
        if(parent->right() == toDelNode) {
            parent->right() = nullptr;     
        } else { // Must be on the left
            parent->left() = nullptr;     
        }

        // Make `toDelNode` an orphan then kill it.
        toDelNode->parent() = nullptr;
        delete toDelNode; // If we don't want anyone using `toDel` anymore
    }

    // One child
    if(
        (toDelNode->left() && !toDelNode->right()) ||
        (!toDelNode->left() && toDelNode->right())
    ) {
        // If root, change root
        if(toDelNode == this->_root) {
            if(toDelNode->left()) {
                this->_root = toDelNode->left();
            } else {
                this->_root = toDelNode->right();
            }
            this->_root->parent() = nullptr;
            return; // This skips the clean up below, it shouldn't 
        }

        // Find out which node actually exists
        TreeNode* subtree;
        if(toDelNode->left()) {
            subtree = toDelNode->left();
        } else {
            subtree = toDelNode->right();
        }

        // Set parent's child to new subtree
        TreeNode* parent = toDelNode->parent();
        if(parent->left() == toDelNode) {
            parent->left() = subtree;
        } else { // right
            parent->right() = subtree;
        }
        subtree->parent() = parent;

        // Make `toDelNode` an orphan then kill it.
        toDelNode->parent() = nullptr;
        toDelNode->right() = nullptr;
        toDelNode->left() = nullptr;
        delete toDelNode; // If we don't want anyone using `toDelNode` anymore
    }

    // Two children
    if(toDelNode->left() && toDelNode->right()) {
        // One step to the right, then all the way to the left
        TreeNode* curr = toDelNode->right();
        while(curr->left()) {
            curr = curr->left();
        }
        string save = curr->value();
        this->remove(save); // Recursive call will only be run once
        
        // Don't really "delete", just update the value
        toDelNode->value() = save; 
    }

}

//print the parent first
void printPreOrderHelper(TreeNode* curr) {
    if(!curr) {
        return;
    }

    for(int i = 1; i < curr->depth(); i++) {
        cout << "----|";
    }
    cout << *curr << endl;
    printPreOrderHelper(curr->left());
    printPreOrderHelper(curr->right());
}

void Tree::printPreOrder() {
    printPreOrderHelper(this->_root);
}

//print the parent last
void printPostOrderHelper(TreeNode *curr) {
    if(!curr) {
        return;
    }
    printPostOrderHelper(curr->left());
    printPostOrderHelper(curr->right());
    for(int i = 1; i < curr->depth(); i++) {
        cout << "----|";
    }
    cout << *curr << endl;
}

void Tree::printPostOrder() {
    printPostOrderHelper(this->_root);
}

//visit your parent then left then right (in order)
void printInOrderHelper(TreeNode * curr) {
    if(!curr) {
        return;
    }
    printInOrderHelper(curr->left());
    for(int i = 1; i < curr->depth(); i++) {
        cout << "----|";
    }
    cout << *curr << endl;
    printInOrderHelper(curr->right());
}

void Tree::printInOrder() {
    printInOrderHelper(this->_root);
}
