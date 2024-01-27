/*
    File Name:          Functions.cpp
    Creator Name:       Joey R. Borrelli
    Date Started:       10/19/2023
    Program Purpose:    holds my functions
*/

#include "lab7.h"

/*
Asks the user for all the data and read it in in a neat 
easy-to-understand format.
*/
void getData(string& n1, string& n2, int& a1, int& a2, string& p1, string& p2){
    string tempString;

    cout << "\nEnter the data for the first super hero:\nNAME: ";
    getline(cin, n1);
    cout << "\nAGE: ";
    getline(cin, tempString);
    a1 = stoi(tempString);
    cout << "\nPET (dog/cat/rabbit/guinea pig) : ";
    getline(cin, p1);
    
    cout << "\n\nEnter the data for the second super hero:\nNAME: ";
    getline(cin, n2);
    cout << "\nAGE: ";
    getline(cin, tempString);
    a2 = stoi(tempString);
    cout << "\nPET (dog/cat/rabbit/guinea pig) : ";
    getline(cin, p2);

    cout << "\n\n";
}

/*
Determines if two out of the three checks were true and 
if so, returns true. Otherwise, returns false.
*/
bool calculateResults(string n1, string n2, int a1, int a2, string p1, string p2){
    int val1, val2, trues = 0;

    for(int i = 0; i < static_cast<int>(n1.length()); i++){
        val1 += static_cast<int>(n1.at(i));
    }
    cout << "The added ASCII value of " + n1 + " is " << val1 << endl;

    for(int i = 0; i < static_cast<int>(n2.length()); i++){
        val2 += static_cast<int>(n2.at(i));
    }
    cout << "The added ASCII value of " + n2 + " is " << val2 << endl;

    if((val1 - val2) <= 50 && (val1 - val2) >= -50){
        cout << "CHECK 1 is true\n";
        trues++;
    }else{
        cout << "CHECK 1 is false\n";
    }

    if(a1 <= (a2 + 10) && a1 >= (a2 - 10)){
        cout << "CHECK 2 is true\n";
        trues++;
    }else{
        cout << "CHECK 2 is false\n";
    }

    if(p1 == p2){
        cout << "CHECK 3 is true\n";
        trues++;
    }else{
        cout << "CHECK 3 is false\n";
    }

    return(trues >=2);
}