#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    string title, year, score;
    int numLoops = 0;

    ifstream movieData("movieData1_windows.txt", ios::in);
    
    while(!movieData.eof()){
        numLoops++;
        getline(movieData, title);
        cout << numLoops << ") Title: " + title + ", ";
        getline(movieData, year);
        cout << "Year: " + year + ", ";
        getline(movieData, score);
        cout << "Rotten Tomatoes Score: " + score << endl;
    }

    return 0;
}