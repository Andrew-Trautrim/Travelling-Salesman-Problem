# Travelling-Salesman-Problem
Program calculates an aproximation of the travelling salesman problem using Christofides algorithm.

The Travelling Salesman Problem (TSP) is a combinatorial problem posed in graph theory and is described as follows: a salesman must travel between N cities, order doesn't matter as long as he visites every city and ends in the city he started with. Each city is connected to every other city by a set weight; the weight representing the dificulty or "cost" of transversing that path. The problem lies in finding a path with the lowest possible cost. This is an NP-hard problem, a brute force solution would result in a complexity of (N-1)! In order to solve this problem in polynomial time, an aproximation is the most reasonable solution.  

Christofides algorithm is the best aproximate solution to the trading salesman problem known to date.  
Algorithms pseudocode:  
    Let G be a complete undirected weighted graph.  
    1. Create a minimum spanning tree T of G.  
    2. Let O be the set of vertices with odd degree in T. By the handshaking lemma, O has an even number of vertices.  
    3. Find a minimum-weight perfect matching M in the induced subgraph given by the vertices from O.  
    4. Combine the edges of M and T to form a connected multigraph H in which each vertex has even degree.  
    5. Form an Eulerian circuit in H.  
    6. Make the circuit found in previous step into a Hamiltonian circuit by skipping repeated vertices (shortcutting).  
    
My program does this by representing the given graph in an adjacency matrix

Input: Complete Undirected Wighted Graph - G  
<pre>
 - 37 51 50 46 
37  - 44 41 48 
51 44  - 28 33 
50 41 28  - 53 
46 48 33 53  - 
</pre>

Output  
<pre>
0 -> 1  
1 -> 3  
3 -> 2  
2 -> 4  
4 -> 0   
Weight: 139
</pre>
