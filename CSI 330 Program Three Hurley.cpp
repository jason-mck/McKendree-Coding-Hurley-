// File: CSI 330 Program 4 Trees Hurley
// Description: This program is used to demonstrate a tree through linked lists.
// Author: Jason Hurley
// Student ID: 0329384
// Date: 10-16-20
#include<iostream>
using namespace std;

struct node											
{
	int data;										
	node* left;										
	node* right;									
};

class Tree											
{
public:
	node* createnode(int value)						
	{
		struct node* newnode = new node;			
		newnode->data = value;						
		newnode->left = NULL;						
		newnode->right = NULL;						
		return(newnode);							
	}

	node* findNode(node* root)						
	{
		while (root->left != NULL)
			root = root->left;
		return root;
	}

	void postOrder(node* root)
	{
		if (root != NULL)
		{
			postOrder(root->left);
			postOrder(root->right);
			cout << root->data << " ";
		}
	}

	void inOrder(node* root)
	{
		if (root != NULL)
		{
			inOrder(root->left);
			cout << root->data << " ";
			inOrder(root->right);
		}
	}

	void preOrder(node* root)
	{
		if (root != NULL)
		{
			cout << root->data << " ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void insertNode(int treeNodeVal, node* leaf)
	{
		if (leaf->left == NULL || leaf->right == NULL)
		{
			if (leaf->left == NULL)
			{
				leaf->left = new node;
				leaf->left->data = treeNodeVal;
				leaf->left->left = NULL;
				leaf->left->right = NULL;
			}
			else
			{
				leaf->right = new node;
				leaf->right->data = treeNodeVal;
				leaf->right->left = NULL;
				leaf->right->right = NULL;
			}
		}
		else
		{
			if (leaf->left != NULL)
				insertNode(treeNodeVal, leaf->left);
			else if (leaf->right != NULL)
				insertNode(treeNodeVal, leaf->right);
		}
	}	

	node* deleteNode(node* root, int data) 
	{
		if (root == NULL)
			return root;
		else if (data != root->data)
		{
			root->left = deleteNode(root->left, data);
			root->right = deleteNode(root->right, data);
		}        
		else 
		{
			if (root->left == NULL && root->right == NULL) 
			{
				delete root;
				root = NULL;
			}
			else if (root->left == NULL) 
			{
				struct node* temp = root;
				root = root->right;
				delete temp;
			}
			else if (root->right == NULL) 
			{
				struct node* temp = root;
				root = root->left;
				delete temp;
			}
			else 
			{
				struct node* temp = findNode(root->right);
				root->data = temp->data;
				root->right = deleteNode(root->right, temp->data);
			}
		}
		return root;
	}
};

int main()
{
	// Variables
	Tree myTree;
	node* root;
	int userChoice = '4';

	// Construction of Starting Tree
	root = myTree.createnode(1);
	root->left = myTree.createnode(2);
	root->right = myTree.createnode(3);
	root->left->left = myTree.createnode(4);
	root->left->right = myTree.createnode(5);
	root->right->left = myTree.createnode(6);
	root->right->right= myTree.createnode(7);
	root->left->left->left = myTree.createnode(8);
	root->left->left->right = myTree.createnode(9);
	root->left->right->left = myTree.createnode(10);

	// User Output / Menu Program
	cout << "Welcome to the Tree Program. This will allow you to store values in a Binary Tree!\n\n";

	while (userChoice != 4) 
	{
		cout << "\n1. Insert Node\n";
		cout << "2. Delete Node\n";
		cout << "3. View Post-Order, Pre-Order, and Post-Order Notation\n";
		cout << "4. End Program\n\n";

		cout << "Please Select a Menu Option (1-4 ONLY): ";
		cin >> userChoice;

		while (userChoice < 1 || userChoice > 4 || cin.fail())
		{
			cout << "\nERROR: Invalid Input. Please Reselect your Option: ";
			cin.clear();
			cin >> userChoice;
		}

		if(userChoice == 1)
		{
			int userInt = 0;
			cout << "\nPlease enter the number you would like to insert: ";
			cin >> userInt;
			cout << "NODE INSERTED\n";
			myTree.insertNode(userInt, root);
		}
		else if(userChoice == 2)
		{
			int userDel = 0;
			cout << "\nPlease select a node that you would like to delete: ";
			cin >> userDel;
			root = myTree.deleteNode(root, userDel);
		}
		else if(userChoice == 3)
		{
			cout << "\nPOSTORDER: ";
			myTree.postOrder(root);
			cout << endl;
			cout << "PREORDER: ";
			myTree.preOrder(root);
			cout << endl;
			cout << "INORDER: ";
			myTree.inOrder(root);
			cout << endl;
		}
		else if(userChoice == 4)
		{
			delete root;
			return 0;
		}
	}
}