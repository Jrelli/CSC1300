/*
    Title:      jrborrelli42_prog1.cpp
    Author:     Joey Borrelli
    Date:       9/1/2023
    Purpose:    open a text file named mod6a.txt as an output file, then writes your nickname, expected graduation data, a random fact, and then says done wrtiing to file.  
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ofstream outFile;

    outFile.open("mod6a.txt");
    outFile << "Jrelli" << endl;
    outFile << "2027" << endl;
    outFile << "I enjoy reading" << endl;
    outFile.close();
    cout << "Done writing to file." << endl;

    return 0;
}