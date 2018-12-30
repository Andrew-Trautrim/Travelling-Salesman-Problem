#ifndef TSP_H
#define TSP_H

#define N 10  // size of graph
#define I 999 // infinite
#define U -1  // undefinded

#include <cstdlib>

using namespace std;

class TSP {

public:	

	void combine(int graph1[N][N], int graph2[N][N]); // combines two given graphs
	void getVertexDegree(int graph[N][N], int degree[N]); // function calculates the degree of each vertex
	void minimumSpanningTree(int graph[N][N], int mst[N][N]); // function creates adjacency matrix representing a MST of a given graph

private:

	void getMinimum(int *from, int *to, int visited[N], int graph[N][N]);

};

#endif /* TSP_H */
