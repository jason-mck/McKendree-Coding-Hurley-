// File: SavingsAccount.cpp OR SavingsAccount.h
// Description: This is the Savings Account Class that Holds Information About User Savings Accounts
// Author: Jason Hurley
// Student ID: 0329384
// Date: 5.7.20
#include <iostream>
#include <iomanip>
#include "BankAccount.h"
#pragma once
using namespace std;

class SavingsAccount : public BankAccount														// Class Derivation from Bank Account Class
{
private:

	bool status;																				// Stores the Status of Account (T = Active, F = Inactive)

public:
	
	SavingsAccount(double balance, double annualIntRate) : BankAccount(balance, annualIntRate)	
	{
		if (balance > 25)																		// Determines if Account is Active or Not Given Initial Balance
			status = true;																		// If Greater, Account Active
		else																					
			status = false;																		// If Less Than, Account Inactive
	}

	bool getStatus() const																		// Getter; Returns the Account Status
	{
		return status;
	}

	virtual void withdraw(double withAmt)														// Overridden; Overrides Withdraw Function
	{
		if (status == true)																		// Checks Status
		{
			BankAccount::withdraw(withAmt);														// If True, Withdrawal Run
			if (balance < 25)																	// Checks if Balance is Under $25 After Withdrawal
				status = false;																	// Sets Status to False
		}

		else																					// If False, Then Display Inactive Message
		{
			cout << fixed << setprecision(2);
			cout << "Withdrawal failed! Savings account is inactive (Current Balance: $" << balance << ")" << endl;
		}
	}

	virtual void deposit(double d)																// Overridden; Overides Deposit function
	{
		if (status == false)																	// Checks for Inactive Account
		{
			if (d + balance >= 25)																// If Deposit + Balance Greater than 25, Deposit is Made
				BankAccount::deposit(d);

			else																				// Displays Inactivity Message if Deposit Does Not Bring Account to $25+
			{
				cout << fixed << setprecision(2);
				cout << "Deposit Entered! Savings account will  still be inactive after deposit! (Current Balance: $" << balance + d << ")\n";
				return;
			}
			
		} 
		else																					// Runs Deposit if Account is Active
			BankAccount::deposit(d);
	}

	virtual amountOwed monthlyProc()															// Overridden; Runs Monthly Processing
	{
		if (monthlyWithdrawals > 4)																// If Amount of Withdrawals is 4+, Calculates Fees
			monthlyCharges += 1.0 * (monthlyWithdrawals - 4);									// Calculates Feesfor Multiple Withdrawals

		amountOwed temp;																		// Creates Temp Struct
		temp.serviceCharges = monthlyCharges;													// Sets Service Charges in Temp
		temp.totalAmountOwed = 0.0;																// Initializes Total Amount Owed as Zero

		BankAccount::monthlyProc();																// Calls Monthly Processing Base Class
		
		if (balance < 25)																		// Sets Activity to False if Balance is Under Threshold 
			status = false;

		return temp;
	}
};