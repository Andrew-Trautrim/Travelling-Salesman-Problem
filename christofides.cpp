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
	
	// complete undirected weighted graph, G
	// adjacency matrix representing the graph
	int graph[N][N] = {{ I, 37, 51, 50, 46},
			   {37,  I, 44, 41, 48},
			   {51, 44,  I, 28, 33},
			   {50, 41, 28,  I, 53},
			   {46, 48, 33, 53,  I}
			  }; 
	cout << "Complete Undirected Wighted Graph - G" << endl;
	christofide.printMatrix(graph);

	// step 1: calculate minimum spanning tree T of G
	int mst[N][N];
	christofide.minimumSpanningTree(graph, mst);
	cout << "Minimum Spanning Tree - T" << endl;
	christofide.printMatrix(mst);

	// step 2: calculate odd degree of verticies from T
	int degree[N];
	christofide.getVertexDegree(mst, degree);

	// graph of odd degree verticies O
	int oddDegree[N][N];
	christofide.oddDegree(graph, degree, oddDegree);
	cout << "Odd Degree Verticies of T Subgraph of G - O" << endl;
	christofide.printMatrix(oddDegree);

	cout << "Common edges between O & T removed" << endl;
	christofide.removeCommonEdges(oddDegree, mst);
	christofide.printMatrix(oddDegree);
	
	// step 3 minimum-weight perfect match
	// **TODO** MINIMUM-WEIGHT PERFECT MATCH
	int vertexCount = christofide.vertexCount(oddDegree);
	int match[N][N] = {{I, I, I, I, I},
			   {I, I, I, I, I},
			   {I, I, I, I, I},
			   {I, I, I, I, I},
			   {I, I, I, I, I}
			  };
	int visited[N] = {0, 0, 0, 0, 0};
	christofide.perfectMatch(oddDegree, 0, vertexCount, visited, match);

	cout << "Perfect Match of O - M" << endl;
	christofide.printMatrix(match);

	// step 4: combine minimum-weight perfect match with the minimum spanning tree
	christofide.combine(mst, match);
	cout << "M U T" << endl;
	christofide.printMatrix(mst);
	
	// step 5: create Eulerian Circuit from the combined graph
	int edgeCount = christofide.edgeCount(mst, false);
	int from[edgeCount], to[edgeCount];
	christofide.eulerianCircuit(mst, 0, 0, edgeCount, from, to);

	// step 6: remove repeated verticies creating a hamiltonian circuit
	int circuit[N][N];
	christofide.removeRepeatedVerticies(graph, from, to, edgeCount, circuit);
	cout << "Hamiltonian Circuit" << endl;
	christofide.printMatrix(circuit);
	
	christofide.printHamiltonianCircuit(circuit, 0);
	
	return 0;
}
