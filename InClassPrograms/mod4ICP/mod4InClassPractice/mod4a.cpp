/*
    Title: mod4a.cpp
    Author: Joey Borrelli
    Date: 9/6/2023
    Purpose:    a program for a restaurant host to assist them with seating patrons
*/
#include <iostream>
using namespace std;
int main(){
    int numInParty;
    cout << "How many people are in your party?: ";
    cin >> numInParty;
    if(numInParty <=2 ){
        cout << "\nYou may be seated at a small table.\n\n";
    }else{
        cout << "\nYou may be seated at a large table.\n\n";
    }
    return 0;
}