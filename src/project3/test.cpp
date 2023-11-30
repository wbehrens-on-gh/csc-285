#include <iostream>

#include "numberOneandTwo.hpp"
#include "numberOneandTwoTreeNode.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    IntBinaryTree myTree;

    myTree.insert(9);
    myTree.insert(3);
    myTree.insert(-3);
    myTree.insert(7);

    for (int index=1; index<argc; index++)
    {
        myTree.insert( atoi(argv[index]) );
    }

    myTree.print(cout);

    int delVal;
    cout << "Enter a value to delete (0 to stop): ";
    cin >> delVal;
    while(delVal!=0)
    {
        myTree.remove(delVal);
        myTree.print(cout);

        cout << "Enter a value to delete (0 to stop): ";
        cin >> delVal;
    }
    return 0;
}
