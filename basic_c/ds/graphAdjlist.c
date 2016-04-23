#include <stdio.h>

typedef struct AdjNode {
	int dest;
	struct AdjNode *next;
} AdjNode;

typedef struct AdjList {
	AdjNode *head;
} AdjList;

typedef struct Graph {
	int n;
	AdjList *array;
} Graph;

Graph *initGraph (int n);
AdjNode *newNode (int dest);
void addEdge (Graph *g, int src, int dest);
void printGraph (Graph *g);


Graph *initGraph (int n)
{
	int i;
	Graph *temp = calloc (1, sizeof (Graph));
	temp->n = n;
	temp->array =  calloc (n, sizeof (AdjList));
	for (i=0; i<n; ++i)
	{
		temp->array[i].head = NULL;	
	}
	return temp;
}

AdjNode *newNode (int dest)
{
	AdjNode *temp = calloc (1, sizeof (AdjNode));
	temp->dest =  dest;
	temp->next = NULL;
	return temp;
}

void addEdge (Graph *g, int src, int dest)
{
	// add from src to dest 
	AdjNode *temp = newNode (dest);
	temp->next  =  g->array[src].head;
	g->array[src].head = temp;

	// add from dest to src as graph is undirected 
	temp = newNode (src);
	temp->next = g->array[dest].head;
	g->array[dest].head = temp;
}

void printGraph (Graph *g)
{
	int i ;
	AdjNode *ptr = NULL;
	for (i = 0; i<g->n; i++)
	{
		ptr = g->array[i].head;
		while (ptr)
		{
			printf ("%d->",ptr->dest);
			ptr = ptr->next;
		}
		printf ("\n");
	}
}


void main ()
{
	Graph *g = NULL;
		
	g = initGraph (5);
	
    addEdge(g, 0, 1);
    addEdge(g, 0, 4);
    addEdge(g, 1, 2);
    addEdge(g, 1, 3);
    addEdge(g, 1, 4);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
 
    // print the adjacency list representation of the above graph
    printGraph(g);
    
    return 0;	
}
