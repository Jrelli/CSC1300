#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    string favColor = "blue";
    cout << "My favorite color is " << endl;
    cout << setw(12) << favColor + "!";
    return(0);
}