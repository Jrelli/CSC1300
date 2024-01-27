#include <iostream>

using namespace std;

int main(){
    // create variables and pointers
    int length, width, area;
    int *lengthPtr, *widthPtr;
    lengthPtr = &length;
    widthPtr = &width;

    // get user input and ouput area
    cout << "\n\nPlease input the length of the rectangle.\n";
    cin >> *lengthPtr;
    cout << "\nPlease input the width of the rectangle.\n";
    cin >> *widthPtr;
    cout << "The area is " << (*lengthPtr * *widthPtr) << "\n";

    // output which is greater
    if(*lengthPtr > *widthPtr){
        cout << "The length is greater than the width.\n";
    }else if(*lengthPtr < *widthPtr){
        cout << "The width is greater than the length\n";
    }else{
        cout << "The length and the width are the same\n";
    }
    
    return 0;
}