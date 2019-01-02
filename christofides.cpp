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
	
	// step 1 - complete undirected weighted graph, G
	// adjacency matrix representing the graph
	int graph[N][N] = {{ I, 26, 25, 23, 31, 18},
			   {26,  I, 21, 22, 27, 29},
			   {25, 21,  I, 24, 19, 20},
			   {23, 22, 24,  I, 12, 30},
			   {31, 27, 19, 12,  I, 25},
			   {18, 29, 20, 30, 25,  I},
			  };
	
	// step 2: calculate minimum spanning tree, T, from graph G
	int mst[N][N];
	christofide.minimumSpanningTree(graph, mst);

	// step 3: calculate degree of verticies from T
	int degree[N];
	christofide.getVertexDegree(mst, degree);

	// step 4: subgraph of G from odd degree verticies given by T
	int oddDegree[N][N];
	christofide.oddDegree(graph, degree, oddDegree);

	// step 5
	// **TODO** MINIMUM-WEIGHT PERFECT MATCH
	int perfectMatch[N][N] = {{ I,  I, 25,  I,  I,  I},
				  { I,  I,  I, 22,  I,  I},
				  {25,  I,  I,  I,  I,  I},
				  { I, 22,  I,  I,  I,  I},
				  { I,  I,  I,  I,  I,  I},
				  { I,  I,  I,  I,  I,  I}
				 };

	// step 6: combine minimum-weight perfect match with the minimum spanning tree
	christofide.combine(mst, perfectMatch);
	
	// step 7: create Eulerian Circuit from the combined graph
	int edgeCount = christofide.edgeCount(mst, false);
	int from[edgeCount], to[edgeCount];
	christofide.eulerianCircuit(mst, 0, 0, edgeCount, from, to);

	// step 8: remove repeated verticies
	int circuit[N][N];
	christofide.removeRepeatedVerticies(graph, from, to, edgeCount, circuit);
	
	christofide.printHamiltonianCircuit(circuit, 0);

	return 0;
}
