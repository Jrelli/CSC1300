/*
    Title: lab3c.cpp
    Author: Joey R. Borrelli
    Date:   9/14/2023
    Purpose: 
*/
#include <iostream>
using namespace std;
int main(){
    // var to hold user input for quitting
    char quit = 'n';
    
    // constant to hold our math answer
    const int MATH_ANS = 22;
    
    // var to hold user answer for the math
    int userMath;
    
    // keeps asking for input if quit is not y or our answer is wrong.
    while(quit != 'y' || userMath != MATH_ANS){
        cout << "\nWhat do you get if you add 4 + 18? ";
        cin >> userMath;
        cout << "Enter the letter 'y' if you want to quit.\n";
        cin >> quit;
        cout << "The letter you entered is " << quit << endl;
        // outputs if our answer is wrong.
        if(userMath != MATH_ANS){
            cout << "Oh goat foot! You forgot how to add!\n";
        }
    }
    return 0;
}