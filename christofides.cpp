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

	// step 1 - complete undirected weighted graph G
	// adjacency matrix representing the graph
	int graph[N][N] = {{ I,  9,  3,  2, 10},
			   { 9,  I,  8,  7,  5},
			   { 3,  8,  I,  4, 11},
			   { 2,  7,  4,  I,  6},
			   {10,  5, 11,  6,  I},
			  };
	
	// step 2: calculate minimum spanning tree T from graph G
	int mst[N][N];
	christofide.minimumSpanningTree(graph, mst);

	cout << "Minimum Spanning Tree - T" << endl;
	for(int y = 0; y < N; ++y) {
		for(int x = 0; x < N; ++x) {
			if(mst[y][x] == I)
				cout << "- ";
			else
				cout << mst[y][x] << " ";
		}
		cout << endl;
	}

	// step 3: calculate degree of verticies from T
	int degree[N];
	christofide.getVertexDegree(mst, degree);

	// step 4: subgraph of G from odd degree verticies given by T
	int oddDegree[N][N];
	christofide.oddDegree(graph, degree, oddDegree);

	cout << endl << "Odd Degree" << endl;
	for(int y = 0; y < N; ++y) {
		for(int x = 0; x < N; ++x) {
			if(oddDegree[y][x] == I)
				cout << "- ";
			else
				cout << oddDegree[y][x] << " ";
		}
		cout << endl;
	}

	// step 5
	// **TODO** MINIMUM-WEIGHT PERFECT MATCH
	int perfectMatch[N][N] = {{I, I, I, I, I},
				  {I, I, 8, I, I},
				  {I, 8, I, I, I},
				  {I, I, I, I, I},
				  {I, I, I, I, I}
				 };
	cout << endl << "Minimum-weight perfect match - M" << endl;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(perfectMatch[i][j] == I) 
				cout << "- ";
			else
				cout << perfectMatch[i][j] << " ";
		}
		cout << endl;
	}

	// step 6: combine minimum-weight perfect match with the minimum spanning tree
	christofide.combine(mst, perfectMatch);
	cout << endl << "M u T" << endl;
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(mst[i][j] == I) 
				cout << "- ";
			else
				cout << mst[i][j] << " ";
		}
		cout << endl;
	}

	// step 7: create Eulerian Circuit from the combined graph
	int edgeCount = christofide.edgeCount(mst, false);
	cout << endl << "# edges: " << edgeCount << endl;

	// step 8: remove repeated verticies


	return 0;
}
