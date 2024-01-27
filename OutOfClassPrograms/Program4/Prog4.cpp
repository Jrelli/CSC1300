#include "prog4.h"

int main(){
    Vehicles vehicleArray[100];
    int numberOfVehicles = 0;
    bool keepRunning = true;
    int userMenuInput;

    // While the user wants to keep the program running
    while(keepRunning){
        do{
            // Print out menu options
            cout << "\nWhat would you like to do?\n\t1.\tEnter some vehicles.\n\t2.\tDelete a vehicle.\n\t3.\tPrint vehicles.\n\t4.\tPrint statistics on vehicle cost.\n\t5\tEnd program.\n\tEnter 1, 2, 3, 4, or 5.\nCHOICE: ";
            cin >> userMenuInput;
            cout << "\n\n";
        // check input
        }while(userMenuInput < 1 || userMenuInput > 5);
        
        // run proper function based on user input
        switch (userMenuInput){
            case 1:
                numberOfVehicles = enterVehicle(numberOfVehicles, vehicleArray);
                break;
            case 2:
                numberOfVehicles = deleteVehicle(numberOfVehicles, vehicleArray);
                break;
            case 3:
                printVehicles(numberOfVehicles, vehicleArray);
                break;
            case 4:
                printStatistics(numberOfVehicles, vehicleArray);
                break;
            case 5:
            // fall through to end program
            default:
                keepRunning = false;

                do{
                    // ask user if we should save vehicles to file.
                    cout << "Do you wish to save your vehicles to a file?\nEnter (1 for yes or 2 for no): ";
                    cin >> userMenuInput;
                    cout << "\n";
                // validate input
                }while(userMenuInput < 1 || userMenuInput > 2);
                
                // save vehicles to file 
                if(userMenuInput == 1){
                    saveVehiclesToFile(numberOfVehicles, vehicleArray);
                }

                cout << "\nGoodbye!\n";
                break;
        }
    }
    return 0;
}