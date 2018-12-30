#include <iostream>

#include "TSP.h"

/*
 * CHRISTOFIDES ALGORITHM
 * algorithm for calculating an approximate solution to the travelling salesman problem (TSP)
 * Step 1: Create a minimum spanning tree
 * Step 2: Find the set of verticies with odd degree
 * Step 3: Calculate the minimum-weight perfect matching graph in the induced subgraph given by the verticies with odd degree
 * Step 4: Combine the minimum-weight perfect match with the minimum spanning tree to form a multigraph
 * Step 5: Form an Eulerian Circuit from the resulting multigraph
 * Step 6: Change the circuit into a Hamiltonian Circuit by skipping repeated verticies
 */
int main(void) {

	TSP christofide;

	// adjacency matrix representing an undirected weighted graph
	int graph[N][N] = {{ I, 10,  I, 20, 20,  5, 15,  5,  I,  I},
			   {10,  I,  5, 10,  I,  I,  I, 20, 15,  5},
			   { I,  5,  I,  5,  I,  I,  I,  I,  I, 15},
			   {20, 10,  5,  I, 10,  I,  I,  I,  I,  I},
			   {20,  I,  I, 10,  I,  5,  I,  I,  I,  I},
			   { 5,  I,  I,  I,  5,  I, 10,  I,  I,  I},
			   {15,  I,  I,  I,  I, 10,  I,  5,  I,  I},
			   { 5, 20,  I,  I,  I,  I,  5,  I, 20,  I},
			   { I, 15,  I,  I,  I,  I,  I, 20,  I, 10},
			   { I,  5, 15,  I,  I,  I,  I,  I, 10,  I}
			  };
	
	// step 1
	int mst[N][N];
	christofide.minimumSpanningTree(graph, mst);

	for(int y = 0; y < N; ++y) {
		for(int x = 0; x < N; ++x) {
			if(mst[y][x] == I)
				cout << "- ";
			else
				cout << mst[y][x] << " ";
		}
		cout << endl;
	}

	// step 2
	int degree[N];
	christofide.getVertexDegree(mst, degree);

	int oddDegree[N][N];
	christofide.oddDegree(graph, degree, oddDegree);

	cout << endl << endl;
	for(int y = 0; y < N; ++y) {
		for(int x = 0; x < N; ++x) {
			if(oddDegree[y][x] == I)
				cout << "- ";
			else
				cout << oddDegree[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}
