#ifndef TSP_H
#define TSP_H

#define N 5   // size of graph
#define I 999 // infinite
#define U -1  // undefinded

#include <cstdlib>
#include <iostream>

using namespace std;	

/* returns true if the graphs are equal */
bool compare(int graph1[N][N], int graph2[N][N]);
/* checks if specified edge is in a given set of edges */
bool containsEdge(int from[], int to[], int f, int t, int edgeCount);
/* creates an Eulerian Circuit from a given graph */
bool eulerianCircuit(int graph[N][N], int v, int e, int edgeCount, int from[], int to[]);
/* calculates minimum cost perfect match for a given graph */
bool perfectMatch(int graph[N][N], int v, int vertexCount, int visited[N], int match[N][N]);

/* calculates and returns the number of edges in a given graph */
int edgeCount(int graph[N][N], bool complete);
/* retusn the ttal weight of a graph */
int getWeight(int graph[N][N]);
/* calculates and returns the number of verticies */
int vertexCount(int graph[N][N]);

/* combines two given graphs */
void combine(int graph1[N][N], int graph2[N][N]);
/* gets the smallest edge weight in a given adjacency matrix */
void getMinimum(int *from, int *to, int visited[N], int graph[N][N]);
/* function calculates the degree of each vertex */
void getVertexDegree(int graph[N][N], int degree[N]);
/* initialize all values to infinite */
void initialize(int graph[N][N]);
/* function creates an adjacency matrix representing a MST of a given graph */
void minimumSpanningTree(int graph[N][N], int mst[N][N]);
/* function creates a graph out of odd degree verticies */
void oddDegree(int graph[N][N], int degree[N], int oddDegree[N][N]);
/* removes all repeating verticies, directs path elsewhere */
void removeRepeatedVerticies(int graph[N][N], int from[], int to[], int edgeCount, int circuit[N][N]);
/* removes common edges between two graphs */
void removeCommonEdges(int graph1[N][N], int graph2[N][N]);
/* prints out the circuit from a given adjacency matrix, must be a hamiltonian circuit */
void printHamiltonianCircuit(int circuit[N][N], int pos);
/* function used for testing*/
void printMatrix(int matrix[N][N]);

#endif /* TSP_H */
