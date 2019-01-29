#include "TSP.h"

// utility test function
// prints matrix for testing purposes
void printMatrix(int matrix[N][N]) {
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(matrix[i][j] == I) {
				cout << " - ";
			}
			else {
				if(matrix[i][j] >= 10) 
					cout << matrix[i][j] << " ";
				else 
					cout << " " << matrix[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

// counts he number of edges in a given graph
int edgeCount(int graph[N][N], bool complete) {
	if(complete) 
		return (N * (N - 1)) / 2; // if a complete graph, number of edgs is given by the formula
	
	int count = 0;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(graph[i][j] != I && j > i) // if there is an edge and it hasnt already been counted
				count++;
	return count;
}

// counts the number of verticies in a graph of arbitrary size
int vertexCount(int graph[N][N]) {
	int count = 0;

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(graph[i][j] != I) {
				count++;
				break;
			}
		}
	}

	return count;
}

// recursive fuction calculates an eulerian circuit i.e. every edge of the given graph is visited once
// uses a bactracking algorithm
bool eulerianCircuit(int graph[N][N], int v, int e, int edgeCount, int from[], int to[]) {
	
	// base case
	// if all edges have been visited
	// and the circuit starts and ends on the same vertex
	if(e == edgeCount && from[0] == to[edgeCount - 1])
		return true;

	for(int i = 0; i < N; ++i) { // iterates through all possible connections from current vertex, v
		if(graph[v][i] != I && !containsEdge(from, to, v, i, edgeCount)) { // if a connection can be made and the edge hasn't been visited
			from[e] = v; // v represents current vertex
			to[e] = i; // i represents the next vertex in the circuit
			if(eulerianCircuit(graph, i, ++e, edgeCount, from, to))
				return true;
			
			e--; // resets values if no solution exists from the last position, backtracks to the next possible value
		}
	}

	return false;
}

// recursive function finds a perfect match in a graph
// i.e. every vertex is connected only once
// TODO minimum weight
bool perfectMatch(int graph[N][N], int v, int vertexCount, int visited[N], int match[N][N]) {
	
	/*
	 * Logically, it should be checked that the vertex count is even as perfect match can only be made with an even number of verticies.
	 * However, we are given a graph representing a subgraph of verticies with odd degree. It is mathematically proven that the number
	 * of verticies with odd degree in a graph will always be even.
	 */

	// base case
	if(v == vertexCount)
		return true;

	// recursive case
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			// trys arbitrary connection
			if(graph[i][j] != I && visited[i] == 0 && visited[j] == 0) {
				visited[i] = 1;
				visited[j] = 1;
				match[i][j] = graph[i][j];
				match[j][i] = graph[j][i];
				v += 2;

				// returns true if a solution is found from current connection
				if(perfectMatch(graph, v, vertexCount, visited, match)) // if solution exists from current point
					return true;

				// reset values if no solution is found
				v -= 2;
				visited[i] = 0;
				visited[j] = 0;
				match[i][j] = I;
				match[j][i] = I;
			}
		}
	}

	return false;
}

// combines two graphs
void combine(int graph1[N][N], int graph2[N][N]) {
	
	for(int i = 0; i < N; ++i)
		for(int j = 0 ; j < N; ++j)
			if(graph2[j][i] != I && graph1[j][i] == I)
				graph1[j][i] = graph2[j][i];
	return;
}

// calculatess the degree of each vertex in a given graph
void getVertexDegree(int graph[N][N], int degree[N]) {
	
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

// Function creates and returns a Minimum Spanning Tree (MST) in the form of an adjacency matrix
// Calculated using Prim's algorithm
void minimumSpanningTree(int graph[N][N], int mst[N][N]) {
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
void oddDegree(int graph[N][N], int degree[N], int oddDegree[N][N]) {
	
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

// removes similar edges in two different graphs
void removeCommonEdges(int graph1[N][N], int graph2[N][N]) {
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(graph1[i][j] == graph2[i][j]) 
				graph1[i][j] = I;
	return;	
}

// redirects path to avoid repeated verticies to create a hamiltonian circuit, i.e. the output of Christofides algorithm
void removeRepeatedVerticies(int graph[N][N], int from[], int to[], int edgeCount, int circuit[N][N]) {

	initialize(circuit);

	int visited[N];
	int pos = from[0]; // start at the beginning of the circuit

	for(int i = 0; i < edgeCount; ++i) {
		visited[pos] = 1;
		int f = from[i];
		int t = to[i];
		if(visited[t] == 1 && t != from[0]) { // if vertex has already been visited and its not the end of the circuit
			t = to[i + 1]; // skip to next vertex
			i++;
		}
		circuit[f][t] = graph[f][t];
		pos = t;
	}

	return;
}

// prints the path of a given circuit from a starting position
void printHamiltonianCircuit(int circuit[N][N], int pos) {

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(circuit[pos][j] != I) {
				cout << pos << " -> " << j << endl;
				pos = j; // moves to the next vertex
				break;
			}
		}
	}
	return;
}

// utility function
// checks if an edge is in a given set of edges
bool containsEdge(int from[], int to[], int f, int t, int edgeCount) {
	for(int i = 0; i < edgeCount; ++i)
		if((from[i] == f && to[i] == t) || (from[i] == t && to[i] == f)) 
			return true;

	return false;
}

// finds the next available node in a given graph
bool compare(int graph1[N][N], int graph2[N][N]) {
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j) 
			if(graph1[i][j] != graph2[i][j])
				return false;

	return true;
}

// searches for the smallest weight that connects a visited to an unvisited vertex
void getMinimum(int *from, int *to, int visited[N], int graph[N][N]) {
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

// initializes all values in a given adjacency matrix to infinite
void initialize(int graph[N][N]) {
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			graph[i][j] = I;
	return;
}
