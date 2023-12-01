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

    char addVal;
    cout << "Enter a character to insert (+ to stop): ";
    cin >> addVal;
    while(addVal!='+')
    {
        myTree.insert(addVal);
        myTree.print(cout);

        cout << "Enter a character to insert (+ to stop): ";
        cin >> addVal;
    }

    char delVal;
    cout << "Enter a character to delete (+ to stop): ";
    cin >> delVal;
    while(delVal!='+')
    {
        myTree.remove(delVal);
        myTree.print(cout);

        cout << "Enter a character to delete (+ to stop): ";
        cin >> delVal;
    }

    return 0;
}
