// File: CSI 230 Mini Project.cpp
// Description: This is a bank account problem using Classes
// Author: Jason Hurley
// Student ID: 0329384
// Date: 5.7.20
#include <iostream>
#include "SavingsAccount.h"
#include "CheckingAccount.h"
using namespace std;

int main()
{
	// Step One; Variable Declaration

		// Doubles
		double startBal = 0.0;									// Stores User Starting Balance
		double annualRate = 0.0;								// Stores User Annual Rate
		double userDeposit = 0.0;								// Stores User Deposit Each Iteration
		double userWithdrawal = 0.0;							// Stores User Withdrawal Each Iteration
		double totalUserDeposits = 0.0;							// Stores Amount Total of User Deposits
		double totalUserWithdrawals = 0.0;						// Stores Amount Total of User Withdraways

	// Step Two; User Output
		cout << "Welcome to the McKendree Banking Program. This program will help track finances with a Savings and Checking Account.\n";
		cout << "First, we will set up your accounts. Please enter values when prompted.\n\n";
		cout << "------------------- SAVINGS ACCOUNT SETUP AND INFORMATION -------------------";

		cout << "\n\nPlease enter your Savings Account Starting Balance: $";
		cin >> startBal;

		while (startBal < 25)									// Checks that User Entered a Greater Amount than 25 to Open Account
		{
			cout << "ERROR! Please enter a Positive Number Greater than $25: $";
			cin >> startBal;
		}

		cout << "Please enter your Savings Account Interest Percentage (EX: 19.5): ";
		cin >> annualRate;

		while (annualRate < 0)									//  Checks that User Entered a Greater Amount than 0 for Annual Rate
		{
			cout << "ERROR! Please enter a Positive Number Greater than 0%: ";
			cin >> annualRate;
		}

	// Step Three; Set up Savings Account and Get Data
	annualRate = annualRate / 100;								// Converts Rate to Decimal
	SavingsAccount savings(startBal, annualRate);				// Initializes a Savings Account

	cout << "\n\nPlease enter your deposits one by one. When finished, type -1 for Withdrawals: ";
	cout << "\n\nPlease enter Deposit Amount: $";
	cin >> userDeposit;

	while (userDeposit != -1)									// Runs While Loop, Getting Deposits Until User Enters Sentinel to Move to Next Loop
	{
		totalUserDeposits += userDeposit;						// Adds the User Deposit to Total Deposit Amount 
		savings.deposit(userDeposit);							// Calls the Class Deposit Function and Deposits Amount to Savings
		
		cout << fixed << setprecision(2);						// Input/Output Formatting (Set Two Decimal Points)

		cout << "\nBalance: $" << savings.getBalance();
		cout << "\nNumber of deposits: " << savings.getMonthlyDeposits();
		cout << "\nNumber of withdrawals: " << savings.getMonthlyWithdrawals();

		cout << "\n\nPlease enter another deposit, or -1 to view Final Stats: ";
		cin >> userDeposit;
	}

	cout << "\nPlease enter your withdrawals one by one. When finished, type -1 for Final Stats\n";
	cout << "\nPlease enter Withdrawal Amount: $";
	cin >> userWithdrawal;

	while (userWithdrawal != -1) 
	{
		totalUserWithdrawals += userWithdrawal;					// Adds the User Withdrawal to Total Withdrawal Amount 
		savings.withdraw(userWithdrawal);						// Calls the Class Withdraw Function and Withdraws Amount from Savings

		cout << fixed << setprecision(2);						// Input/Output Formatting (Set Two Decimal Points)

		cout << "\nBalance: $" << savings.getBalance();
		cout << "\nNumber of deposits: " << savings.getMonthlyDeposits();
		cout << "\nNumber of withdrawals: " << savings.getMonthlyWithdrawals();

		cout << "\n\nEnter another withdrawal amount, or -1 to stop: ";
		cin >> userWithdrawal;
	}

	cout << "\n--------- SAVINGS ACCOUNT STATISTICS ---------\n";
	cout << fixed << setprecision(2);
	cout << "\nStarting Balance:" << setw(20) << "$" << startBal;							// Displays Start Balance
	cout << "\nNumber of Deposits: " << setw(23) << savings.getMonthlyDeposits();			// Displays Number of Deposits
	cout << "\nTotal Deposit Amount:" << setw(18) << "$" << totalUserDeposits;				// Displays Deposit Amount
	cout << "\nNumber of Withdrawals: " << setw(20) << savings.getMonthlyWithdrawals();		// Displays Number of Withdrawals
	cout << "\nTotal Amount of Withdrawals:" << setw(11) << "$" << totalUserWithdrawals;	// Displays Total Amount of Withdrawals

	amountOwed tempSaving = savings.monthlyProc();											// Performs Monthly Processing, Gets Service Charges

	cout << "\nService fees:" << setw(26) << "$" << tempSaving.serviceCharges;				// Displays Monthly/Service Fees
	cout << "\nEnding balance:" << setw(22) << "$" << savings.getBalance();					// Displays End Balance (Post-Processing)
	cout << "\n----------------------------------------------\n";
	
	// Step Four; Checking Account Information
	cout << "\n\n--------- CHECKING ACCOUNT SETUP AND INFORMATION ---------\n";

	cout << "\n\nPlease enter your Checking Account Starting Balance: $";
	cin >> startBal;

	while (startBal < 0)																	// Checks that User Enters Start Bal Greater than 0
	{
		cout << "ERROR! Please enter a Positive Number Greater than $0: $";
		cin >> startBal;
	}

	cout << "Please enter your Checking Account Interest Percentage (EX: 19.5): ";
	cin >> annualRate;

	while (annualRate < 0)																	// Checks that User Enters Annual Interest Rate Greater than 0
	{
		cout << "ERROR! Please enter a Positive Number Greater than 0%: ";
		cin >> annualRate;
	}

	annualRate = annualRate / 100;															// Converts Annual Rate to Decimal
	CheckingAccount checking(startBal, annualRate);											// Creates Checking Account Item

	cout << "\nPlease enter your withdrawals one by one. When finished, type -1 for Final Stats\n";
	cout << "\nPlease enter Withdrawal Amount: $";
	cin >> userWithdrawal;

	while (userWithdrawal != -1)															// Loop to Get Withdrawals Until Setinel
	{
		totalUserWithdrawals += userWithdrawal;												// Totalizes Withdrawals
		checking.withdraw(userWithdrawal);													// Sends User Withdrawal Amount to Subtract from Balance

		cout << "\nBalance: $" << checking.getBalance();
		cout << "\nNumber of withdrawals: " << checking.getMonthlyWithdrawals();

		cout << "\n\nEnter another withdrawal amount, or -1 to stop: ";
		cin >> userWithdrawal;
	}

	cout << "\n--------- CHECKING ACCOUNT STATISTICS ---------\n";
	cout << fixed << setprecision(2);
	cout << "\nStarting Balance:" << setw(21) << "$" << startBal;
	cout << "\nNumber of Withdrawals: " << setw(20) << checking.getMonthlyWithdrawals();
	cout << "\nTotal Amount of Withdrawals:" << setw(11) << "$" << totalUserWithdrawals;

	amountOwed tempChecking = checking.monthlyProc();										// Performs Monthly Processing, Subtracts Service Charges from Balance

	cout << "\nService fees:" << setw(26) << "$" << tempChecking.serviceCharges;
	cout << "\nEnding balance:" << setw(23) << "$" << checking.getBalance();


	// Step Five; End Program
	cout << endl;
	return 0;
	
}
