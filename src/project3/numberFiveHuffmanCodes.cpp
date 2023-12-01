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
#include "TreeNodeHuf.hpp"
#include "TreeHuf.hpp"

//https://cplusplus.com/reference/algorithm/sort/
#include <algorithm>//found there is a sort method in this library after trying to do it manually figured out it already existed!! : 
#include <numeric>

#include <map>
#include <iostream>
#include <vector>

using namespace std;

// Alias for letter+freq
#define HUF_LETTER pair<string, double>

//vector of the pairs of frequency and letter
vector<HUF_LETTER> ordPairs = {
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
    {"Z", 0.0006}
};

//map of every tree created in the recursive method
map<string /*id*/, Tree /*the tree pointer*/> treeTable;


//makes a custom data structure to sort the vector of pairs all credit goes to will on this
struct {
    bool operator()(HUF_LETTER  a, HUF_LETTER b) const { return a.second < b.second;}
} customSort;

vector<HUF_LETTER> doHuf(vector<pair<string, double>> pairV) {
    //&& pairV.at(1).second == 1.0
    if(pairV.size() == 1) { 
        // only 1 tree left in the 
        return pairV;
    }
    
    std::sort(pairV.rbegin(), pairV.rend(), customSort);

    HUF_LETTER lowFreqVal = pairV.at(pairV.size()-1); // get the last element of the vector
    pairV.pop_back(); // get rid of it
     
    // case 1: value is a single pair
    if(treeTable.find(lowFreqVal.first) == treeTable.end()) {
        // add to tree
        Tree newTree;

        // value isn't a tree 
        newTree.insertHuf(lowFreqVal.first, lowFreqVal.second); // make it a tree
        
        pairV.push_back({lowFreqVal.first, lowFreqVal.second}); // add it back into the pool of frequencies
        treeTable[lowFreqVal.first] = newTree; // add the new tree to the tree map (treeTable)
    } else { 
        // case 2: value is a tree
        Tree tree1 = treeTable[lowFreqVal.first];
        
        // get the second lowest value
        HUF_LETTER secLowFreqVal = pairV.at(pairV.size()-1);
        pairV.pop_back(); // get the second lowest value

        // if the second lowest value in the vector is a tree
        if(treeTable.find(secLowFreqVal.first) != treeTable.end()) { 
            // assign tree variables to the 2 lowest values and get the roots of the trees to then be used to add them togethe
            Tree tree2 = treeTable[secLowFreqVal.first];
            
            // lowFreq val is the node you are inserting into the seclowval tree 
            TreeNode* toBeInserted = tree1.root();
            // call the node insert method to insert toBeInserted node into tree2 
            
            double totalFreq = tree1.getFreq();
            tree2.insertNodeHuf(toBeInserted, totalFreq);

            // then remove tree2 from the map (remove the tree we added to the other tree)
            if(treeTable.size() > 1) {
                treeTable.erase(tree2.root()->value().first);
            }

            // tree1 will be added back but technically it's tree2
            tree1 = tree2;
        } else { // it is not a tree just a pair
            tree1.insertHuf(secLowFreqVal.first, secLowFreqVal.second);//put the pair into the tree
        }
        
        // Update tree in table
        treeTable[lowFreqVal.first] = tree1;
        
        // add the tree back into the vector to then be combined with another tree later
    

        
        pairV.push_back({tree1.root()->value().first, tree1.root()->value().second});
    
    }
   

    return doHuf(pairV);//keep returning the vector 
}


int main(int argc, char *argv[]) {
    std::sort(ordPairs.rbegin(), ordPairs.rend(), customSort);
    cout << "vector after sort: " << endl;
    for(auto val : ordPairs) {
        cout << val.first << ":" << val.second << endl;
    }

    Tree hufTree = treeTable[doHuf(ordPairs).at(0).first];
    cout << "trees:" << endl;
    /*
    for (auto v : treeTable) {
        cout << v.first << ":" << v.second << endl;
        if(v.second) {
            if(v.second.root()) {
                cout << v.second->root()->value().first << endl;
            }
        }
    } 
    */
    hufTree.printInOrder();
    
    cout << "after doHuf: " << endl;
    for(auto val : ordPairs) {
        cout << val.first << ":" << val.second << endl;
    }

    // Set root of tree to non-letter value and set the freq    
    TreeNode* val = new TreeNode("root", hufTree.getFreq());
    val->right() = hufTree.root();
    val->left() = hufTree.root()->left();
    hufTree.root() = val;

    cout << "VALUE : " << hufTree.root()->value().second << endl;
    cout << "new tree :" << endl;
    hufTree.printInOrder();

    for(TreeNode* curr = hufTree.root(); curr; curr = curr->right()) {
        cout << *curr << endl;
    }

    return 0;
}