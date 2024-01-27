#include "prog4.h"

int enterVehicle(int numCurrentVehicles, Vehicles vehiclesArray[]){
    int userMenuInput;
    string fileName;
    ifstream inputFromFile;
    string tempString; // holds string when parsing through text file

    // checks if we are over capacity, false case if over
    if(numCurrentVehicles < 100){
        do{
            // functions main menu
            cout << "What do you want to do?\n\t1. Load my Vehicles from a file.\n\t2. Enter one Vehicle manually.\n\tChoose 1 or 2.\nCHOICE: ";
            cin >> userMenuInput;
            cout << "\n";
        // validate input
        }while(userMenuInput < 1 || userMenuInput > 2);
        
        switch (userMenuInput){
            case 1:
                // get the name of the file from the user
                cout << "What is the came of the file with your list of vehicles? (ex: filename.txt)\nFILENAME:  ";
                cin >> fileName;
                cout << "\n";

                // open the file
                inputFromFile.open(fileName);

                // if file exists, false case is if it does exist
                if(!inputFromFile.is_open()){
                    cout << "\nINVALID FILE NAME\n";
                }else{
                    // this integer is used for incrimination and keeping track of what variable im on.
                    int i = 0;
                    while(getline(inputFromFile, tempString, '#')){
                        i++;
                        switch(i){
                            case 1: //name
                                vehiclesArray[numCurrentVehicles].vehicleName = tempString;
                                break;
                            case 2: // description
                                vehiclesArray[numCurrentVehicles].vehicleDescription = tempString;
                                break;
                            case 3: // hasWeapons
                                vehiclesArray[numCurrentVehicles].hasWeapons = (tempString == "1");
                                break;
                            case 4: // hoursToRepair
                                vehiclesArray[numCurrentVehicles].vehicleCosts.hoursToRepair = convertToFloat(tempString);
                                break;
                            case 5: // costPerHourToRepair
                                vehiclesArray[numCurrentVehicles].vehicleCosts.costPerHourRepair = convertToFloat(tempString);
                                break;
                            case 6: // costForParts
                                vehiclesArray[numCurrentVehicles].vehicleCosts.costOfParts = convertToFloat(tempString);
                                break;
                            case 7: // costForSupplies
                                vehiclesArray[numCurrentVehicles].vehicleCosts.costOfSupplies = convertToFloat(tempString);
                                i = 0;
                                numCurrentVehicles++;
                                // first vehicle completely entered
                                break;
                            default: 
                                break;
                        }
                    }
                    cout << "\nAll vehicles from " + fileName + " have been added to the program.\n";
                    // close the file
                    inputFromFile.close();
                }
                break;
            case 2:
            //fall through
            default:
                bool addAnotherVehicle;
                // loops through array for user to manually enter in values
                do{
                    cout << "\nNAME: ";
                    cin.ignore();
                    getline(cin, vehiclesArray[numCurrentVehicles].vehicleName);
                    cout << "\n\n";

                    cout << "\nDESCRIPTION: ";
                    cin.ignore();
                    getline(cin, vehiclesArray[numCurrentVehicles].vehicleDescription);
                    cout << "\n\n";

                    cout << "\nDOES THIS VEHICLE HAVE WEAPONS? (y or n): ";
                    cin >> tempString;
                    vehiclesArray[numCurrentVehicles].hasWeapons = (tempString == "y");
                    cout << "\n\n";

                    cout << "How many hours do you spend repairing the " + vehiclesArray[numCurrentVehicles].vehicleName + "?\nNUM HOURS: ";
                    cin >> vehiclesArray[numCurrentVehicles].vehicleCosts.hoursToRepair;
                    cout << "\n\n";

                    cout << "What is the cost per hour for repairing for the " + vehiclesArray[numCurrentVehicles].vehicleName + "?\nCOST PER HOUR: $";
                    cin >> vehiclesArray[numCurrentVehicles].vehicleCosts.costPerHourRepair;
                    cout << "\n\n";

                    cout << "How much money do you spend on parts for the " + vehiclesArray[numCurrentVehicles].vehicleName + "?\nPARTS COST: $";
                    cin >> vehiclesArray[numCurrentVehicles].vehicleCosts.costOfParts;
                    cout << "\n\n";

                    cout << "How much money do you spend on supplies for the " + vehiclesArray[numCurrentVehicles].vehicleName + "?\nSUPPLIES COST: $";
                    cin >> vehiclesArray[numCurrentVehicles].vehicleCosts.costOfSupplies;
                    cout << "\n\n";

                    // If we want to run again
                    numCurrentVehicles++;
                    cout << "The " + vehiclesArray[numCurrentVehicles].vehicleName + " has been added.\n\nWant to add more vehicles? (y or n) ";
                    cin >> tempString;
                    addAnotherVehicle = (tempString == "y");
                // while the user wants to add another
                }while(addAnotherVehicle);
                break;
        }
    }else{
        cout << "You garage is already full!\nYou cannot add anymore vehicles.\n";
    }
    return(numCurrentVehicles);
}

