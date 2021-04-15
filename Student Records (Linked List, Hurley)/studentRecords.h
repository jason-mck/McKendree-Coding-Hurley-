#pragma once
#include <string>
#include <iostream>
using namespace std;

struct studentRecords
{
	string studentName;																	// Stores the Student Name String
	int studentAge;																		// Stores the Student Age Integer
	float studentGPA;																	// Stores the Student GPA
	studentRecords* next;																// Stores the Address of the Next Node
};

class node
{
private:

	studentRecords* head, * tail;

public:
	node()																				// Initializes Head and Tail Variables
	{
		head = NULL;
		tail = NULL;
	}

	void Put_One_In()																	// Puts One Record into the List
	{
		string stuName;
		int stuAge;
		float stuGpa;

		cout << "\n\nENTERING STUDENT DATA TO LIST.\n\n";								// Lines 33 - 41 Get Input and Output Info to User
		cout << "Student Name: ";
		cin >> stuName;
		cout << "Student Age (Integer): ";
		cin >> stuAge;
		cout << "Student GPA (Decimal): ";
		cin >> stuGpa;

		cout << "Entering to List...\n\n";

		studentRecords* temp = new studentRecords;										// Lines 43 - 47 Declares a Node and Stores Information in it.
		temp->studentName = stuName;
		temp->studentAge = stuAge;
		temp->studentGPA = stuGpa;
		temp->next = NULL;

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
	}

	void Print_Da_List()
	{
		cout << "PRINTING STUDENT DATA...\n\n";

		studentRecords* start = head;
		int iteration = 0;

		if (!start)
		{
			cout << "\nNO STUDENT DATA...RETURNING TO MENU...\n\n";
			return;
		}
		else
		{
			cout << "\n\tNAME\t\tAGE\t\tGPA\n";

			while (start)
			{
				cout << "#" << iteration << "\t" << start->studentName << "\t\t";
				cout << start->studentAge << "\t\t";
				cout << start->studentGPA << "\t\t";
				cout << endl;
				start = start->next;
				iteration++;
			}
		}
	}

	void Take_One_Out()
	{
		if (head == NULL)
		{
			cout << "\nERROR...LINKED LIST EMPTY. RETURNING TO MENU";
			return;
		}

		Print_Da_List();

		int pos_to_del = 0;
		studentRecords* temp = head;
		cout << "\nSTUDENT DELETION...\n\n";
		cout << "PLEASE SELECT STUDENT POS FOR DELETION: ";
		cin >> pos_to_del;

		if (pos_to_del == 0)
		{
			head = temp->next;
			free(temp);
			return;
		}

		for (int i = 0; temp != NULL && i < pos_to_del - 1; i++)
		{
			temp = temp->next;
		}

		if (temp == NULL || temp->next == NULL)
		{
			cout << "\nSELECTION EXCEEDS NUMBER OF NODES. PLEASE INSERT MORE NODES\n\n";
			return;
		}

		studentRecords* next = temp->next->next;
		free(temp->next);
		temp->next = next;
	}

	void Delete_Da_List()
	{
		studentRecords* current = head;
		studentRecords* next;

		while (current != NULL)
		{
			next = current->next;
			delete(current);
			current = next;
		}

		head = NULL;
		tail = NULL;
	}
};



