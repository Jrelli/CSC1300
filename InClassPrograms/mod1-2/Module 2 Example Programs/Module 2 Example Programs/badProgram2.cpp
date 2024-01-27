/* 
	Filename: badProgram2.cpp
	Author: April Crockett
	Date: 8/22/2023
	Purpose: demonstrate logic errors
	
	
	What's wrong with this program? 
*/

#include <iostream>
using namespace std;

int main()
{
	int a, b;
	int c = a+b;
	
	a = 3;
	b = 4;	
	cout << "The value of c is " << c;	
	
	return 0;
}