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
    unsigned int i, minDist = 0;
    for (i=0;i<=nV;i++)
    {
        if ((visit[i] == 1) && (dist[i] <= minDist ))
            minDist = dist[i];
    }
    return i;
}

void printSol (unsigned int *dist, unsigned int nV)
{
    unsigned int i;
    printf ("Vertex/tDistance\n");
    for (i=0;i<=nV;i++)
        printf ("%u/t%u\n",nV, dist[i]);
}

void dijkstra (unsigned int nV, int s)
{
    unsigned int i , j ;
    unsigned int *visited = calloc (1, sizeof (int));
    unsigned int *dist = calloc (nV, sizeof (int));

    /** set distances as max and visited as zero */
    for (i=0;i<=nV;i++)
    {
        visited[i] = 0;
        dist[i] = DIST_MIN;
    }

    /** mark distance of source vertex from itself as zero */
    dist[s] = 0;

    /** Run 1st loop to calculate shortest path for all vertices using source as source 
      * Run 2nd loop for neighbors for the vertex selected above */
    for (i=0; i<=nV;i++)
    {
        /** Select the  vertex with min distance */
        unsigned int tSource = min(s, nV, visited, dist);
        visited[tSource] =  1;

        /** traverse the graph for that particular vertex neighbors */
        for (j=0;j<=nV;j++)
        {
            if ((visited[j]!=0) && (G1[tSource][j] != 0) 
                        && (dist[tSource] != DIST_MIN) 
                        && (dist[tSource] + G1[tSource][j] < DIST_MIN))
                dist[j] = dist[tSource] + G1[tSource][j];
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
