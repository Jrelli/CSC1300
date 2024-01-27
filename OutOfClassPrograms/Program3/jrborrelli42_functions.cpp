/*
    File Name:  jrborrelli42_functions.cpp
    Author:     Joey R. Borrelli
    Date:       11/1/2023
    Purpose:    This file holds all of my functions
*/
#include "jrborrelli42_prog3.h"

// adds candy
void addCandy(int &numCandies, int candyType[], string candyFlavor[], float costMaterials[], int numOompas[], float askingPrice[]){
    if(numCandies < 50){
        //inital question
        int userChoice;
        cout << "\nChoose a candy type:\n\t1. Wonka Bar\n\t2. Everlasting Gobstoppers\n\t3. Hair Toffee\n\nEnter choice: ";
        cin >> userChoice;
        //input validation
        while(userChoice < 1 || userChoice > 3){
            cout << "\nYou must enter 1, 2, or 3!\nEnter choice: ";
            cin >> userChoice;
        }
        // put to array
        candyType[numCandies] = userChoice;

        //inital question
        cin.ignore();
        cout << "\nWhat's the flavor of your candy? ";
        // put to array
        getline(cin, candyFlavor[numCandies]);
        //NOTE: input validation?

        //initial question
        cout << "How much did the material cost? ";
        float tempFlt;
        cin >> tempFlt;
        //input validation
        while(tempFlt < 0.0){
            cout << "\nError!! You cannot have a negative cost for the material!\nHow much did the material cost? $";
            cin >> tempFlt;
        }
        //add tempFlt to array
        costMaterials[numCandies] = tempFlt;

        //initial question
        cout << "How many Oompa Loompas did it take to make the candy? ";
        int tempInt;
        cin >> tempInt;
        //input validation
        while(tempInt < 0){
            cout << "\nError!! You cannot have a negative number of Oompa Loompas!\nHow many Oompa Loompas did it take to make the candy? ";
            cin >> tempInt;
        }
        //add tempInt to array
        numOompas[numCandies] = tempInt;

        //call the calculatePrice function to populate the askingPrice array.
        askingPrice[numCandies] = calculatePrice(tempFlt, tempInt);

        cout << "\nA new candy has been added to the inventory!\n";
        //increase number of candies added
        numCandies++;
    }
}

