/*
    File Name:          Lab6.cpp
    Creator Name:       Joey R. Borrelli
    Date Started:       10/05/2023
    Program Purpose:    Print out cool picture and count goblin sick days
*/

#include <iostream>
using namespace std;

// var that our program loops on
bool endProgram = false;

void goblinSickDays(); // takes in and prints how many days the goblins were sick for
int displayMenuChoice(); // loops through display and takes in input
int displayCoolMessage(int numTimes); // displays a cool message and incriments the times its ran

int main(){
    int userInput; // holds user input
    int numPrintedCoolMessage = 0; // var to hold how many times the cool message was printed
    
    //loops as long as the user wants to continue
    do{
        userInput = displayMenuChoice(); //returns user choice
        // runs the function we want based on user choice
        switch (userInput){
            case 1:
                goblinSickDays();
                break;
            case 2:
                numPrintedCoolMessage = displayCoolMessage(numPrintedCoolMessage); // displays cool message and returns the number of times ran
                break;
            case 3: // falls to default, which outputs final message and ends us
            default:
                endProgram = true;
                cout << "Number of times you printed a cool image: " << numPrintedCoolMessage << endl << "Bye!\n\n";
                break;
        }
    }while(!endProgram);
    return 1;
}

void goblinSickDays(){
    int numGoblinTellers = 0; //holds the number of golbin tellers we have
    int totalDaysSick = 0; //holds the number of total sick days
    int tempNum = 0; // works as a buffer between the user's input and adding it to totalSick days
    cout << "How many golbin tellers?\nEnter: ";
    cin >> numGoblinTellers;
    cout << endl;
    // loops for however many tellers
    for(int i = 1; i < numGoblinTellers + 1;i++){
        // loops for each of the 3 years
        for(int j = 1; j < 4;j++){
            cout << "How many days in year " << j << " was goblin number " << i << " sick?\nEnter: ";
            cin >> tempNum;
            totalDaysSick += tempNum;
            cout << endl;
        }
    }
    // final output
    cout << "The " << numGoblinTellers << " goblins were out sick for a total of " << totalDaysSick << " days during the last 3 years.\n";
}

int displayCoolMessage(int numTimes){
    numTimes++;//incriment
    //prints out cool message
    cout << " /$$$$$$$                      /$$             /$$      /$$\n";                              
    cout << "| $$__  $$                    | $$            | $$$    /$$$\n";                                          
    cout << "| $$  \\ $$  /$$$$$$  /$$   /$$| $$$$$$$       | $$$$  /$$$$  /$$$$$$  /$$$$$$$   /$$$$$$  /$$   /$$\n";
    cout << "| $$$$$$$  /$$__  $$| $$  | $$| $$__  $$      | $$ $$/$$ $$ /$$__  $$| $$__  $$ /$$__  $$| $$  | $$\n" ;
    cout << "| $$__  $$| $$  \\__/| $$  | $$| $$  \\ $$      | $$  $$$| $$| $$  \\ $$| $$  \\ $$| $$$$$$$$| $$  | $$\n";
    cout << "| $$  \\ $$| $$      | $$  | $$| $$  | $$      | $$\\  $ | $$| $$  | $$| $$  | $$| $$_____/| $$  | $$\n";
    cout << "| $$$$$$$/| $$      |  $$$$$$/| $$  | $$      | $$ \\/  | $$|  $$$$$$/| $$  | $$|  $$$$$$$|  $$$$$$$\n" ;
    cout << "|_______/ |__/       \\______/ |__/  |__/      |__/     |__/ \\______/ |__/  |__/ \\_______/ \\____  $$\n" ;   
    cout << "                                                                                          /$$  | $$\n"  ;    
    cout << "                                                                                         |  $$$$$$/\n"   ;   
    cout << "                                                                                          \\______/\n";
    // returns incriment
    return(numTimes);
}

int displayMenuChoice(){
    //holds user input
    int input;
    cout << "\n\nWELCOME TO GRINGOTT's BANK!\n\n";
    //loop checks user input
    do{
        cout << "Please choose one of the following options:\n\t1 - Enter Goblin Sick Days\n\t2 - Display Something Cool\n\t3 - End the Program\n\nCHOICE: ";
        cin >> input;
    }while(input < 0 && input > 4);
    cout << endl << endl;
    //returns our input
    return(input);
}