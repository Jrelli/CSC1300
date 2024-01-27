/*
    Title: lab3a.cpp
    Author: Joey R. Borrelli
    Date:   9/14/2023
    Purpose: Determines how much of a loser you are depending on how you spend your time studying and being on your phone.
*/

#include <iostream>
using namespace std;
// variables to hold hours
int screen;
int study;

int main(){
    // ask for input and store
    cout << "Enter Your average daily screen time in hours: ";
    cin >> screen;
    cout <<"\nEnter your average daily study time in hours: ";
    cin >> study;

    // outputs our results based on screen and study vars.
    if(screen <= 2 && study >= 6){
        cout << "\nYou need to socialize with people more often.";
    }else if(screen > 2 && study >= 6){
        cout << "\nYou need to socialize with people more often and get off that phone.";
    }else if(screen <= 2 && (study >= 2 && study < 6)){
        cout << "\nYou manage your time well.";
    }else if(screen > 2 && study < 6){
        cout << "\nWhat are you going to do if you lose that phone?\nIt is interfering with your ability to have a real life.";
    }
    
    return 0;
}