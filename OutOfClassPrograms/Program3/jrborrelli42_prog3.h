/*
    File Name:  jrborrelli42_prog3.h
    Author:     Joey R. Borrelli
    Date:       11/1/2023
    Purpose:    This is my header file which keeps all of my libary imports, constants, and function prototypes.
*/
#ifndef PROG3_H
#define PROG3_H

#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;

const double COST_PER_OOMPA = 7.5;
const string LINE = "---------------------------------------------------------------------------------------------";

// Function prototypes
void addCandy(int &numCandies, int candyType[], string candyFlavor[], float costMaterials[], int numOompas[], float askingPrice[]);

void calculateTotals(int candyTable, int totalCandies, int candyType[], string candyFlavor[], float costMaterials[], int numOompas[], float askingPrice[]);

float calculatePrice(float costMaterials, int numOompasReq4Candy);

void calculateProfit(int candyTable, int totalCandies, int candyType[], float costMaterials[], float askingPrice[]);

float getMaxPrice(int totalCandies, float askingPrice[], int &mostExpensiveCandyIDX);

#endif