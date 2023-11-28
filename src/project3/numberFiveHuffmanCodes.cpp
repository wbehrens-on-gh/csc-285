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
#include "TreeNodeHuf.hpp"
#include "TreeHuf.hpp"
#include <iostream>
#include <vector>

#include <algorithm>//found there is a sort method in this library after trying to do it manually figured out it already existed!! : 

#include <numeric>
using namespace std;


string letterAr[26] = {"A", "B","C", "D","E", "F", "G", "H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

double freqAr[26] = {0.0817, 0.0145,0.0248,0.0431,0.1232, 0.0209, 0.0182, 0.0668, 0.0689, 0.0010, 0.0080, 0.0397, 0.0277, 0.0662,0.0781,0.0156,0.0009,0.0572,0.0628, 0.0905, 0.0304, 0.0102, 0.0264, 0.0015, 0.0211, 0.0005};

string letterAr2[26];
double workArr[26];
int countOrd = 0;


double ordFreq[26];
string ordLetter[26];

void printTable() {//print the freqency table out
cout << "Letters | Frequency" << endl;
    for(int i = 0; i < 26; i ++) {
        cout << letterAr[i] << " " << freqAr[i] << endl;
    }
}



void sortFreq() {//sorts the frequencies and the letters to be in the right order
    double lowNum = 100000;
    int index = 0;
    
        for(int i = 0; i < 26; i++) {
            if(workArr[i] < lowNum) {
                lowNum = workArr[i];
                index = i;
            }
        }
       
        //delete the number from workArr
        workArr[index] = 1000;
        //then put it in the array
       
        ordFreq[countOrd] = lowNum;

        //also put it in the ordered letter array
        ordLetter[countOrd] = letterAr[index];

        countOrd += 1;
       
}

void secArr() {
    for(int i = 0; i < size(freqAr); i++) {
        workArr[i] = freqAr[i];
    }
    cout << "THIS IS WORK ARR " << endl;
    for(int i = 0; i < size(freqAr); i++) {
        cout << workArr[i] << endl;
    }
    for(int i = 0; i < size(freqAr); i++) {
        letterAr2[i] = letterAr[i];
    }
}
int main(int argc, char *argv[]) {
    secArr();
    printTable();
    cout << endl << endl;
    Tree * treeArr[20];

   
    //sort the frequencies and take the first 2
    for(int i = 0; i < 26; i++) {
    sortFreq();
    }
    for(int i = 0; i < 26; i++) {
        cout << ordFreq[i] << endl;
    }
    


    double num1 = ordFreq[0];
    double num2 = ordFreq[1];
    double nodeValue = num1 + num2;

    string val = to_string(nodeValue);
    //cout << "val1 " << freqAr[index] << " val 2 " << freqAr[index2] << endl;
    //cout << "node Val: " << nodeValue << endl << "string " << val << endl;
    //first make the root node then the others until we get 1 at the root
    TreeNode* root = new TreeNode(val, nodeValue);
    Tree huffmanTree1;
    
    //insert the root then the 2 other values to make the first "tree"
    huffmanTree1.insertHuf(root->value(), nodeValue);
    huffmanTree1.insertHuf(ordLetter[0], ordFreq[0]);
    huffmanTree1.insertHuf(ordLetter[1], ordFreq[1]);

    cout << "Huffman Tree 1" << endl;
    huffmanTree1.printPreOrder();
    //cout << huffmanTree1.root()->left()->value();
    //cout << " " << huffmanTree1.root()->left()->freq();
    //delete the two letters that we added together from the letter Array and then add a new letter
    for(int i = 0; i < 26; i++) {
        if(letterAr2[i] == ordLetter[0] || letterAr2[i] == ordLetter[1]) {
            //delete from list
            letterAr[i] = "";
        }
    }
//then add the new tree at the end of the list
for(int i = 0; i < 26; i++) {
    if(letterAr2[i] == "") {
        letterAr2[i] = "X1";
        break;
    }
}

  
    
    
}