#include <iostream>

#include "Tree.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    CharBinaryTree myTree;

    myTree.insert('D');
    myTree.insert('i');
    myTree.insert('s');
    myTree.insert('c');
    myTree.insert('r');
    myTree.insert('e');
    myTree.insert('t');
    myTree.insert('=');
    myTree.insert('f');
    myTree.insert('u');
    myTree.insert('n');

    for (int index=1; index<argc; index++)
    {
        myTree.insert( atoi(argv[index]) );
    }

    myTree.print(cout);
    /*
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
    */
    return 0;
}
