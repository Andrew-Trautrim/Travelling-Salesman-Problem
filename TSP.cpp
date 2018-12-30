#include "TSP.h"

// combines two graphs
void TSP::combine(int graph1[N][N], int graph2[N][N]) {
	
	for(int i = 0; i < N; ++i)
		for(int j = 0 ; j < N; ++j)
			if(graph2[j][i] != I && graph1[j][i] == I)
				graph1[j][i] = graph2[j][i];
	return;
}

// calculatess the degree of each vertex in a given graph
void TSP::getVertexDegree(int graph[N][N], int degree[N]) {
	
	// iterates through the entire 2D array to count how many conections each vertex has
	for(int i = 0; i < N; ++i) {
		int count = 0;
		for(int j = 0; j < N; ++j) 
			if(graph[j][i] != I) // if vertex has a connection i.e. isn't set to an infinite weight
				count++;
		degree[i] = count; // the degree is the number of connection the vertex has
	}

	return;
}

/*
 * Function creates and returns a Minimum Spanning Tree (MST) in the form of an adjacency matrix
 * Calculated using Prim's algorithm
 */
void TSP::minimumSpanningTree(int graph[N][N], int mst[N][N]) {
	int visited[N], from, to;

	for(int i = 0; i < N; ++i) {
		visited[i] = 0;
		for(int j = 0; j < N; ++j) {
			mst[i][j] = I; // all verticies initially set to infinite 
		}
	}
	visited[0] = 1;

	for(int i = 0; i < N-1; ++i) {
		getMinimum(&from, &to, visited, graph);
		mst[from][to] = graph[from][to];
		mst[to][from] = graph[to][from];
		visited[to] = 1;
	}

	return;
}

// creates a graph connecting all odd degree verticies
void TSP::oddDegree(int graph[N][N], int degree[N], int oddDegree[N][N]) {
	
	// initially sets all values in adjacency matrix to infinite
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			oddDegree[i][j] = I;
		}
	}

	for(int i = 0; i < N; ++i) {
		// checks if current vertex has an odd degree
		if(degree[i] % 2 == 1) {
			for(int j = 0; j < N; ++j) {
				// checks if pssible next vertex also has odd degree
				if(degree[j] % 2 == 1) {
					// connects verticies
					oddDegree[i][j] = graph[i][j];
					oddDegree[j][i] = graph[j][i];
				}
			}
		}
	}

	return;
}

// searches for the smallest weight that connects a visited to an unvisited vertex
void TSP::getMinimum(int *from, int *to, int visited[N], int graph[N][N]) {
	int min = I;

	// i represents the current node
	for(int i = 0; i < N; ++i) {
		// j represents the possible nest node in the MST
		for(int j = 0; j < N; ++j) {
			if(visited[i] == 1 && visited[j] == 0 && graph[i][j] < min) {
				min = graph[i][j];
				*from = i;
				*to = j;
			}
		}
	}
	return;
}