int deleteVehicle(int numCurrentVehicles, Vehicles vehiclesArray[]){
    string userInput;

    cout << "\nThe following is a list of all the vehicles you take care of:\n";
    
    //iterate through array, printing out all names
    for(int i = 0; i < numCurrentVehicles; i++){
        cout << vehiclesArray[i].vehicleName << "\n";
    }

    // get user's desired vehicle to be deleted
    cout << "\nWhat vehicle do you wish to remove?\nVEHICLE NAME: ";
    cin.ignore();
    getline(cin, userInput);

    // delete the item from the array and decrement var
    if(moveArrayElements(numCurrentVehicles, userInput, vehiclesArray)){
        numCurrentVehicles--;
        cout << "\nYou have removed the " + userInput + "\n\n";
    }else{
        cout << "\nSorry, a vehicle by the name " + userInput + " could not be found.\n";
    }

    return(numCurrentVehicles);
}

void printVehicles(int numCurrentVehicles, Vehicles vehiclesArray[]){
    int userInput;
    string word, line; // used for text wrapping
    string userFileName;

    do{
        cout << "\nWhat would you like to do?\n\t1. Print vehicles to the screen.\n\t2. Print vehicles to a file.\n\tChoose 1 or 2.\nCHOICE:  ";
        cin >> userInput;
    }while(userInput > 2 || userInput < 1);
    
    // choose to print or output to text file
    switch (userInput){
        case 1:// print
            // iterate through array
            for(int i = 0; i < numCurrentVehicles; i++){
                cout << "\n----------------------------------------------------------------------\nVEHICLE " << i << ":\nName:           " << vehiclesArray[i].vehicleName + "\nDescription:\n";
                
                // Text wrapping the description
                istringstream iss(vehiclesArray[i].vehicleDescription);
                // while there are more words from iss to be streamed into word
                while(iss >> word){
                    // if our line isn't long enough yet
                    if((line.length() + word.length() + 1) <= 60){
                        // adds a space if we don't have one
                        if(!line.empty()){
                            line += " ";
                        }
                        // add more words to the line
                        line += word;
                    }else{
                        // print out line
                        cout << "    " << line << "\n";
                        // sets our line to our next word
                        line = word;
                    }
                }
                // outputs final line that isn't full length
                cout << "    " << line << "\n\nHas weapons?";

                // outputs if weapons
                if(vehiclesArray[i].hasWeapons){
                    cout << setw(8) << "yes\n";
                }else{
                    cout << setw(8) << "no\n";
                }

                cout << "Number of Hours to repair the Vehicle: " << fixed << setprecision(2) << vehiclesArray[i].vehicleCosts.hoursToRepair << "\nCost Per Hour:  $ " << vehiclesArray[i].vehicleCosts.costPerHourRepair << "\nCost for Parts: $ " << vehiclesArray[i].vehicleCosts.costOfParts << "\nSupplies Cost:  $ " << vehiclesArray[i].vehicleCosts.costOfSupplies << "\n\n";
            }
            break;
        case 2:// text file
        // fall through
        default:// text file
            // get name
            cout << "\nWhat is the name of your file you wish to write to?\nFILENAME: ";
            cin.ignore();
            getline(cin, userFileName);

            // open file
            ofstream outFile(userFileName);

            // iterate through array
            for(int i = 0; i < numCurrentVehicles; i++){
                outFile << "\n----------------------------------------------------------------------\nVEHICLE " << i << ":\nName:           " << vehiclesArray[i].vehicleName + "\nDescription:\n";
                
                // Text wrapping the description
                istringstream iss(vehiclesArray[i].vehicleDescription);
                // while there are more words from iss to be streamed into word
                while(iss >> word){
                    // if our line isn't long enough yet
                    if((line.length() + word.length() + 1) <= 60){
                        // adds a space if we don't have one
                        if(!line.empty()){
                            line += " ";
                        }
                        // add more words to the line
                        line += word;
                    }else{
                        // print out line
                        outFile << "    " << line << "\n";
                        // sets our line to our next word
                        line = word;
                    }
                }
                // outputs final line that isn't full length
                outFile << "    " << line << "\n\nHas weapons?";

                // outputs if weapons
                if(vehiclesArray[i].hasWeapons){
                    outFile << setw(8) << "yes\n";
                }else{
                    outFile << setw(8) << "no\n";
                }

                outFile << "Number of Hours to repair the Vehicle: " << fixed << setprecision(2) << vehiclesArray[i].vehicleCosts.hoursToRepair << "\nCost Per Hour:  $ " << vehiclesArray[i].vehicleCosts.costPerHourRepair << "\nCost for Parts: $ " << vehiclesArray[i].vehicleCosts.costOfParts << "\nSupplies Cost:  $ " << vehiclesArray[i].vehicleCosts.costOfSupplies << "\n\n";
            }
            break;
    }

}

