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
//https://cplusplus.com/reference/algorithm/sort/


#include <numeric>

#include <map>

using namespace std;



//unsorted arrays
//std::vector<string> letterV = {"A", "B","C", "D","E", "F", "G", "H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};
//std::vector<string> origLV = letterV;

//starts as unsorted but then gets sorted and used 
//std::vector<double> freqV = {0.0817, 0.0145,0.0248,0.0431,0.1232, 0.0209, 0.0182, 0.0668, 0.0689, 0.0010, 0.0080, 0.0397, 0.0277, 0.0662,0.0781,0.0156,0.0009,0.0572,0.0628, 0.0905, 0.0304, 0.0102, 0.0264, 0.0015, 0.0211, 0.0005};
//std::vector<double> origFV = freqV;
//std::map<string, double> pairData;


//vector of the pairs of frequency and letter
std::vector<std::pair<string, double>> ordPairs = {
    {"A", 0.0817},
    {"B", 0.0145},
    {"C", 0.0248},
    {"D", 0.0431},
    {"E", 0.1232},
    {"F", 0.0209},
    {"G", 0.0182},
    {"H", 0.0668},
    {"I", 0.0689},
    {"J", 0.0010},
    {"K", 0.0080},
    {"L", 0.0397},
    {"M", 0.0277},
    {"N", 0.0662},
    {"O", 0.0781},
    {"P", 0.0156},
    {"Q", 0.0009},
    {"R", 0.0572},
    {"S", 0.0628},
    {"T", 0.0905},
    {"U", 0.0304},
    {"V", 0.0102},
    {"W", 0.0264},
    {"X", 0.0015},
    {"Y", 0.0211},
    {"Z", 0.0005}
};

//map of every tree created in the recursive method
std::map<string/*id*/, Tree/*the tree*/> treeTable;

//makes a custom data structure to sort the vector of pairs all credit goes to will on this
struct  {
    #define HUF_LETTER pair<string, double>
    bool operator()(HUF_LETTER  a, HUF_LETTER b) const { return a.second < b.second;}
} customSort;

void printTable() {//print the freqency table out
cout << "Letters | Frequency" << endl;
    for(int i = 0; i < 26; i ++) {
        cout << ordPairs.at(i).first << ":" << ordPairs.at(i).second << endl;
    }
}



void printVectorL(vector<string> letterV) {
       cout << "Ord Letters " << endl;
    for(int i = 0; i < letterV.size(); i++) {
        cout << letterV.at(i) << endl;
    }
}
void printVectorN(vector<double> numV) {
    cout << "Ord Nums " << endl;
    for(int i = 0; i < numV.size(); i++) {
        cout << numV.at(i) << endl;
    }
}
void print() {
    //for(int i = 0; i < pairData.size(); i++) {
    for(auto val : ordPairs) {
        cout << val.first << ":"<< val.second << endl;
    }
}

vector<pair<string, double>> doHuf(vector<pair<string, double>> pairV) {

    if(pairV.size() == 1 && pairV.at(1).second == 1.0) {//only 1 tree left in the 
        return pairV;
    }

    sort(pairV.rbegin(), pairV.rend(), customSort);

    // pop off value
    HUF_LETTER thing = pairV.at(pairV.size()-1);//get the last element of the vector
    pairV.pop_back();//get rid of it
    
    //add to tree
    Tree newTree;
    //newTree.insertHuf(thing.first, thing.second);
    //treeTable.insert(std::pair<string, Tree>(thing.first + to_string(thing.second) ,newTree));//used for how to insert values into a map: https://cplusplus.com/reference/map/map/insert/
    //inserts into the map a pair of string, Tree the string is the letter and frequency together

    // case 1: value is a single pair
    if(treeTable.find(thing.first) == treeTable.end()) {
        // not a tree
    } else {
        // tree
        Tree huf = treeTable[thing.first];
    }

    // case 2: value is a tree




    // do this after removing lowest freq value, adding new tree, then sorting
    return doHuf(pairV);
}

int main(int argc, char *argv[]) {
    printTable();

    

    cout << endl;
    sort(ordPairs.rbegin(), ordPairs.rend(), customSort);
    print();

    //treeTable[doHuf(ordPairs).at(0).first];


    
/*
    printTable();
    cout << endl << endl;
    Tree huffmanTree1;
    

    //first thing to do is sort both the letter and freq vectors  
    sort(freqV.begin(), freqV.end());
    printVectorN(freqV);

    sortLetter();
    printVectorL(ordLetter);

    //sort the letter vector


    

    double num1 = ordFreq.at(0);
    double num2 = ordFreq.at(1);
    double nodeValue = num1 + num2;

    string val = to_string(nodeValue);
    //cout << "val1 " << freqAr[index] << " val 2 " << freqAr[index2] << endl;
    //cout << "node Val: " << nodeValue << endl << "string " << val << endl;
    //first make the root node then the others until we get 1 at the root
    TreeNode* root = new TreeNode(val, nodeValue);
   
   
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
            //delete from lists
            letterAr[i] = "";
        }
    }
    
   
    //new tree is identified by the comb of the left and right
    //add the frequency to the ordered list and delete the children from the frequency list
    //put in vector

   

    //then add the freq to the ordered list
    
    
    
    
    huffmanTree1.printPreOrder();
*/





  
    
    
}