/*
    Title:      lab5.cpp
    Author:     Joey Borrelli
    Date:       9/28/2023
    Purpose:    A program designed to calculate total costs of tables orders at a restaurant and output them to a text file.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){
	// object to output to a file.
	ofstream outputFile;

	// constants to hold the cost of different items
	const double PIZZA_COST = 20.00;
	const double PIZZA_TOPPING_COST = 2.00;
	const double BURGER_COST = 15.00;
	const double SANDWICH_COST = 10.00;

	// constants to hold my dicounts for the first time you buy an item
	const double FIRST_PIZZA_DISCOUNT = 0.2;
	const double FIRST_BURGER_DISCOUNT = 0.15;
	const double FIRST_SANDWICH_DISCOUNT = 0.1;
	
	// int to hold the choice of the user when giving input
	int userChoice;

	// booleans that hold if its the first time getting an item, used to apply discount
	bool pastFirstPizza = false;
	bool pastFirstBurger = false;
	bool pastFirstSandwich = false;
	
	// ints to hold total number of items
	int numPizzas;
	int numToppings;
	int numBurgers;
	int numSandwiches;

	// double to hold my total cost of all items
	double totalCost = 0;

	// boolean to know if my program should re-run
	bool endProgram = false;

	// opens or creates restaurant.txt
	outputFile.open("restaurant.txt");
	
	// loops as long as they still want to order; based on endProgram boolean
	do{
		// initialize or reset my item counters to zero for every iteration of the loop
		numPizzas = 0;
		numToppings = 0;
		numBurgers = 0;
		numSandwiches = 0;

		// Get user input for figure out which item they want to order
		cout << "\n\nWelcome to The Cauldron Restaurant!\n\n";
		cout << "Please choose one of the following options:\n\nPIZZA(1)\n\nBURGER(2)\n\nSANDWICH(3)\n\nDone Ordering(4)\n\nENTER: ";
		cin >> userChoice;
		// validate input
		while(userChoice < 1 || userChoice > 4){
			cout << "\n\nOops! That is not a valid choice. Choose 1-4.\n\nENTER: ";
			cin >> userChoice;
		}

		// switch case to choose between different items
		switch (userChoice){
			case 1:
				// gets user input on how many pizzas they want to order
				cout << "\n\nHow many pizzas do you want to order?\nENTER: ";
				cin >> numPizzas;
				// validate input
				while(numPizzas < 1){
					cout << "\nYou need to order at least 1 pizza.\nENTER: ";
					cin >> numPizzas;
				}
				
				// loops for every pizza they want to ask how many toppings on each.
				for(int i = 0; i < numPizzas; i++){
					cout << "\nFor pizza " << (i + 1) << ", how many toppings? ";
					cin >> numToppings;
					// validate input
					while(numToppings < 0){
						cout << "\nYou can't have negative toppings, enter at least 0.\nENTER: ";
						cin >> numToppings;
					}
					
					// outputs cost, adds total, decides if it needs to apply dicount if we have already ordered pizza before.
					if(!pastFirstPizza){
						cout << setprecision(2) << fixed << "\nThis pizza costs $" << ((PIZZA_COST + (PIZZA_TOPPING_COST * numToppings)) - ((PIZZA_COST + (PIZZA_TOPPING_COST * numToppings))) * FIRST_PIZZA_DISCOUNT);
						totalCost += ((PIZZA_COST + (PIZZA_TOPPING_COST * numToppings)) - ((PIZZA_COST + (PIZZA_TOPPING_COST * numToppings))) * FIRST_PIZZA_DISCOUNT);
					}else{
						cout << setprecision(2) << fixed << "\nThis pizza costs $" << (PIZZA_COST + (PIZZA_TOPPING_COST * numToppings));
						totalCost += (PIZZA_COST + (PIZZA_TOPPING_COST * numToppings));
					}
					
					// set pastFirstPizza to true, because 1 pizza at least has now been ordered
					pastFirstPizza = true;
				}
				
				// ouput the number of pizzas ordered and the total.
				cout << endl << numPizzas << " pizzas were added and the total is now $" << totalCost;
				
				// output text to text file
				outputFile << numPizzas << " pizzas were added and the total is now $" << setprecision(2) << fixed << totalCost << endl;
				
				break;
			case 2:
				// gets user input on how many burgers they want to order
				cout << "\n\nHow many burgers do you want to order?\nENTER: ";
				cin >> numBurgers;
				// validate input
				while(numBurgers < 1){
					cout << "\nYou need to order at least 1 burger.\nENTER: ";
					cin >> numBurgers;
				}
				
				// adds total, decides if it needs to apply dicount if we have already ordered a burger before.
				if(!pastFirstBurger){
					totalCost += ((BURGER_COST - (BURGER_COST * FIRST_BURGER_DISCOUNT)) + ((numBurgers - 1) * BURGER_COST));
				}else{
					totalCost += (numBurgers * BURGER_COST);
				}
				
				// sets pastFirstBurger to true, because 1 burger at least has now been ordered
				pastFirstBurger = true;
				
				// output the number of burgers ordered and the total.
				cout << endl << numBurgers << " burgers were added and the total is now $" << setprecision(2) << fixed << totalCost;
				
				// output text to text file
				outputFile << numBurgers << " burgers were added and the total is now $" << setprecision(2) << fixed << totalCost << endl;
				
				break;
			case 3:
				// gets user input on how many sandwiches they want to order
				cout << "\n\nHow many sandwiches do you want to order?\nENTER: ";
				cin >> numSandwiches;
				// validate input
				while(numSandwiches < 1){
					cout << "\nYou need to order at least 1 Sandwiches.\nENTER: ";
					cin >> numSandwiches;
				}
				
				// adds total, decides if it needs to apply dicount if we have already ordered a sandwich before.				
				if(!pastFirstSandwich){
					totalCost += ((SANDWICH_COST - (SANDWICH_COST * FIRST_SANDWICH_DISCOUNT)) + ((numSandwiches - 1) * SANDWICH_COST));
				}else{
					totalCost += (numSandwiches * SANDWICH_COST);
				}
				
				// sets pastFirstSandwich to true, because 1 sandwich at least has now been ordered
				pastFirstSandwich = true;
				
				// output the number of sandwichess ordered and the total.
				cout << endl << numSandwiches << " sandwiches were added and the total is now $" << setprecision(2) << fixed << totalCost;
				
				// output text to text file
				outputFile << numSandwiches << " sandwiches were added and the total is now $" << setprecision(2) << fixed << totalCost << endl;

				break;
			
			// falls to default and ends the program.
			case 4:
			default:
				endProgram = true;
				break;
		}
	}while(!endProgram);

	// outputs the final total.
	cout << "\n\nThe total for your order is $" << setprecision(2) << fixed << totalCost;
	
	// outputs the final total to the text file.
	outputFile << "\n\nThe total for your order is $" << setprecision(2) << fixed << totalCost;

	// close the file
	outputFile.close();
	
	return 0;
}