void printStatistics(int numCurrentVehicles, Vehicles vehiclesArray[]){
    double cost;
    double totalCost = 0;

    cout << "\nCOST OF EACH VEHICLE:\n\nVEHICLE" << setw(44) << "COST\n";
    // iterate through array
    for(int i = 0; i < numCurrentVehicles; i++){
        cost = (vehiclesArray[i].vehicleCosts.hoursToRepair * vehiclesArray[i].vehicleCosts.costPerHourRepair) + vehiclesArray[i].vehicleCosts.costOfParts + vehiclesArray[i].vehicleCosts.costOfSupplies;
        cout << left << setw(20) << vehiclesArray[i].vehicleName << right << setw(10) << "$" << right << setw(20) << fixed << setprecision(2) << cost << "\n";
        totalCost += cost;
    }

    cout << "\n" << left << setw(20) << "TOTAL COST:" << right << setw(10) << "$" << right << setw(20) << fixed << setprecision(2) << totalCost << "\n";
}

void saveVehiclesToFile(int numCurrentVehicles, Vehicles vehiclesArray[]){
    string userFileName;

    // get file name
    cout << "\nWhat is the name of the file you want to save your vehicles to?\nFILENAME: ";
    cin.ignore();
    getline(cin, userFileName);

    // open file
    ofstream outFile(userFileName);

    // iterate through array
    for(int i = 0; i < numCurrentVehicles; i++){
        outFile << vehiclesArray[i].vehicleName << "#" << vehiclesArray[i].vehicleDescription << "#" << vehiclesArray[i].hasWeapons << "#" << vehiclesArray[i].vehicleCosts.hoursToRepair << "#" << vehiclesArray[i].vehicleCosts.costPerHourRepair << "#" << vehiclesArray[i].vehicleCosts.costOfParts << "#" << vehiclesArray[i].vehicleCosts.costOfSupplies << "#";
    }

    cout << "\nYour vehicles were successfully saved to the " + userFileName + " file.\n";
}

float convertToFloat(string inputString){
    istringstream iss(inputString);
    float convertedFloat;
    if(!(iss >> convertedFloat)){
        convertedFloat = 0;
    }
    return(convertedFloat);
}

bool moveArrayElements(int numCurrentVehicles, string nameOfRMVehicle, Vehicles vehiclesArray[]){
    // holds the index of the vehicle that will be removed
    int vehicleRM_IDX;
    
    // increments on my false case so that I can know if I found a match in the array
    int j = 0;

    // iterate through array to find match and get index
    for(int i = 0; i < numCurrentVehicles; i++){
        if(vehiclesArray[i].vehicleName == nameOfRMVehicle){
            vehicleRM_IDX = i;
        }else{
            j++;
        }
    }


    if(j != (numCurrentVehicles - 1)){
        // No match
        return(false);
    }else{
        // Found a match
        // iterate through array, moving the above vehicle to the bellow vehicle
        for(int i = vehicleRM_IDX; i < numCurrentVehicles - 1; i++){
            vehiclesArray[i].vehicleName = vehiclesArray[i+1].vehicleName;
            vehiclesArray[i].vehicleDescription = vehiclesArray[i+1].vehicleDescription;
            vehiclesArray[i].hasWeapons = vehiclesArray[i+1].hasWeapons;
            vehiclesArray[i].vehicleCosts.hoursToRepair = vehiclesArray[i+1].vehicleCosts.hoursToRepair;
            vehiclesArray[i].vehicleCosts.costPerHourRepair = vehiclesArray[i+1].vehicleCosts.costPerHourRepair;
            vehiclesArray[i].vehicleCosts.costOfSupplies = vehiclesArray[i+1].vehicleCosts.costOfSupplies;
            vehiclesArray[i].vehicleCosts.costOfParts = vehiclesArray[i+1].vehicleCosts.costOfParts;
        }
        //NOTE: how is this changing the array, aren't I only changing the argument of the array
        return(true);
    }


}