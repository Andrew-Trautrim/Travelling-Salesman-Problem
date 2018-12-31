#ifndef TSP_H
#define TSP_H

#define N 5   // size of graph
#define I 999 // infinite
#define U -1  // undefinded

#include <cstdlib>

using namespace std;

class TSP {

public:	

	int edgeCount(int graph[N][N], bool complete); // calculates and returns the number of edges in a given graph

	void eulerianCircuit(int graph[N][N], int edgeCount, int ec[N][N]); // creates an Eulerian Circuit from a given graph
	void combine(int graph1[N][N], int graph2[N][N]); // combines two given graphs
	void getVertexDegree(int graph[N][N], int degree[N]); // function calculates the degree of each vertex 
	void minimumSpanningTree(int graph[N][N], int mst[N][N]); // function creates adjacency matrix representing a MST of a given graph
	void oddDegree(int graph[N][N], int degree[N], int oddDegree[N][N]); // function creates graph out of odd degree verticies
	void removeRepeatedVerticies(int graph[N][N], int hc[N][N]); // removes all repeating verticies, directs path elsewhere

private:

	bool getNextEdge(int from, int *to, int graph[N][N], int visited[N][N]);

	void getMinimum(int *from, int *to, int visited[N], int graph[N][N]); // gets the smallest edge weight in a given adjacency matrix

};

#endif /* TSP_H */
