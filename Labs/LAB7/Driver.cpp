/*
    File Name:          Driver.cpp
    Creator Name:       Joey R. Borrelli
    Date Started:       10/19/2023
    Program Purpose:    Checks if super heros will be roommates
*/

#include "lab7.h"

/*
    Print out “Super Hero Roommate Compatibility Check”
    Call the getData() function, sending two strings that 
    will hold the super hero’s names, two integers that will 
    hold the hero’s ages, and two strings that will hold the 
    hero’s pets. Call the calculateResults() function, sending
    the hero’s names, ages, and pets to the function. This 
    function returns a Boolean. True if the heroes are compatible
    and false otherwise. Last, if the heroes are compatible, 
    print their names and print that they are compatible to be 
    roommates. Otherwise, print their names and that they are 
    not compatible.
*/
int main(){
    string name1, name2, pet1, pet2;
    int age1, age2;

    cout << "\nSuper Hero Roommate Compatibility Check\n";
    
    bool areCompatable;
    getData(name1, name2, age1, age2, pet1, pet2);
    if(calculateResults(name1, name2, age1, age2, pet1, pet2)){
        cout << "***** RESULTS *****\n" << name1 << " and " << name2 << " are compatible to be roommates!\n";
    }else{
        cout << "***** RESULTS *****\n" << name1 << " and " << name2 << " are not compatible to be roommates.\n";
    }
    return 0;
}
