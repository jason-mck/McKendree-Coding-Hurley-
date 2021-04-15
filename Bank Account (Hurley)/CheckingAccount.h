// File: CheckingAccount.cpp OR CheckingAccount.h
// Description: This is the Savings Account Class that Holds Information About User Savings Accounts
// Author: Jason Hurley
// Student ID: 0329384
// Date: 5.7.20

#include <iostream>
#include <iomanip>
#include "BankAccount.h"
#pragma once
using namespace std;

class CheckingAccount : public BankAccount											// Initializes Class from Bank Account (Derived)
{
private:

	double owed;																	// Stores Amount Owed by User

public:

	CheckingAccount(double bal, double annIntRate) : BankAccount(bal, annIntRate)	
	{
		owed = 0.0;																	// Initializes Owed Amount
	}

	double getAmountOwed() const													// Getter; Returns Owed
	{
		return owed;
	}

	virtual void withdraw(double w)																
	{
		if (w > balance)															// Checks that Balance is Greater than Withdrawal Amount
		{
			cout << fixed << setprecision(2);
			cout << "ERROR! Withdraw Failed; You have attempted to withdraw $" << w << " but the Current Balance is $" << balance;
			cout << "\nYou will be charged a $15 Overdraft Fee.\n";

			balance -= 15.0;
		}
		else
		{
																					// If Balance is Greater, Run Withdrawal
		}
		{
			BankAccount::withdraw(w);												// Withdraws from Balance
		}
	}

	virtual amountOwed monthlyProc()												// Overriden Function; Monthly Processing
	{
		monthlyServiceCharges += 5.0;												// Adds $5 Service Fee
		monthlyServiceCharges += (0.1 * monthlyWithdrawals);						// Adds the Withdrawal (Check) Fees

		monthlyCharges += monthlyServiceCharges;									// Sets the Total Charges = Service Charges

		amountOwed temp;															// Creates Temp Object
		temp.serviceCharges = monthlyCharges;										// Sets the Service Charges Member to Monthly Charges

		BankAccount::monthlyProc();													// Runs Monthly Processes

		if (balance < 0)															// IF Balance is Less than 0
		{
			owed = 0 - balance;														// Then, Set the Owed Amount to Amount Owed
		}

		temp.totalAmountOwed = owed;												// Sets totalAmount Owed Member to Owed Amount
		owed = 0;																	// Resets Owed Amount

		return temp;																
	}
};