#include <iostream>
using namespace std;
int main(){
    string favColor;
    int favNum;
    
    cout << "What is your favorite color? ";
    cin >> favColor;
    cout << "What is your favorite number? ";
    cin >> favNum;
    cout << "\nYour favorite color is " + favColor + " and favorite number is " << favNum << endl;
    return 0;
}