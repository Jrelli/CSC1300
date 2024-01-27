/*
    Title:      jrborrelli42_prog1.cpp
    Author:     Joey Borrelli
    Date:       9/25/2023
    Purpose:    guh
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(){
    ifstream inFile;
    string data;

    inFile.open("mod6b.txt");
    if(inFile.is_open()){
        for(int i; i < 7; i++){
            getline(inFile, data);
            cout << data << endl;
        }
    }
    inFile.close();

    return 0;
}