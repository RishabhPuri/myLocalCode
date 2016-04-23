#include <stdio.h>
/**
 * Solve the problem using disjoint set data structures
 * Problem is to find the cycle in graph 
 * now a graph is represented by a pair of vertices and edges
 * So let's define a graph
 * */
typedef struct _edge {
	// src vertex and destination vertex
	int src, dest ;
} edge

typedef struct graph {
	// V = #of vertices, E = #of edges
	int V, E;
	edge *e;
}G;

/** To use disjoint set , we use union-by-rank and path compression 
 * on disjoint set forests 
 * A disjoint set forests is a collection of trees rooted at a node 
 * At init, each root is a representative and points to itself 
 * To use union-by-rank heuristics we need to maintain rank in each node 
 * Also since ranks are used to update parent indices , so need to maintain parent as well*/

typedef struct subset {
	int parent ;
	int rank ;
} ss;

void main ()
{

}
