// includes the i/o package
#include <iostream>
#include <iomanip>
#include <string>

// prevents you from having to do std::cout and std::endl
using namespace std;

// Main method, int return type
int main(){
    
    int num = 5;
    double dec = 5.5;
    float dec2 = 5.5f;
    char character = 'a';
    string word = "bruh";

    // Characters out (stream object, I/O) inherited from line 1
    // <<, >> stream insertion operators
    cout << "Hello World!" << endl;
    cout << "Hello World!\n";
    cout << word << endl;
   
    // setw() sets the cursor to a specific location then pastes backwards
    cout << setw(10) << "CROCKETT";
    cout << setw(5) << "1300" << endl << setw(10) << "CLASS";
    /*
        \n newline
        \b backspace
        \r return goes to the beginning of the line
        \\ backslash
        \’ single quote
        \” double quote
    */

    cout << endl << "Please enter a number, decimal, and single letter: ";
    
    // Characters in, converts data to the desired type
    cin >> num >> dec >> character;
    
    cout << "This is num: " << num << "\nThis is a decimal: " << dec << "\nThis is a character: " << character;

    // 8/28/2023:
    /*
        char                                1 byte                  -128 to 127
        short                               2 bytes                 -32768 to 32767
        int                                 4 bytes                 -214483648 to 2147483647
        unsigned (no negative val) int      4 bytes                 0 to 4294967295
        long long                           8 bytes                 -9223372036854755808 to 9223372036854755807

        ASCII

        float                               4 bytes                 -3.4x10^38 to 3.4x10^38
        double                              8 bytes                 -1.7x10^308 to 1.7x10^308
        long double                         12 bytes                unlimited basically

        all floating point numbers are signed
        overflow error is trying to assign more data to a varible then is possible
    */
    int varName(50);
    int varName2 = 50;

    //const is the keyword for constants

    const int BUTTON_ID = 5;

    //A character literal is surrounded with single quotes:
    char middleInitial = 'R';
    //char middleInitial = (can insert ascii number here for the character);
    
    //All strings are stored with a null terminator (\0) at the end

    //must #include <string>


    string myName = "bruh";
    string varName3(myName,3);
    //varName = bru
    string name;
    cin >> name;//, only gets characters before spaces
    getline(cin, name); //gets spaces and gets rid of the \n at the end
    //part of <string> class

    cin.ignore();// will ignore one character (\n from the buffer)

    // Finish
    return 0;
}