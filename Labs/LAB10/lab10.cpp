/*
    Filename:   lab10.cpp
    Author:     Joey Borrelli
    Date:       11/16/23
    Purpose:    chef
*/

#include <iostream>
#include <limits>

using namespace std;

struct PastryCategory{
    string catName;
    int numAwards;
};

struct Chef{
    string name;
    string homeTown;
    int numCategories;
};

int main(){
    cout << "\n\n*********************************\n";
    cout << "How many chefs are competing in this competition?: ";
    int numChefs;
    cin >> numChefs;

    Chef* arrayOfChefs = new Chef[numChefs]; 
    // array of chef objects

    PastryCategory** awardsArray = new PastryCategory*[numChefs]; 
    // array of pointers to pastry category objects

    // iterate through each chef
    for(int i = 0; i < numChefs; i++){
        cout << "\n\n Chef " << i + 1 << ":\n";
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, arrayOfChefs[i].name);
        cout << "Enter hometown: ";
        cin.ignore();
        getline(cin, arrayOfChefs[i].homeTown);
        cout << "Enter the number of categories they've won awards with: ";
        cin >> arrayOfChefs[i].numCategories;
        for(int j = 0; i < arrayOfChefs[i].numCategories; j++){
            awardsArray[i] = new PastryCategory[arrayOfChefs[i].numCategories];
            cout << "\nEnter the category name: ";
            cin.ignore();
            getline(cin, awardsArray[i][i].catName);
            cout << "Enter the number of awards: ";
            cin >> awardsArray[i][i].numAwards;
        }
    }

    // create variables for the chef with the most awards 
    int totalAwards = 0;
    int chefWithMostAwards;
    
    // iterate through each chef to calculate total awards earned
    for(int i = 0; i < numChefs; i++){
        // variable for each individual chef's awards
        int totalChefAwards = 0;
        
        // iterate through each category
        for(int j = 0; j < arrayOfChefs[j].numCategories; j++){
            // add each award in category
            totalChefAwards += awardsArray[i][j].numAwards;
        }
        
        // output num awards for each chef
        cout << "\nChef " << i + 1 << " total awards: " << totalChefAwards;
        
        // grab our variables for the chef with the most awards
        if(totalChefAwards > totalAwards){
            totalAwards = totalChefAwards;
            chefWithMostAwards = i;
        }
    }

    // print out the chef with the most award's categories 
    cout << "\n Chef " << chefWithMostAwards << ":\n";

    // iterate through categories to print out the numbers in each category
    for(int i = 0; i < arrayOfChefs[chefWithMostAwards].numCategories; i++){
        cout << "Num of Awards in Category " << awardsArray[chefWithMostAwards][i].catName << ": " << awardsArray[chefWithMostAwards][i].numAwards << endl;
    }

    // DELETE
    // loop through chefs
    for(int i = 0; i < numChefs; i++){
        // loop through categories
        for(int j = 0; j < arrayOfChefs[j].numCategories; j++){
            delete[] awardsArray[i]; 
        }
        delete[] awardsArray;
    }
    delete[] arrayOfChefs;
}