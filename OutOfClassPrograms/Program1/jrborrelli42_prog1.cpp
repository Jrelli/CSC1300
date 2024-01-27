/*
    Title: jrborrelli42_prog1.cpp
    Author: Joey Borrelli
    Date: 9/1/2023
    Purpose:    A personality test with TEN questions that will test 
                the user to see which type of donut they represent.
*/
#include <string>
#include <iostream>
using namespace std;

// Gloabal variables to hold my total counts for each dount.
int glazed, peanut, cream, twist, blueb, choco;

// Function that runs after every question, incriments my global vars
void addPoint(char answ){
    // var to hold if input is valid, set to false so loop will run the first time
    bool validInput;
    
    // looped so that if input is invalid it will run again
    do{
        // switch case that will incriment my vars and check my input
        switch(toupper(answ)){
            case 'A':
                validInput = true;
                glazed++;
                break;
            case 'B':
                validInput = true;
                peanut++;
                break;
            case 'C':
                validInput = true;
                cream++;
                break;
            case 'D':
                validInput = true;
                twist++;
                break;
            case 'E':
                validInput = true;
                blueb++;
                break;
            case 'F':
                validInput = true;
                choco++;
                break;
            default:
                cout << "INVALID INPUT\nENTER AGAIN: ";
                cin >> answ;
                validInput = false;
        }
    // loops again if we didn't get a valid input
    }while(!validInput);
}

int main(){
    // vars to hold answer and the play again status
    char ans;
    char playAgain;
    
    // do while loop allows us to repeat if we want to play again
    do{
        // sets vars to 0 because they need to reset if we play again
        glazed = 0;
        peanut = 0;
        cream = 0;
        twist = 0;
        blueb = 0;
        choco = 0;

        cout << "\n\nWELCOME, ANSWER THESE NEXT 10 QUESTIONS TO FIGURE OUT WHAT TYPE OF DONUT YOU ARE!:\n\n";
        
        // asks questions, gets answers, runs increment funciton
        cout << "What is your favorite desert?:\nA. Donuts\nB. Resses\nC. Apple Strudle\nD. Pound Cake\nE. Chocolate Strawberries\nF. Chocolate Birthday Cake\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        cout << "\nWhere would you like to travel?:\nA. Italy\nB. China\nC. France\nD. Sweden\nE. Dubai\nF. Ukraine\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        cout << "\nWhat's your favorite videogame?:\nA. CS:GO\nB. Fortnite\nC. Pubg\nD. Apex Legends\nE. Forza\nF. Minecraft\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        cout << "\nWho is your favorite early church father?:\nA. St. Ambrose of Milan\nB. St. Augustine of Hippo\nC. St. Jerome\nD. St. John Chrysostom\nE. St. Athanasius of Alexandria\nF. St. Basil of Caesarea\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        cout << "\nWhat is your favorite sport?:\nA. Soccer\nB. Football\nC. Basketball\nD. Wrestling\nE. MMA\nF. Boxing\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        cout << "\nWhich is your favorite book of the Bible?:\nA. Matthew\nB. Mark\nC. Luke\nD. John\nE. 1st Maccabees\nF. Psalms\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        cout << "\nWhat is your favorite color?:\nA. White\nB. Blue\nC. Green\nD. Red\nE. Yellow\nF. Orange\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        cout << "\nWho is your least favorite dictator?:\nA. Hitler\nB. Mao Zedong\nC. Kim Jung Un\nD. Kim Il Sung\nE. Hugo Chavez\nF. Joseph Stalin\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        cout << "\nWhats your favorite month?:\nA. January\nB. Febuary\nC. March\nD. April\nE. May\nF. June\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        cout << "\nWho is your favorite biblical character?:\nA. Jesus\nB. Mary (the mother of Jesus)\nC. Elijah\nD. King David\nE. Adam\nF. Noah\n\nEnter your answer: ";
        cin >> ans;
        addPoint(ans);

        //Print out overall results:
        cout << "\n\nOverall results:\n\nGlazed: " << glazed << "\nPeanut Butter: " << peanut << "\nCream filled: " << cream << "\nTwist: " << twist << "\nBlueberry: " << blueb << "\nChocolate: " << choco << endl;
        
        // array to hold results for us to iterate through
        int results[6] = {glazed, peanut, cream, twist, blueb, choco};
        
        // ints to hold our largest num and our result's index
        int largest = 0;
        int resultIDX;
        
        // iterates through list to find biggest num
        for(int i = 0; i < (sizeof(results) / sizeof(int));i++){
            if(results[i] > largest){
                largest = results[i];
                resultIDX = i;
            }
        }

        // now that we have our largest, find if there is another equally large num
        for(int i = 0; i < (sizeof(results) / sizeof(int));i++){
            if(results[i] == largest && i != resultIDX){
                resultIDX = 88;
            }
        }
        
        //Print out which donut you are:
        switch(resultIDX){
            case 0:
                cout << "\nYou are a glazed donut!\n";
                break;
            case 1:
                cout << "\nYou are a peanut butter donut!\n";
                break;
            case 2:
                cout << "\nYou are a cream filled donut!\n";
                break;
            case 3:
                cout << "\nYou are a glazed twist donut!\n";
                break;
            case 4:
                cout << "\nYou are a blueberry donut!\n";
                break;
            case 5:
                cout << "\nYou are a chocolate donut!\n";
                break;
            case 88:
                cout << "\nSorry, I do not know what you are. I think you are confused.\n";
                break;
            default:
                cout << "\nERROR: switch case on line 115, variable result not populated properly.\n";
        }

        // do while loop to validate input
        do{
            // gets input from user 
            cout << "\nDo you want to play again? (y/n)\nEnter: ";
            cin >> playAgain;
        }while(toupper(playAgain) != 'Y' && toupper(playAgain) != 'N');   
            
    // repeat if answer was yes
    }while(toupper(playAgain) == 'Y');
    
    return 0;
}