#include <string>
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string fileName;
    string tempString;
    int numLoops = 0;
    cout << "Enter the file name you would like to read from: ";
    cin >> fileName;
    ifstream file(fileName);
    if(file.is_open()){
        while(!file.eof()){
            numLoops++;
            getline(file, tempString, '#');
            if(tempString == ""){
                break;
            }
            cout << numLoops << ") Title: " << tempString << ", Year: ";
            getline(file, tempString, '#');
            cout << tempString << ", Rotten Tomatoes Score: ";
            getline(file, tempString, '#');
            cout << tempString << endl;
        }
    }else{
        cout << "\n\nERROR: File failed to open, line 10: conditional file.is_open() is false\n\n";
    }
    return 0;
}