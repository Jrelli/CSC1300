/*
    Title: lab2b.cpp
    Author: Joey and Shane
    Date: August 31, 2023
    Purpose:    Display the approx # of customers in the survey who purchase one or more
                energy drinks per week and the # of customers who prefer citrus-flavored
                energy drinks.
*/
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    const int numSurveyed = 16500;
    const double percentOneOrMore = 0.15;
    const double percentPreferCitrus = 0.58;
    
    double numWhoPreferOneOrMore = (numSurveyed * percentOneOrMore);
    double numWhoPreferOneOrMoreAndCitrus = (numWhoPreferOneOrMore * percentPreferCitrus);
    cout << "\nNum of people who drink more than one a week: " << numWhoPreferOneOrMore;
    cout << "\nNum of people who drink more than one a week and prefer Citrus flavored: " << fixed << setprecision(0) << numWhoPreferOneOrMoreAndCitrus;

    return 0;
}