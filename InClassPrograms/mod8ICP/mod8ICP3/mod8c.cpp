#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char name1[30] = "Joey";
    string name2 = "Gavin";
    
    cout << "\n\nname1: ";
    for(int i = 0; i < strlen(name1); i ++){
        cout << name1[i];
    }
    cout << "\nname2: " + name2 + "\n\nWhat is your full name? ";
   
    cin.getline(name1, 30);
    cout <<"What is your friend's full name? ";
    getline(cin, name2);
    
    cout << "\nname1: ";
    for(int i = 0; i < strlen(name1); i ++){
        cout << name1[i];
    }
    cout << "\nname2: " + name2 + "\n\n";
    
    strcpy(name1, "SCOUT");
    name2 = "JACK";

    cout << "name1: ";
    for(int i = 0; name1[i] != '\0'; i++){
        cout << name1[i];
        if(name1[i + 1] != '\0'){
            cout << "*";
        }
    }
    cout << "*\n";


    cout << "name2: ";
    for(int i = 0; i < name2.length(); i++){
        cout << name2[i];
        if(i < name2.length() - 1){
            cout << "*";
        }
    }
    cout << "*\n";

    return 0;
}