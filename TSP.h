#ifndef TSP_H
#define TSP_H

#define N 10   // size of graph
#define I 999 // infinite
#define U -1  // undefinded

#include <cstdlib>
#include <iostream>

using namespace std;

class TSP {

public:	

	int edgeCount(int graph[N][N], bool complete); // calculates and returns the number of edges in a given graph

	bool eulerianCircuit(int graph[N][N], int v, int visited[N][N]); // creates an Eulerian Circuit from a given graph

	void combine(int graph1[N][N], int graph2[N][N]); // combines two given graphs
	void getVertexDegree(int graph[N][N], int degree[N]); // function calculates the degree of each vertex 
	void minimumSpanningTree(int graph[N][N], int mst[N][N]); // function creates adjacency matrix representing a MST of a given graph
	void oddDegree(int graph[N][N], int degree[N], int oddDegree[N][N]); // function creates graph out of odd degree verticies
	void removeRepeatedVerticies(int graph[N][N], int hc[N][N]); // removes all repeating verticies, directs path elsewhere

private:

	bool compare(int graph1[N][N], int graph2[N][N]); // returns true if the graphs are equal

	void getMinimum(int *from, int *to, int visited[N], int graph[N][N]); // gets the smallest edge weight in a given adjacency matrix

};

#endif /* TSP_H */
