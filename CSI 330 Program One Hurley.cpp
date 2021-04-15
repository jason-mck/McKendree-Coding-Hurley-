// File: CSI 330 Program #1
// Description: This program solves f(n)=3f(n-1)-2n, f(2)=4 Recursively
// Author: Jason Hurley
// Student ID: 0329384
// Date: 09-03-20

#include <iostream>
using namespace std;

int f(int x)							// Recursive Function
{
	if (x == 2)							// Base Case: When X == 2
		return 4;						// Four is Returned

	else								// Recursive Case: When X < 2 || X == 2
		return 3 * f(x - 1) - 2 * x;	// Function Recurses for User Generated Number (X or userNum)
}

int main()
{
	// Step One: Variable Declaration

		// Integers
		int userNum;		// Stores the User Generated Number	

	// Step Two: Recursive Function Call and Display

	do 
	{
		cout << "Please Enter the Number you Want to Recursively Solve For: ";
		cin >> userNum;
		cout << endl;
	} while (userNum < 2);	// Do While Loop: Ensures there is no UNDEFINED Result/Program Crash from userNum < 2

	cout << "\nF(" << userNum << ") = " << f(userNum);

	return 0;
}