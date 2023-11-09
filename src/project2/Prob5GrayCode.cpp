/*

D$ && The Cents
Project #2 - Problem 5 - Gray Codes

Max Hoffman

*/


#include <iostream>
#include <vector>

using namespace std;

std::vector<std::string> list1;
std::vector<std::string> list2;
std::vector<std::string> list3;

//used for syntax for vectors since this is the first time I have used them
//https://cplusplus.com/reference/vector/vector/

//used to print out the vectors
void print(vector<string> toPrint) {
    cout << "-----" << endl;
     for(int i = 0; i < toPrint.size(); i++) {
        cout << toPrint.at(i) << " ";
    }
    cout << endl;
    cout << "-----" << endl;
}


//adds zeroes to the beginning of each of the entries in the vector
void addZeros(vector<string> &toAppend) {
    for(int i = 0; i < toAppend.size(); i++) {
        toAppend.at(i) = "0" + toAppend.at(i);
    }

}


//adds the 1s to the beginning of each entry in the vector
void addOnes(vector<string> &toAppend) {
    for(int i = 0; i < toAppend.size(); i++) {
        toAppend.at(i) = "1" + toAppend.at(i);
    }
    
}

void combLists(vector<string> &List1, vector<string> &List2, vector<string> List3) {
    //add contents of List1 to the combined list
    for(int i = 0; i < list1.size(); i++) {
        list3.push_back(list1.at(i));
    }

    //add the second half to combined list
    for(int i = 0; i < list2.size(); i++) {
        list3.push_back(list2.at(i));
    }


}

int main(int argc, char *argv[]) {
    string num1;
    string num2;

    string labels[5] = {"1 bit -> 2 bits", "2 bits -> 3 bits", "3 bits -> 4 bits", "4 bits -> 5 bits", "5 bits -> 6 bits"};//used to identify what combined list is what
    int count = 1;
    int labelC = 0;

    //get the input string and assign to list 1
    cout << "Enter 1 Bit Input : (# #)" << endl;
    cin >> num1;
    cin >> num2;
    list1.push_back(num1);
    list1.push_back(num2);

    cout << endl;
    
    cout << "1 Bit Input String : " << endl;
    print(list1);

    while(count != 6) {//start from 1 bit to 6 bits so we do this 6 times
        //sets list 2 equal to list 1's reversal
        for(int i = list1.size() -1; i >= 0; i--) {
            list2.push_back(list1.at(i));
        }

   

    
    addZeros(list1);//add leading zeroes to list 1
    addOnes(list2);//add leading ones to list 2
    combLists(list1, list2, list3);//combine the lists into list 3

    cout << "New Combined List " << labels[labelC] << " : " << endl;//print out what we are converting
    print(list3);


    //clear list 1 and 2 since we are done with them and only need the combined list for the next step
    list1.clear();
    list2.clear();
    //set List 1 equal to the new combined list
    list1 = list3;
    //clear the combined list to be filled with the new combined list
    list3.clear();

    count++;
    labelC++;
    }


    return 0;
}