//File: Lab6_P4
//Description: This program is a password checker prorgam.
//Author: Jason Hurley
// Student ID: 0329384
//Date: 03.18.19

const int ARRAY_SIZE = 64;                 // Array Sizing Constant

#include <iostream>
#include <cstring>
#include <cctype>
#include <string>
using namespace std;

void checkCriteria(char*);                  // Function Prototype; Checks Given Criteria

int main()
{
	// Step One; Declare Variables

		// Characters
		char userPassword[ARRAY_SIZE];      // Stores User Password as Char Array


	// Step Two; User Input / Output
	cout << "This program will ask you to input a password of your choosing, and check the following criteria.";
	cout << "\n\n1. Your password should be at least six characters long.";
	cout << "\n2. Your password should contain at least one uppercase and at least one lower letter.";
	cout << "\n3. Your password should contain at least one digit.";
	cout << "\n4. Your password should be less than 32 digits.\n\n";
	cout << "Please enter your Password: ";
	cin.getline(userPassword, ARRAY_SIZE);

	while (strlen(userPassword) > 32)
	{
		cout << "\n\nERROR! Please make sure your Password is Less than 32 Characters!\n";
		cout << "Please enter your Password: ";
		cin.getline(userPassword, ARRAY_SIZE);
		cout << endl;
		checkCriteria(userPassword);
	}

	// Step Three; End Program
	return 0;
}

void checkCriteria(char* password)
{
	// Integers
	int upper = 0;      // Stores Upper (Is there Uppercase Character?)
	int lower = 0;      // Stores Lower (Is there Lowercase Character?)
	int digit = 0;      // Stores Digit (Is there Digit Character?)

	for (int i = 0; i < strlen(password); i++)
	{
		if (isupper(password[i]))   // Checks if there are Uppercase
			upper++;
		if (islower(password[i]))   // Checks if there are Lowercase
			lower++;
		if (isdigit(password[i]))   // Checks if there are Digits
			digit++;
	}

	if (strlen(password) <= 6)                                                  // Checks that Password is More than 6 Chars
		cout << "Password is not at least six characters long.\n";
	if (upper == 0)                                                             // Checks that Password contains Uppercase
		cout << "Password does not contain at least one uppercase letter.\n";
	if (lower == 0)                                                             // Checks that Password Contains Lowercase
		cout << "Password does not contain at least one lowercase letter.\n";
	if (digit == 0)                                                             // Checks that Password Contrains Digit
		cout << "Password does not have at least one digit.\n";
	if (upper > 0 && lower > 0 && digit > 0 && strlen(password) > 6)            // Checks that All Criteria Met
		cout << "VALID PASSWORD.\n\n";

	return;
}