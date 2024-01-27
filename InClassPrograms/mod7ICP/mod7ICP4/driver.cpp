#include "luckyguess.h"

int main(){
    string name;
    string favFood;
    int favNum;

    getUserData(name, favFood, favNum);
    
    if(luckyGuess(favNum)){
        cout << name + ", you will get a lifetime supply of " + favFood << "!" << endl;
    }else{
        cout << name + ", sorry, you get no " + favFood << endl;
    }
    return 1;
}