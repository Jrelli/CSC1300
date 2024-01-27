/*
	Title:    mod5c.cpp
	Author:   Joey R. Borrelli
	Date:     9/15
	Purpose:  Practice for loops (in-class practice)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	int rnum = 0; 	//rnum holds the random number generated
	int total = 0;  	//total for the particular ability
	int oddRoll = 1;	//holds the number of times an ODD roll occurred
	int rollNum = 0;	//Number of times dice has been rolled for this ability
	
	
	//seed the random number generator
	srand (time(0));
	
	cout << "\nDnD Stat Roll\n";
	cout << "1 - Strength\n";
	cout << "2 - Dexterity\n";
	cout << "3 - Constitution\n";
	cout << "4 - Intelligence\n";
	cout << "5 - Wisdom\n";
	cout << "6 - Charisma\n";
	
	cout << "\nFor your character stats, I am rolling a"
			" 6-sided die until an ODD dice roll \noccurs more "
			"than once OR the total of all dice rolled so far is equal\n"
			"to or exceeds 20, whichever comes first.\n\nIf the total "
			"exceeds 20, then the last dice roll is removed.\n\n"
			"I will then print the result for each ability score.\n\n";
	
	//ADD ALL YOUR CODE BELOW 
	//MAKE SURE YOU HAVE AT LEAST ONE FOR LOOP AND TWO LOOPS IN TOTAL.  
	//USE THE PROVIDED VARIABLES THAT HAVE BEEN DEFINED
	
	for (int i = 1; i <= 6; i++){
		while(oddRoll <= 1 && rollNum < 20){
			rnum = (rand() % 6) + 1;
			cout << "roll " << rollNum << ": " << rnum << endl;
			if(rnum % 2 != 0)
				oddRoll++;
			total += rnum;
			rollNum++;
		}
		if(total > 20){
			total = total - rnum;
		}	
		cout << "Ability #" << i << "'s score is: " << total << endl;
	}
	return 0;
}