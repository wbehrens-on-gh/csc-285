/**
 * Applied Discrete Structures Project 3
 * 
 * D$ && The Cents
 * 
 * Made by Max Hoffman
 * 
 * Problem 5 - Huffman Coding
 * 
 * 
*/

//Sources I used 
// I used this for converting: https://cplusplus.com/reference/string/stod/
//https://www.w3schools.com/cpp/cpp_arrays_size.asp
//
//
#include "TreeNode.hpp"
#include "Tree.hpp"
#include <iostream>
#include <vector>

#include <numeric>
using namespace std;


string letterAr[26] = {"A", "B","C", "D","E", "F", "G", "H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

double freqAr[26] = {0.0817, 0.0145,0.0248,0.0431,0.1232, 0.0209, 0.0182, 0.0668, 0.0689, 0.0010, 0.0080, 0.0397, 0.0277, 0.0662,0.0781,0.0156,0.0009,0.0572,0.0628, 0.0905, 0.0304, 0.0102, 0.0264, 0.0015, 0.0211, 0.0005};
double workArr[26];

//for the 0s and 1s
char team0[26];
char team1[26];


void printTable() {//print the freqency table out
cout << "Letters | Frequency" << endl;
    for(int i = 0; i < 26; i ++) {
        cout << letterAr[i] << " " << freqAr[i] << endl;
    }
}


int findLowest() {//finds the lowest frequency to then add to the second lowest, right is represented by 1 left by 0
    double lowestVal = 100;
    int index = 0;

    for(int i = 0; i < size(workArr); i++) {
        if(workArr[i] < lowestVal) {
            lowestVal = workArr[i];
            index = i;
        }
    }
    //delete it from the array
    workArr[index] = 100000;


    return index;
}


void secArr() {
    for(int i = 0; i < size(freqAr); i++) {
        workArr[i] = freqAr[i];
    }
}
int main(int argc, char *argv[]) {
    secArr();
    

    printTable();

    //find the 2 lowest frequencies in the array then we make the root node based off of that value
    int index = findLowest();
    int index2 = findLowest();
    double nodeValue = freqAr[index] + freqAr[index2];
    string val = to_string(nodeValue);
    //cout << "val1 " << freqAr[index] << " val 2 " << freqAr[index2] << endl;
    //cout << "node Val: " << nodeValue << endl << "string " << val << endl;
    //first make the root node then the others until we get 1 at the root
    TreeNode* root = new TreeNode(val);
    Tree huffmanTree;
    
    //inser the root
    huffmanTree.insert(root->value());

    //insert the two children index and index2
    TreeNode * leftN;
    leftN->value() = letterAr[index];
    //left = root->left();

/*
    TreeNode * right;
    right->value() = letterAr[index2];
    right = root->right();
*/


    //huffmanTree.insert(letterAr[index]);
    //huffmanTree.insert(letterAr[index2]);

    cout << "Huffman Tree" << endl;
    huffmanTree.printPreOrder();

    

    //while(nodeValue != 1.00) {//while the root does not equal 1, when it equals 1 we are done and we can then calculate the value for each node and add it up
        


    //}



    //now assign the letters to each left or right
    
    
}