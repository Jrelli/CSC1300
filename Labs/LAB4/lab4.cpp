/*
    Title:      lab4.cpp
    Author:     Joey Borrelli
    Date:       9/21/2023
    Purpose:    replace inputed text's abreviations with the full text.
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    char again; // char to hold users input if they want to run the program again.
    string userInput; // string to hold the raw undecoded input, and the decoded version
    int numAbrv; // int to hold number of abbreviations changed
    size_t foundStr; // holds starting int of desired string 
    
    // loops as long as the user wants to keep decoding.
    do{
        // resets vars 
        int numAbrv = 0;
        size_t foundStr = 0;

        //gets users inputed string
        cout << "\nEnter text: ";
        getline(cin, userInput);

        // outuputs their input
        cout << "You entered: ";
        cout << userInput;

        // while an instance of the desired string is found
        do{
            // finding "BFF"
            foundStr = userInput.find("BFF", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 3, "best friend forever");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;
        
        // while an instance of the desired string is found
        do{
            // finding "IDK"
            foundStr = userInput.find("IDK", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 3, "I don't know");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;

        // while an instance of the desired string is found
        do{
            // finding "JK"
            foundStr = userInput.find("JK", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 2, "just kidding");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;

        // while an instance of the desired string is found
        do{
            // finding "TMI"
            foundStr = userInput.find("TMI", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 3, "too much information");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;

        // while an instance of the desired string is found
        do{
            // finding "TTYL"
            foundStr = userInput.find("TTYL", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 4, "talk to you later");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;

        // while an instance of the desired string is found
        do{
            // finding "YMMD"
            foundStr = userInput.find("YMMD", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 4, "you made my day");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;

        // while an instance of the desired string is found
        do{
            // finding "TMI"
            foundStr = userInput.find("W8", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 2, "wait");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;

        // while an instance of the desired string is found
        do{
            // finding "QT"
            foundStr = userInput.find("QT", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 3, "cutie");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;

        // while an instance of the desired string is found
        do{ 
            // finding "AYTMTB"
            foundStr = userInput.find("AYTMTB", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 6, "and you're telling me this because");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;

        // while an instance of the desired string is found
        do{
            // finding "LOL"
            foundStr = userInput.find("LOL", foundStr);
            //if it finds the string
            if (foundStr != string::npos){
                // replace the string
                userInput.replace(foundStr, 3, "laugh out loud");
                // incriment the var
                numAbrv++;
            }
        }while(foundStr != string::npos);
        // reset found string index
        foundStr = 0;

        // outputs the expanded string and the number of abbreviations.
        cout << "\nExpanded: " << userInput;
        cout << "\n\nNumber of abbreviations expanded: " << numAbrv;

        // asks if we want to play again.
        cout << "\nDo you want to encode another mesage? (y or n): ";
        cin >> again;

        // tab down a line
        cout << endl;
        
        // clears input so it can loop again
        cin.ignore();

    }while(again == 'y');

    return 0;
}