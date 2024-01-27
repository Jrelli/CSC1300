#include <iostream>

using namespace std;

int main(){
    int userInput;
    string* dogName;
    string* dogBreed;
    int* dogAge;
    cout << "\n\nHow many dogs can you adopt? ";
    cin >> userInput;

    dogName = new string[userInput];
    dogBreed = new string[userInput];
    dogAge = new int[userInput];

    cout << "\n********************\n";
    cout << "Enter the dog data:";
    
    for(int i = 0; i < userInput; i++){
        cout << "\n*****DOG " << i + 1 << "*****\n";
        cout << "Name:      ";
        cin.ignore();
        getline(cin, *(dogName + i));
        cout << "Breed:     ";
        getline(cin, *(dogBreed + i));
        cout << "Age:       ";
        cin >> *(dogAge + i);
    }

    cout << "\n********************\n";
    cout << "Print the dogs:";

    for(int i = 0; i < userInput; i++){
        cout << "\n*****DOG " << i + 1 << "*****\n";
        cout << "Name:      " << *(dogName + i) << endl;
        cout << "Breed:     " << *(dogBreed + i) << endl;
        cout << "Age:       " << *(dogAge + i) << endl;
    }
    
    return 0;
}