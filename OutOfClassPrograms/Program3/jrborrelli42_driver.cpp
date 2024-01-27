/*
    File Name:  jrborrelli42_driver.cpp
    Author:     Joey R. Borrelli
    Date:       11/1/2023
    Purpose:    The purpose of this program is to help Willy Wonka keep track of the prices of his candies.
*/
#include "jrborrelli42_prog3.h"

int main(){
    int numItems                    = 0;        //integer that holds the number of items.
    const int maxNumItems           = 50;       //integer that holds the max number of items.
    
    int candyType[maxNumItems]      = {0};      //integer array with 50 elements that holds either a 1, 2 or 3 to represent what the candy type is (1= Wonka Bar, 2= Everlasting Gobstoppers, 3= Hair Toffee)
    string candyFlavor[maxNumItems] = {""};       //an array of strings with 50 elements that holds an interesting flavor for each candy item.
    float costMaterials[maxNumItems]= {0.0};    //float array with 50 elements that holds the cost of the materials to make the candy.
    int numOompas[maxNumItems]      = {0};      //int array with 50 elements that holds the number of Oompa Loompas it took to create the piece of candy.
    float askingPrice[maxNumItems]  = {0.0};    //float array with 50 elements that holds the asking price of the candy.
    
    bool endProgram                 = false;    //boolean holds if we want the program to end.
    int userInput;                              //int holds the users input

    int maxIndex                    = 0;
    float maxPrice                  = 0.0;

    const string IDX_DEF[3]         = {"Wonka Bar", "Everlasting Gobstopper", "Hair Toffee"};

    cout << endl << endl;
    cout << "**************************************************\n";
    cout << "*  WELCOME TO WILLY WONKA'S CHOCOLATE FACTORY!!  *\n";
    cout << "**************************************************";

    // keep running program unless user wants to quit
    do{
        cout << "\n\nWonka's candy management program:\n\t1.\tAdd a piece of candy to inventory\n\t2.\tCalculate totals for candy\n\t3.\tCalculate profits for candy\n\t4.\tPrint candy with max price\n\t5.\tQuit the program\n\nChoose 1-5: ";
        cin >> userInput;

        // validate input
        while(userInput < 0 || userInput > 6){
            cout << "\nYou must enter 1-5!\nChoose again: ";
            cin >> userInput;
        }

        switch(userInput){
            case 1:
                addCandy(numItems, candyType, candyFlavor, costMaterials, numOompas, askingPrice);
                break;
            case 2:
                cout << "\n\nChoose what candy you want to get the total for:\n\t1.\tWonka Bars\n\t2.\tEverlasting Gobstoppers\n\t3.\tHair Toffees\n\t4.\tAll candy\n\nChoose 1-4: ";
                cin >> userInput;
                //validate input
                while(userInput < 0 || userInput >4){
                    cout << "\nYou must enter 1-4!\nChoose again: ";
                    cin >> userInput;
                }
                calculateTotals(userInput, numItems, candyType, candyFlavor, costMaterials, numOompas, askingPrice);
                break;
            case 3:
                cout << "\n\nChoose what candy you want to get the profit for:\n\t1.\tWonka Bars\n\t2.\tEverlasting Gobstoppers\n\t3.\tHair Toffees\n\t4.\tAll candy\n\nChoose 1-4: ";
                cin >> userInput;
                //validate input
                while(userInput < 0 || userInput >4){
                    cout << "\nYou must enter 1-4!\nChoose again: ";
                    cin >> userInput;
                }
                calculateProfit(userInput, numItems, candyType, costMaterials, askingPrice);
                break;
            case 4:
                maxPrice = getMaxPrice(numItems, askingPrice, maxIndex);
                //print the flavor, type and asking price of the most expensive candy
                cout << "\nCandy with the highest price is the " << candyFlavor[maxIndex] << " flavored " << IDX_DEF[candyType[maxIndex] - 1] << " for " << setprecision(2) << maxPrice << endl; 
                break;
            case 5:
                cout << "\n\tGOODBYE!!\n\n";
                endProgram = true;
                break;
            default:
                cout << "\n\nERROR: DEFAULT CASE RAN- jrborrelli_driver.cpp Line(49)\n\n";
            break;
        }
    }while(!endProgram);

    return(0);
}