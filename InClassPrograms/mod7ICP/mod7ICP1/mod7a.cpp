#include <iostream>
using namespace std;

void countCharacters(string phrase, int mode);


int main(){
    string userPhrase;
    cout << "Enter a string: ";
    getline(cin, userPhrase);
    cout << endl << endl;
    countCharacters(userPhrase, 1);
    cout << endl << endl;
    countCharacters(userPhrase, 2);
}

void countCharacters(string phrase, int mode){
    if(mode == 1){
        int numDigits = 0;
        for(int i = 0; i < phrase.length(); i++){
            if(isdigit(phrase[i])){
                numDigits++;
            }
        }
        cout << numDigits;
    }else{
        int numDesired = 0;
        for(int i = 0; i < phrase.length(); i++){
            if(ispunct(phrase[i])){
                numDesired++;
            }
        }
        cout << numDesired;
    }
}