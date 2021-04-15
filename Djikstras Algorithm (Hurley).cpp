// Jason Hurley
// CSI 330
// Dr. Pokorny
// This program uses Dijkstras Algorithm to find the shortest path given an adjacency matrix.

#include <iostream>
using namespace std;
#define SIZE 5
#define INFINITY 999999

int findMin(int distance[], bool shortPath[])
{
	int min = INFINITY;
	int minVal;

	for (int i = 0; i < SIZE; i++)
		if (shortPath[i] == false && distance[i] <= min)
		{
			min = distance[i];
			minVal = i;
		}

	return minVal;
}

void dijkstra(int oriGraph[SIZE][SIZE])
{
	int sourceVertex = 0;
	int dist[SIZE];
	bool known[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		dist[i] = INFINITY;
		known[i] = false;
	}

	dist[sourceVertex] = 0;

	for (int count = 0; count < SIZE - 1; count++)
	{
		int a = findMin(dist, known);
		known[a] = true;

		for (int i = 0; i < SIZE; i++)
			if (!known[i] && oriGraph[a][i] && dist[a] != INFINITY && dist[a] + oriGraph[a][i] < dist[i])
				dist[i] = dist[a] + oriGraph[a][i];
	}

	cout << "\n\nVERTEX \t\tDISTANCE (FROM SOURCE = 0)\n";
	for (int i = 0; i < SIZE; i++)
		cout << i << "\t\t" << dist[i] << endl;
}

int main()
{
	int graph[SIZE][SIZE] = { 0, 5, 0, 6, 0,
								5, 0, 9, 0, 7,
								0, 9, 0, 0, 9,
								6, 0, 0, 0, 5,
								0, 7, 9, 5, 0 };

	cout << "Hello! This is a Graphing Program.\n";
	cout << "This program will allow you to input the weights of edges between vertices.\n\n";
	cout << "\nYou will start by inputting 25 vertices, and the shortest path from the Source (0) to a certain vertices.\n\n";

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << "Please Input the Weight Between < " << i + 1 << ", " << j + 1 << " > : ";
			cin >> graph[i][j];
			cout << endl;
		}
	}

	dijkstra(graph);

	return 0;
}

