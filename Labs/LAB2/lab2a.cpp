/*
    Title: lab2a.cpp
    Author: N/A, debugged by Joey and Shane
    Date: August 31, 2023
    Purpose:    The program should ask the user for their name, display a welcome message (with 
                their name), and then print you & your partner’s names and a fun fact about each of you.   
                Then the program should ask the user for the radius of a circle, then calculate and print the area.
*/
#include <cmath>
#include <iostream>
using namespace std;

int main(){
    string name;
    double radius;
    const double PI = 3.14;
    double area;
    
    //print welcome message after getting user's name
    cout << "What is your name? ";
    cin >> name;
    cout << "Hi, " << name << ", welcome to this program!\n";

    //introduce lab partners and tell fun facts about yourselves
    cout << "Our names are Joey and Shane.\n\n";
    cout << "A fun fact about Joey is he lead his robotics programming team in highschool.\n\n";
    cout << "A fun fact about Shane is he has dual citizenship to the USA and Signapore.\n\n";

    //calculate the area of user's circle
    cout << "What is the radius of your circle? ";
    cin >> radius;
    area = PI * pow(radius, 2.0);
    cout << "\nThe area of your circle is " << area << endl << endl;

    return 0;
}