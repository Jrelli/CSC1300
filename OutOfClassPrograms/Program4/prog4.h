/*
    File Name:  prog4.h
    Author:     Joey R. Borrelli
    Date:       11/1/2023
    Purpose:    This is my header file which keeps all of my libary imports, constants, and function prototypes.
*/
#ifndef PROG4_H
#define PROG4_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

struct Cost{
    double hoursToRepair;
    double costPerHourRepair;
    double costOfParts;
    double costOfSupplies;
};

struct Vehicles{
    string vehicleName;
    string vehicleDescription;
    bool hasWeapons;
    Cost vehicleCosts;
};

int enterVehicle(int, Vehicles[]);
int deleteVehicle(int, Vehicles[]);
void printVehicles(int, Vehicles[]);
void printStatistics(int, Vehicles[]);
void saveVehiclesToFile(int, Vehicles[]);
float convertToFloat(string);
bool moveArrayElements(int, string, Vehicles[]);

#endif