#include <stdio.h>
#include <stdlib.h>

#define VERTEX_MAX 3000
#define EDGE_MAX   3000
#define DIST_MIN 0xffff

unsigned int G1[VERTEX_MAX][VERTEX_MAX] = {0};
unsigned int G2[VERTEX_MAX][VERTEX_MAX] = {0};


/** nV: number of the vertices 
 *
 *  s : source vertex .*/

int min (int s, unsigned int nV, unsigned int *visit, unsigned int *dist)
{
    unsigned int i, minDist = 0xffff;
    for (i=1;i<=nV;i++)
    {
        if ((visit[i] == 0) && (dist[i] <= minDist ))
        {
            minDist = dist[i];
            s = i; 
        }
    }
    return s;
}

void printSol (unsigned int *dist, unsigned int nV)
{
    unsigned int i;
    printf ("Vertex\tDistance\n");
    for (i=1;i<=nV;i++)
        printf ("%u\t%u\n",i, dist[i]);
}

void dijkstra (unsigned int nV, int s)
{
    unsigned int i , j, u, v;
    unsigned int *visited = calloc (1, sizeof (int));
    unsigned int *dist = calloc (nV, sizeof (int));

    /** set distances as max and visited as zero */
    for (i=1;i<=nV;i++)
    {
        visited[i] = 0;
        dist[i] = DIST_MIN;
    }

    /** mark distance of source vertex from itself as zero */
    dist[s] = 0;

    /** Run 1st loop to calculate shortest path for all vertices using source as source 
      * Run 2nd loop for neighbors for the vertex selected above */
    for (i=1; i<=nV;i++)
    {
        /** Select the  vertex with min distance */
        u = min(s, nV, visited, dist);
        visited[u] = 1;
        //printf ("min is %u\n",u);

        /** traverse the graph for that particular vertex neighbors */
        for (v=1;v<=nV;v++)
        {
            if ((visited[v]==0) && (G1[u][v] != 0) 
                        && (dist[u] != DIST_MIN) 
                        && (dist[u] + G1[u][v] < dist[v]))
                dist[v] = dist[u] + G1[u][v];
                //printf ("vertex %u, dist %u\n",v, dist[v]);
        }

    }


    printSol(dist, nV);
}

void main ()
{
    unsigned int nV, nE, i = 0, j, k, s, d, ac, tpc ;
    scanf ("%u %u", &nV, &nE);
    while (i++<nE)
    {
        scanf ("%u %u %u %u",&s, &d, &ac, &tpc);
        G1[s][d] = ac;
        G2[s][d] = tpc;
    }
    scanf ("%u %u", &s, &d);
    dijkstra (nV, s);
    return;
}
