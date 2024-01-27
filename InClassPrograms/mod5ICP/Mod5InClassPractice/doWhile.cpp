// mod5a In-Class Practice
// Description : Generate random number between 7 and 77. Calculate sum of random numbers. 
//              Ask user to guess the random number.
using namespace std;
#include<iostream>
#include<time.h>
int main(){
	
	int rnum=0; 	//rnum holds the random number generated
	int trnum=0; 	//trnum is set to the total number of random numbers that need to be generated
	int i=0;		//i is a counter for the while loop that generates the random numbers
	int guess=0; 	//guess will hold the user's guess
	int low =7; 	//low is the lower limit for the random number generated
	int high=77; 	//high is the upper limit for the random number generated
	char tryAgain;
	
	//seed the random number generator
	srand (time(0));
	
	do{
		// generates a random number between the low & high range inclusively
		rnum = rand() % (high + 1 - low) + low;
		
		// gets guess from user
		cout << "\n\nGuess a number between " << low << " and " << high << ":  ";
		cin >> guess;
		
		// validates if the user entered a number in the valid range (7 to 77). Both 7 & 77 are included in the valid range.
		while(guess < 7 || guess > 77){
			cout << "The number is not in the valid range!\n";
			cout << "Guess a number between " << low << " and " << high << ":  ";
			cin >> guess;
		}
		
		// checks if our guess is right
		if(guess == rnum){
			cout << "\n\nYou have gained the super power where skittles can shoot from your fingertips!\n\n";
		}else{
			cout << "\n\nYou get no super powers.  The random number was " << rnum << endl << endl;
		}

        int validInput = 0;
		// Checks if we want to play again, and validates input
		do{
			if(validInput > 0){
                cout << "Not a valid input, try again.\n";
            }
            cout << "Do you want to play again? (y/n):\n";
			cin >> tryAgain;
            validInput++;
            // cout << (char)toupper(tryAgain); 
            // cout << (((char)toupper(tryAgain) != 'N') || ((char)toupper(tryAgain) != 'Y'));
		}while((char)toupper(tryAgain) != 'N' && (char)toupper(tryAgain) != 'Y');
	
	}while(toupper(tryAgain) == 'Y');
	
	return 0;
}