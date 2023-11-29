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

    sort(pairV.rbegin(), pairV.rend(), customSort);//sort

    HUF_LETTER lowFreqVal = pairV.at(pairV.size()-1);//get the last element of the vector
    pairV.pop_back();//get rid of it
    
    //add to tree
    Tree newTree;
 
    // case 1: value is a single pair
    if(treeTable.find(lowFreqVal.first) == treeTable.end()) {
        newTree.insertHuf(lowFreqVal.first, lowFreqVal.second);//make it a tree
        // TODO: get total freq of all items in tree
        pairV.push_back({lowFreqVal.first, lowFreqVal.second});//add it back into the pool of frequencies
        treeTable[lowFreqVal.first] = newTree;//add the new tree to the tree map (treeTable)
    } else { 
        // case 2: value is a tree
       
        Tree huf = treeTable[lowFreqVal.first];
        HUF_LETTER seclowFreqVal = pairV.at(pairV.size()-1);
        pairV.pop_back();//get the second lowest value

        if(treeTable.find(seclowFreqVal.first) == treeTable.end()) {//if the second lowest value in the vector is a tree
            //new insert method to add a node to a tree
            //lowFreqVal and seclowFreqVal are both of the "trees"

            
            
        }
        else {//it is not a tree just a pair
            newTree.insertHuf(seclowFreqVal.first, seclowFreqVal.second);//put the pair into the tree
        }

        //add the tree back into the vector to then be combined with another tree later
        pairV.push_back( pair<string, double> (newTree.root()->value().first, newTree.root()->value().second));

    }

    return doHuf(pairV);//keep returning the vector 
}

int main(int argc, char *argv[]) {
    printTable();

    

    cout << endl;
    sort(ordPairs.rbegin(), ordPairs.rend(), customSort);
    print();

    treeTable[doHuf(ordPairs).at(0).first];



  
    
    
}