// calculates totals and prints out table
void calculateTotals(int candyTable, int totalCandies, int candyType[], string candyFlavor[], float costMaterials[], int numOompas[], float askingPrice[]){
    cout << "\n\n";
    float totalMatCost = 0.0; // holds total materials
    float totalAskingPriceCost = 0.0; // holds total asking price

    //check which table we want to ouput
    switch (candyTable){
        case 1:
            cout << "Total Wonka bars in Inventory:\n\n";
            cout << right << setw(0) << "TYPE" << setw(33) << "FLAVOR" << setw(10) << "COST" << setw(15) << "NUM-OOMPAS" << setw(16) << "PRICE\n";
            cout << LINE << endl;
            
            //outputs and increments proper vars for each wonka bar
            for(int i = totalCandies - 1; i >= 0; i--){
                if(candyType[i] == 1){
                    cout << right << setw(0) << "Wonka Bar" << setw(28) << candyFlavor[i] << setw(10) << fixed << setprecision(2) << costMaterials[i] << setw(15) << numOompas[i] << setw(15) << setprecision(2) << askingPrice[i] << endl;
                    totalMatCost += costMaterials[i];
                    totalAskingPriceCost += askingPrice[i];
                }
            }
            
            //print totals
            cout << LINE << endl; 
            cout << setw(0) << "\nTOTALS:" << setw(30) << "$" << setw(10) << setprecision(2) << totalMatCost << setw(15) << "$" << setw(15) << totalAskingPriceCost << endl;
            break;
        
        case 2:
            cout << "Total Everlasting Gobstoppers in Inventory:\n\n";
            cout << right << setw(0) << "TYPE" << setw(33) << "FLAVOR" << setw(10) << "COST" << setw(15) << "NUM-OOMPAS" << setw(16) << "PRICE\n";
            cout << LINE << endl;
            
            //outputs and increments proper vars for each EG
            for(int i = totalCandies - 1; i >= 0; i--){
                if(candyType[i] == 2){
                    cout << right << setw(0) << "Everlasting Gobstoppers" << setw(14) << candyFlavor[i] << setw(10) << fixed << setprecision(2) << costMaterials[i] << setw(15) << numOompas[i] << setw(15) << setprecision(2) << askingPrice[i] << endl;                    
                    totalMatCost += costMaterials[i];
                    totalAskingPriceCost += askingPrice[i];
                }            
            }
            
            //print totals
            cout << LINE << endl;
            cout << setw(0) << "\nTOTALS:" << setw(30) << "$" << setw(10) << setprecision(2) << totalMatCost << setw(15) << "$" << setw(15) << totalAskingPriceCost << endl;
            break;
        
        case 3:
            cout << "Total Hair Toffees in Inventory:\n\n";
            cout << right << setw(0) << "TYPE" << setw(33) << "FLAVOR" << setw(10) << "COST" << setw(15) << "NUM-OOMPAS" << setw(16) << "PRICE\n";
            cout << LINE << endl;
            
            //outputs and increments proper vars for each HT
            for(int i = totalCandies - 1; i >= 0; i--){
                if(candyType[i] == 3){
                    cout << right << setw(0) << "Hair Toffees" << setw(25) << candyFlavor[i] << setw(10) << fixed << setprecision(2) << costMaterials[i] << setw(15) << numOompas[i] << setw(15) << setprecision(2) << askingPrice[i] << endl;                    
                    totalMatCost += costMaterials[i];
                    totalAskingPriceCost += askingPrice[i];
                }
            }
            
            //print totals
            cout << LINE << endl;
            cout << setw(0) << "\nTOTALS:" << setw(30) << "$" << setw(10) << setprecision(2) << totalMatCost << setw(15) << "$" << setw(15) << totalAskingPriceCost << endl;
            break;
        
        case 4:
        //fall through
        default:
            cout << "Total Candy in Inventory:\n\n";
            cout << right << setw(0) << "TYPE" << setw(33) << "FLAVOR" << setw(10) << "COST" << setw(15) << "NUM-OOMPAS" << setw(16) << "PRICE\n";
            cout << LINE << endl;
            
            //outputs for each candy
            for(int i = totalCandies - 1; i >= 0; i--){
                switch (candyType[i]){
                    case 1:
                        cout << right << setw(0) << "Wonka Bar" << setw(28) << candyFlavor[i] << setw(10) << fixed << setprecision(2) << costMaterials[i] << setw(15) << numOompas[i] << setw(15) << setprecision(2) << askingPrice[i] << endl;
                        break;
                    case 2:
                        cout << right << setw(0) << "Everlasting Gobstoppers" << setw(14) << candyFlavor[i] << setw(10) << fixed << setprecision(2) << costMaterials[i] << setw(15) << numOompas[i] << setw(15) << setprecision(2) << askingPrice[i] << endl;
                        break;
                    case 3:
                        cout << right << setw(0) << "Hair Toffees" << setw(25) << candyFlavor[i] << setw(10) << fixed << setprecision(2) << costMaterials[i] << setw(15) << numOompas[i] << setw(15) << setprecision(2) << askingPrice[i] << endl;
                        break;
                    default:
                        break;
                }
                // increments proper vars
                totalMatCost += costMaterials[i];
                totalAskingPriceCost += askingPrice[i];
            }
            
            //print totals
            cout << LINE << endl;
            cout << setw(0) << "\nTOTALS:" << setw(30) << "$" << setw(10) << setprecision(2) << totalMatCost << setw(15) << "$" << setw(15) << totalAskingPriceCost << endl;
        break;
    }
}

// returns asking price of a candy
float calculatePrice(float costMaterials, int numOompasReq4Candy){
    return(numOompasReq4Candy * COST_PER_OOMPA + costMaterials);
}

