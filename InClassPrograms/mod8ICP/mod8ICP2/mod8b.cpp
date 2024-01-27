#include<iostream>
using namespace std;

const int NUM_ITEMS = 10;

int findHighest(double[]);
int findLowest(double[]);
double findAverage(double[]);

int main(){
    string names[NUM_ITEMS];
    string tempString;
    double prices[NUM_ITEMS];

    cout << "\n\nTell me 10 useful things and their price:\n";

    for(int i = 1; i <= NUM_ITEMS; i++){
        cout << "USEFUL THING " << i << ": ";
        getline(cin, names[i - 1]);
        cout << "PRICE FOR THING " << i << ": ";
        getline(cin, tempString);
        prices[i - 1] = stod(tempString);
    }

    cout << "\nYour list of useful items include: \n";
    for(int i = 0; i < 10; i++){
        cout << names[i] << ", $" << prices[i] << endl;
    }

    cout << "\n\n****RESULTS****\n";
    cout << "HIGHEST PRICE: " + names[findHighest(prices)] + " with price $" << prices[findHighest(prices)] << endl;
    cout << "LOWEST PRICE: " + names[findLowest(prices)] + " with price $" << prices[findLowest(prices)] << endl;
    cout << "AVERAGE PRICE: $" << findAverage(prices) << endl << endl;
    return 0;
}

int findHighest(double arr[]){
    int largestNum = 0;
    int idx;
    for(int i = 0; i < NUM_ITEMS; i++){
        if(arr[i] > largestNum){
            largestNum = arr[i];
            idx = i;
        }
    }
    return(idx);
}

int findLowest(double arr[]){
    int smallestNum = arr[0];
    int idx;
    for(int i = 0; i < NUM_ITEMS; i++){
        if(arr[i] < smallestNum){
            smallestNum = arr[i];
            idx = i;
        }
    }
    return(idx);
}

double findAverage(double arr[]){
    double total = 0;
    for(int i = 0; i < NUM_ITEMS; i++){
        total += arr[i];
    }
    return(total / NUM_ITEMS);
}