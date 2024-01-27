#include "luckyguess.h"

void getUserData(string& name, string& favFood, int& favNum){
    cout << "\n\nEnter your full name: ";
    getline(cin, name);
    cout << "\n\nEnter your favorite food: ";
    getline(cin, favFood);
    cout << "\n\nEnter your favorite number: ";
    cin >> favNum;
    cout << endl;
}

bool luckyGuess(int num){
    srand(time(0));
    int randNum = (rand() % 100) + 1;
    cout << "Random number: " << randNum << endl;
    return(randNum - 25 <= num && randNum + 25 >= num);
}