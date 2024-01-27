/*
    File Name:  jrborrelli42_program2.cpp
    Author:     Joey R. Borrelli
    Date:       9/22/2023
    Purpose:    analyze dinosaur files or something idk
*/
#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

// function prototypes
int carnOrHerb(string);
bool searchCarnivore(string);
bool searchHerbivore(string);
void printDino(ofstream&, ifstream&, string, int, int&);
bool overTenGrand(string);

int main(){
    // file objects
    ofstream herbFile, carnFile, otherFile;
    ifstream directoryFile;
    
    // holds our total numbers
    int numDinos = 0, numCarnivores = 0, numHerbivores = 0, numFatDinos = 0, numSaurus = 0, numNotDinos = 0;
    string tempString; // holds output from file
    string fileName; // holds users file name
    
    // If the file name was invalid, and the file wasn't opened, it will continue to ask for a new file name.
    while(!directoryFile.is_open()){
        // Read in the filename of the data from the user.
        cout << "Dinosaur Directory File Name (dinoDirectory.txt): ";
        cin >> fileName;
        cout << endl;

        // Open the file
        directoryFile.open(fileName);
    }

    // loops through the file.
    while(getline(directoryFile, tempString, '#')) {
        // if the tempstring has "saurus" in it, then
        if(tempString.find("saurus") != string::npos){
            numSaurus++;
        }
        
        // carnivore or herbivore
        int carnOrHerbResult = carnOrHerb(tempString);
        if (carnOrHerbResult == 1){
            numCarnivores++;
            numDinos++;
            carnFile.open("carnOutFile.txt", ios::app);
            printDino(carnFile, directoryFile, tempString, numCarnivores, numFatDinos);
            carnFile.close();
        }else if(carnOrHerbResult == 2){
            numHerbivores++;
            numDinos++;
            herbFile.open("herbOutFile.txt", ios::app);
            printDino(herbFile, directoryFile, tempString, numHerbivores, numFatDinos);
            herbFile.close();
        }else{
            numNotDinos++;
            otherFile.open("otherOutFile.txt", ios::app);
            printDino(otherFile, directoryFile, tempString, numNotDinos, numFatDinos);
            otherFile.close();
        }
    }

    directoryFile.close();

    cout << "\n--------------------------------------------------\n";
    cout << right << setw(30) << "TOTAL DINOS: " << numDinos << endl;
    cout << right << setw(30) << "TOTAL CARNIVORE DINOS: " << numCarnivores << endl;
    cout << right << setw(30) << "TOTAL HERBIVORE DINOS: " << numHerbivores << endl;
    cout << right << setw(30) << "DINOS OVER 10,000 LBS: " << numFatDinos << endl;
    cout << right << setw(30) << "DINO NAMES END IN 'SAURUS': " << numSaurus << endl;
    cout << right << setw(30) << "ANIMALS NOT DINOS: " << numNotDinos << endl;
    cout << "--------------------------------------------------\n";

    return 0;
}

/*
This function will return a Boolean value, 
indicating if the animal is a carnivore (true) or not (false)
*/
bool searchCarnivore(string name){
    ifstream carnFile;
    string tempString;
    carnFile.open("carnivores.txt");
    while(getline(carnFile, tempString, '#')){
        if(tempString == name){
            carnFile.close();
            return(true);
        }
    }
    carnFile.close();
    return(false);
}

/*
This function will return a Boolean value, 
indicating if the animal is a herbivore (true) or not (false)
*/
bool searchHerbivore(string name){
    ifstream herbFile;
    string tempString;
    herbFile.open("herbivores.txt");
    while(getline(herbFile, tempString, '#')){
        if(tempString == name){
            herbFile.close();
            return(true);
        }
    }
    herbFile.close();
    return(false);
}

/*
This function will return an integeter indicating the
type of dinosaur that has the name entered.
*/
int carnOrHerb(string name){
    if(searchCarnivore(name)){
        return(1);
    }else{
        if(searchHerbivore(name)){
            return(2);
        }else{
            return(-1);
        }
    }
}

/*
This function returns if the weight is over 10,000lbs.
*/
bool overTenGrand(string weight){
    string maxWeight;
    int beginIDX;
    int endIDX;
    
    // if it's not a range of weights
    if(weight.find("to") == string::npos){
        beginIDX = 0;
        endIDX = weight.find("lbs") - 1;
    // if it is a range of weights
    }else{
        // finds begining and ending indexes of our max weight
        beginIDX = weight.find("to") + 3;

        endIDX = weight.find("lbs") - 2;
    }
    
    // sets maxWeight to just the biggest number/removes lowest and lbs
    for(int i = beginIDX; i <= endIDX; i++){
        maxWeight += weight[i];
    }

    // removes comma from maxWeight
    int index = maxWeight.find(',');
    while (index != string::npos) {
        maxWeight.erase(index, 1);
        index = maxWeight.find(',', index);
    }

    // converts to int and returns if greater than 10,000
    return(stoi(maxWeight) > 10000);
}

/*
This function is responsible for reading in the rest of the data about 
the animal from the input file, checking to see if the dinosaur is over
10,000 lbs, and printing the data in an easy-to-read format to the 
correct output file.
*/
void printDino(ofstream& typeDinoF, ifstream& dirF, string name, int typeAcc, int& weightAcc){
    string height, mass, food, description;
    if(carnOrHerb(name) == 1){
        cout << name + " is being printed to the CARNIVORE file!\n";
    }else if(carnOrHerb(name) == 2){
        cout << name + " is being printed to the HERBIVORE file!\n";
    }else{
        cout << name + " is being printed to the OTHER file!\n";
    }
    typeDinoF << "DINOSAUR NAME: " << name << endl;
    getline(dirF, height, '#');
    typeDinoF << "HEIGHT/LENGTH: " << height << endl;
    getline(dirF, mass, '#');
    if(overTenGrand(mass)){
        weightAcc++;
    }
    typeDinoF << "MASS:     " << mass << endl;
    getline(dirF, food, '#');
    typeDinoF << "EATS:     " << food << endl;
    getline(dirF, description, '#');
    typeDinoF << "DESCRIPTION;   " << description << endl << endl;
}