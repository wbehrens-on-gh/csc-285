//Given the ordered list of edges of an ordered, rooted tree, list its vertices in
//preorder, inorder, and postorder.

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
void preOrder(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }

    // print data of node
    cout << node->data << " ";

    // recur on left subtree
    preOrder(node->left);

    // recur on right subtree
    preOrder(node->right);
}

void inOrder(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }

    //recur on left child
    inOrder(node->left);

    //print node data
    cout << node->data << " ";

    //now right child
    inOrder(node->right);

}

void postOrder(struct Node* node)
{
    if (node == NULL)
    {
        return;
    }

    // recur on left subtree
    postOrder(node->left);

    // recur on right subtree
    postOrder(node->right);

    // deal with the node
    cout << node->data << " ";
}


int main()
{
    //creates a tree ()
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(6);
    root->left->left->left = newNode(5);

    // Function calls
    cout << "Preorder traversal of binary tree is: \n";
    preOrder(root);
    cout << endl;
    cout << "Inorder traversal of binary tree is: \n" ;
    inOrder(root);
    cout << endl;
    cout << "Postorder traversal of binary tree is: \n" ;
    postOrder(root);
    cout << endl;


}

