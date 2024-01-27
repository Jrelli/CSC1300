#include<iostream>
using namespace std;

const int NUM_ITEMS = 10;

int main(){
    string names[NUM_ITEMS];
    string tempString;
    double prices[NUM_ITEMS];

    cout << "\n\nTell me 10 useful things and their price:\n";

    for(int i = 1; i <= NUM_ITEMS; i++){
        cout << "USEFUL THING " << i << ": ";
        getline(cin, names[i - 1]);
        cout << "PRICE FOR THING " << i << ": ";
        getline(cin, tempString);
        prices[i - 1] = stod(tempString);
    }

    cout << "\nYour list of useful tiems include: \n";
    for(int i = 0; i < 10; i++){
        cout << names[i] << ", $" << prices[i] << endl;
    }
    return 0;
}