#ifndef TSP_H
#define TSP_H

#define N 6   // size of graph
#define I 999 // infinite
#define U -1  // undefinded

#include <cstdlib>
#include <iostream>

using namespace std;

class TSP {

public:	

	int edgeCount(int graph[N][N], bool complete); // calculates and returns the number of edges in a given graph

	bool eulerianCircuit(int graph[N][N], int v, int e, int edgeCount, int from[], int to[]); // creates an Eulerian Circuit from a given graph
	bool minimumCostPerfectMatch(int graph[N][N], int v, int match[N][N]); // calculates minimum cost perfect match of a given graph

	void combine(int graph1[N][N], int graph2[N][N]); // combines two given graphs
	void getVertexDegree(int graph[N][N], int degree[N]); // function calculates the degree of each vertex 
	void minimumSpanningTree(int graph[N][N], int mst[N][N]); // function creates adjacency matrix representing a MST of a given graph
	void oddDegree(int graph[N][N], int degree[N], int oddDegree[N][N]); // function creates graph out of odd degree verticies
	void removeRepeatedVerticies(int graph[N][N], int from[], int to[], int edgeCount, int circuit[N][N]); // removes all repeating verticies, directs path elsewhere
	void removeCommonEdges(int graph1[N][N], int graph2[N][N]); // removes common edges between two graphs
	void printHamiltonianCircuit(int circuit[N][N], int pos); // prints out the circuit from a given adjacency matrix, must be a hamiltonian circuit

private:

	bool compare(int graph1[N][N], int graph2[N][N]); // returns true if the graphs are equal
	bool containsEdge(int from[], int to[N], int f, int t, int edgeCount); // checks if a specific edge is in a given set of edges

	int getWeight(int graph[N][N]); // returns the total weight of a graph

	void getMinimum(int *from, int *to, int visited[N], int graph[N][N]); // gets the smallest edge weight in a given adjacency matrix
	void initialize(int graph[N][N]); // initialize all values to infinite

};

#endif /* TSP_H */
