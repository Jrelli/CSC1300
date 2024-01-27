#include <iostream>
using namespace std;

void getUserData(string& name, string& favFood, int& favNum);
bool luckyGuess(int num);

int main(){
    string name;
    string favFood;
    int favNum;

    getUserData(name, favFood, favNum);
    
    if(luckyGuess(favNum)){
        cout << name + ", you will get a lifetime supply of " + favFood << "!" << endl;
    }else{
        cout << name + ", sorry, you get no " + favFood << endl;
    }
    return 1;
}

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