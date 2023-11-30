/*
D$ && The Cents - Project 3

Based on Project 5 code from Computer Science II

Tree Class Code

Made by Will and Max
*/


#include "TreeHuf.hpp"
#include "TreeNodeHuf.hpp"

using namespace std;

TreeNode* Tree::locate(const pair<string, double> &find) const {
    TreeNode* curr = this->_root;
    while(curr) {
        if(find.second < curr->value().second) {
            curr = curr->left();
        } else if (find.second > curr->value().second) {
            curr = curr->right();
        } else { // equal
            return curr;
        }
    }

    return nullptr;
}




//methods to add a node to an existing tree, used to connect trees together
void Tree::insertNodeHuf(const TreeNode * &nodeToAdd) {
     this->_root = insertNodeHufHelper(this->_root);
}


TreeNode * insertNodeHufHelper(TreeNode* & nodeToAdd) {//nodeToAdd is the 
    //all we need to do is take the nodeToAdd which will be the lesser of the trees ( this and nodeToAdd)
    

}


TreeNode* insertHelperHuf(TreeNode* intoSubTree, const string& value, const double & val) {
    if(!intoSubTree) {//if this is the root
        return new TreeNode(value, val);
    }
    //not the root check to see if we have a right (since right is smallest) then right
   
    
    if(intoSubTree->left() == nullptr) {//the 0
        intoSubTree->left() = insertHelperHuf(intoSubTree->left(), value, val);
        intoSubTree->left()->parent() = intoSubTree;    
    }
    else if(intoSubTree->right() == nullptr) {//the 1
        intoSubTree->right() = insertHelperHuf(intoSubTree->right(), value, val);    
        intoSubTree->right()->parent() = intoSubTree;    
    }

    return intoSubTree; 
}

void Tree::insertHuf(const std::string &value, const double & val) {
     this->_root = insertHelperHuf(this->_root, value, val);
}



void Tree::remove(const pair<std::string, double> &toDel) {
    TreeNode* toDelNode = this->locate(toDel);

    // Value doesn't exist
    if(!toDelNode) {
        cerr << "Value `" << toDel.first << ":" << toDel.second << "` was not found so no value was deleted" << endl;
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
        pair<string, double> save = curr->value();
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
