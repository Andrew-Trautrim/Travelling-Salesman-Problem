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
	
	// complete undirected weighted graph, G
	// adjacency matrix representing the graph
	int graph[N][N] = {{ I, 37, 51, 50, 46},
			   {37,  I, 44, 41, 48},
			   {51, 44,  I, 28, 33},
			   {50, 41, 28,  I, 53},
			   {46, 48, 33, 53,  I}
			  }; 
	cout << "Complete Undirected Wighted Graph - G" << endl;
	printMatrix(graph);

	// step 1: calculate minimum spanning tree T of G
	int mst[N][N];
	minimumSpanningTree(graph, mst);
	cout << "Minimum Spanning Tree - T" << endl;
	printMatrix(mst);

	// step 2: calculate odd degree of verticies from T
	int degree[N];
	getVertexDegree(mst, degree);

	// graph of odd degree verticies O
	int odd[N][N];
	oddDegree(graph, degree, odd);
	cout << "Odd Degree Verticies of T Subgraph of G - O" << endl;
	printMatrix(odd);

	cout << "Common edges between O & T removed" << endl;
	removeCommonEdges(odd, mst);
	printMatrix(odd);
	
	// step 3 minimum-weight perfect match
	// **TODO** MINIMUM-WEIGHT PERFECT MATCH
	int vCount = vertexCount(odd);
	int match[N][N] = {{I, I, I, I, I},
			   {I, I, I, I, I},
			   {I, I, I, I, I},
			   {I, I, I, I, I},
			   {I, I, I, I, I}
			  };
	int visited[N] = {0, 0, 0, 0, 0};
	perfectMatch(odd, 0, vCount, visited, match);

	cout << "Perfect Match of O - M" << endl;
	printMatrix(match);

	// step 4: combine minimum-weight perfect match with the minimum spanning tree
	combine(mst, match);
	cout << "M U T" << endl;
	printMatrix(mst);
	
	// step 5: create Eulerian Circuit from the combined graph
	int eCount = edgeCount(mst, false);
	int from[eCount], to[eCount];
	eulerianCircuit(mst, 0, 0, eCount, from, to);

	// step 6: remove repeated verticies creating a hamiltonian circuit
	int circuit[N][N];
	removeRepeatedVerticies(graph, from, to, eCount, circuit);
	cout << "Hamiltonian Circuit" << endl;
	printMatrix(circuit);
	
	printHamiltonianCircuit(circuit, 0);
	
	return 0;
}
