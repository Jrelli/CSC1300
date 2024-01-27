#include <iostream>

using namespace std;

int main(){
    string favFoods[10] , *favFoodsPtr;
    favFoodsPtr = favFoods;

    cout << "\n\nEnter your favorite foods!\n";

    for(int i = 0; i < 10; i++){
        cout << "FAVORITE FOOD " << i + 1 << ": ";
        getline(cin, *(favFoodsPtr + i));
    }

    cout << "\n\nGreat, here is your list:";
    for(int i = 0; i < 10; i++){
        cout << "\n" << favFoods[i];
    }
    return 0;
}