// calculates profits and prints out table
void calculateProfit(int candyTable, int totalCandies, int candyType[], float costMaterials[], float askingPrice[]){
    cout << "\n\n";
    float tempProfit = 0.0; //holds temporary profit
    float totalProfit = 0.0; //holds total profit

    // evaluates whichever type of candy the user wants to do
    switch(candyTable){
        case 1:
            cout << "Total Profits for Wonka bars in Inventory:\n\n";
            cout << "CANDY TYPE" << setw(30) << "PROFIT\n" << LINE;
            // iterates through array, outputs, and increments proper vars for wonka bars
            for(int i = totalCandies - 1; i >= 0; i--){
                if(candyType[i] == 1){
                    tempProfit = askingPrice[i] - costMaterials[i];
                    cout << "\nWonka bars" << right << setw(29) << setprecision(2) << tempProfit;
                    totalProfit += tempProfit;
                }
            }
            cout << endl << LINE << "\n\nTOTAL Profit: " << right << setw(20) << "$" << totalProfit;
            break;
        case 2:
            cout << "Total Profits for Everlasting Gobstoppers in Inventory:\n\n";
            cout << "CANDY TYPE" << setw(30) << "PROFIT\n" << LINE;
            // iterates through array, outputs, and increments proper vars for EG
            for(int i = totalCandies - 1; i >= 0; i--){
                if(candyType[i] == 2){
                    tempProfit = askingPrice[i] - costMaterials[i];
                    cout << "\nEverlasting Gobstoppers" << right << setw(16) << setprecision(2) << tempProfit;
                    totalProfit += tempProfit;
                }
            }
            cout << endl << LINE << "\n\nTOTAL Profit: " << right << setw(20) << "$" << totalProfit;
            break;
        case 3:
            cout << "Total Profits for Hair Toffees in Inventory:\n\n";
            cout << "CANDY TYPE" << setw(30) << "PROFIT\n" << LINE;
            // iterates through array, outputs, and increments proper vars for HT
            for(int i = totalCandies - 1; i >= 0; i--){
                if(candyType[i] == 3){
                    tempProfit = askingPrice[i] - costMaterials[i];
                    cout << "\nHair Toffees" << right << setw(27) << setprecision(2) << tempProfit;
                    totalProfit += tempProfit;
                }
            }
            cout << endl << LINE << "\n\nTOTAL Profit: " << right << setw(20) << "$" << totalProfit;
            break;
        case 4:
        // falls through
        default:
            cout << "Total Profits for all candy in Inventory:\n\n";
            cout << "CANDY TYPE" << setw(30) << "PROFIT\n" << LINE;
            // iterates through array, outputs, and increments proper vars for all types of candy
            for(int i = totalCandies - 1; i >= 0; i--){
                tempProfit = askingPrice[i] - costMaterials[i];
                switch (candyType[i]){
                    case 1:
                        cout << "\nWonka Bar" << right << setw(30) << setprecision(2) << tempProfit;
                        break;
                    case 2:
                        cout << "\nEverlasting Gobstoppers" << right << setw(16) << setprecision(2) << tempProfit;
                        break;
                    case 3:
                    //fall through
                    default:
                        cout << "\nHair Toffee" << right << setw(28) << setprecision(2) << tempProfit;
                        break;
                }
                totalProfit += tempProfit;
            }
            cout << endl << LINE << "\n\nTOTAL Profit: " << right << setw(19) << "$" << totalProfit;
        break;
    }
}

// returns max price
float getMaxPrice(int totalCandies, float askingPrice[], int &mostExpensiveCandyIDX){
    float largestAskingPrice = 0.0; // holds largest asking price
    // iterates through loops
    for(int i = totalCandies - 1; i >= 0; i--){
        // if asking price is larger than our current known largest
        if(askingPrice[i] > largestAskingPrice){
            // set largest and index to proper ones
            largestAskingPrice = askingPrice[i];
            mostExpensiveCandyIDX = i;
        }
    }
    // returns largest price
    return(largestAskingPrice);
}