// File: BankAccount.cpp OR BankAccount.h
// Description: This is the Basic Account Class for All Banking Accounts
// Author: Jason Hurley
// Student ID: 0329384
// Date: 5.7.20

#include <iostream>
#pragma once
using namespace std;

struct amountOwed
{
	double serviceCharges;				// Stores Service Charges Incurred
	double totalAmountOwed;				// Stores Service Charges Incurred Total
};

class BankAccount
{
protected:

	double balance;						// Stores Balance of Account
	int monthlyDeposits;				// Stores Amount of Monthly Deposits
	int monthlyWithdrawals;				// Stores Amount of Monthly Withdrawals
	double annualInterestRate;			// Stores User Generated Annual Interest Rate
	double monthlyCharges;				// Store Total Monthly Charges
	double monthlyServiceCharges;		// Stores Monthly Service Charges

public:

	// Constructor
	BankAccount(double userBal, double annualIntRate)
	{
		balance = userBal;						// Sets Balance to the Passed in User Balance
		annualInterestRate = annualIntRate;		// Sets Annual Interest Rate to the Passed in Annual Interest Rate

		monthlyDeposits = 0;					// Initializes Data
		monthlyWithdrawals = 0;					// Initializes Data
		monthlyServiceCharges = 0.0;			// Initializes Data
		monthlyCharges = 0.0;					// Initializes Data
	}

	double getBalance() const					// Getter; Returns User Balance
	{
		return balance;
	}

	int getMonthlyDeposits() const				// Getter; Returns Number of Monthly Deposits
	{
		return monthlyDeposits;
	}

	int getMonthlyWithdrawals() const			// Getter; Returns Number of Monthly Withdrawals
	{
		return monthlyWithdrawals;
	}

	double getAnnualInterestRate() const		// Getter; Returns Value for Annual Interest Rate
	{
		return annualInterestRate;
	}

	double getMonthlyCharges() const			// Getter; Returns Value for Monthly Charges
	{
		return monthlyCharges;
	}

	virtual void deposit(double depAmt)			// Virtual Function; Deposits Function that Deposits to User Account
	{
		balance += depAmt;						// Adds Deposit Amount to Balance
		monthlyDeposits++;						// Increases the Amount of Deposits
	}

	virtual void withdraw(double withAmt)		// Virtual Function; Withdrawal Function that Withdraws from User account
	{
		balance -= withAmt;						// Subtracts Withdrawal Amount from Balance
		monthlyWithdrawals++;					// Increases the Amount of Withdrawals
	}

	virtual void calcInt()						// Virtual Function; Calculates Interest and Adds to Balance
	{
		balance += (annualInterestRate / 12.0) * balance;
	}

	virtual amountOwed monthlyProc()			// Virtual Function; Performs Monthly Processing
	{
		balance -= monthlyCharges;				// Subtracts Monthly Charges from Balance

		calcInt();								// Calculates Monthly Interest

		monthlyDeposits = 0;					// Reinitializer
		monthlyWithdrawals = 0;					// Reinitializer
		monthlyCharges = 0.0;					// Reinitializer
		monthlyServiceCharges = 0.0;			// Reinitializer

		amountOwed temp{};
		return temp;
	}

};
