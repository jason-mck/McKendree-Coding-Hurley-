// File: CSI 330 Program #2
// Description: This program utilizes lists.
// Author: Jason Hurley
// Student ID: 0329384
// Date: 09-29-20
#include <iostream>
#include "studentRecords.h"
using namespace std;

int main()
{
	int userOption = 0;
	node studentRecordLL;
	
		while (userOption != 4)
		{
			cout << "\nWelcome to the Student Record Management System. Please Select an Option\n\n";
			cout << "1. Enter New Data\n";
			cout << "2. Delete Selected Data\n";
			cout << "3. Print All Data\n";
			cout << "4. End Program\n\n";

			cout << "SELECTION: ";
			cin >> userOption;

			while (userOption < 0 || userOption > 4 || cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "\n\nERROR! Please Select a Valid Option: ";
				cin >> userOption;
			}

			if (userOption == 1)
				studentRecordLL.Put_One_In();				// This Function Puts One Set of Data into the Student Record List (Single Node)
			else if (userOption == 2)
				studentRecordLL.Take_One_Out();				// This Function Takes One Set of Data out of the Student Record List (Single Node)
			else if (userOption == 3)
				studentRecordLL.Print_Da_List();			// This Function Displays All of the Data in the Linked List
			else if (userOption == 4)
				studentRecordLL.Delete_Da_List();			// This Function Deletes the List Stored, then Breaks out of the Loop
		}

		return 0;
}