/*
	Title:  	Lab3b.cpp
	Author:		Joey R. Borrelli
	Date:		9/14/2023
	Purpose:	learning switch statements
*/

#include <iostream>
using namespace std;

int main()
{
	// var to hold grade entered
	char grade;

	// gets grade from user
	cout << "What grade will you earn on this lab assignment?" << endl;
	cout << "GRADE: ";
	cin >> grade;

	//checks our grade and outputs accordingly
	switch(grade){
		case 'A':
			cout << "An A - you rock!!\n";
			break;
		case 'B':
			cout << "You got a B - good job.\n" ;
			break;
		case 'C':
			cout << "Earning a C is satisfactory.\n";
			break;
		case 'D':
			cout << "While D is passing, there is a problem.\n";
			cout << "You really didnt learn much.\n";
			break;
		case 'F':
			cout << "Oh BARF!  You failed - better luck next time.\n";
			break;
		default:
			cout << "You did not enter an A, B, C, D, or F.\n";
	}
	
	/* PREVIOUS CODE */
	// if (grade == 'A')
	// 	cout << "An A - you rock!!\n";
	// else if (grade == 'B')
	// 	cout << "You got a B - good job.\n" ;
	// else if ( grade =='C')
	// 	cout << "Earning a C is satisfactory.\n";
	// else if(grade == 'D')
	// {
	// 	cout << "While D is passing, there is a problem.\n";
	// 	cout << "You really didnt learn much.\n";
	// }
	// else if (grade =='F')
	// 	cout << "Oh BARF!  You failed - better luck next time.\n";
	// else
	// 	cout << "You did not enter an A, B, C, D, or F.\n";

    return 0;
}