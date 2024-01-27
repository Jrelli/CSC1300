#include <iostream>
#include <vector>

using namespace std;

int main(){
    // creates vector and multiplies everything inside by 2
    vector <int> myVector = {7,4,36,1,3,6,2,99,77,10};
    for(int i = 0; i < 10; i++){
        myVector.at(i) = myVector.at(i) * 2;
    }

    // outputs vector contents
    cout << "\n\nThe vector elements, multiplied by 2, are: ";
    for(int i = 0; i < 10; i++){
        cout << myVector.at(i) << " ";
    }
    cout << "\n\n";

    // adds up the total of the contents of the vector and displays them.
    int total = 0;
    for(int i = 0; i < 10; i++){
        total = total + myVector.at(i);
    }
    cout << "The total of all array elements is " << total << "\n\n";

    // selection sort to order the vector from least big to most big
    int minimum;
    int temporary;
    for(int i = 0; i < 10 - 1; i++){
        minimum = i;
        for(int j = i + 1; j < 10; j ++){
            if(myVector.at(j) < myVector.at(minimum)){
                minimum = j;
            }
        }
        temporary = myVector.at(i);
        myVector.at(i) = myVector.at(minimum);
        myVector.at(minimum) = temporary;
    }

    // output the contents of the vector
    cout << "The sorted vector elements are: ";
    for(int i = 0; i < 10; i++){
        cout << myVector.at(i) << " ";
    }
    cout << "\n\n";

    return 0;
}