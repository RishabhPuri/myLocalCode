#include <stdio.h>

typedef struct _list {
    unsigned int v;
    struct _list *next; 
} listNode;


typedef struct _Graph {
    listNode **adjList;
 } G;

listNode *newNode (unsigned int v)
{
    listNode *temp = calloc (1, sizeof (listNode));
    temp->v = v;
    temp->next = 0x0;
    return temp;
}

G *initGraph (unsigned int N)
{
    G *temp = calloc (1, sizeof (G));
    listNode **templist = calloc (N, sizeof(void*)); 
    temp->adjList = templist;
    return temp;
}

void addEdge (G* g, unsigned int source, unsigned int dest)
{
    listNode *temp  = g->adjList[source];
    while (temp)
        temp = temp->next;
    
    temp = newNode(dest);
    return;
}


void delGraph (G* g)
{
    if (g)
    {
        if (g->adjList)
            free (adjList);
        free (g);
    }
    return ;
}

void bfs (G *g, unsigned int N, unsigned int source)
{
    unsigned char *visit = calloc (N, sizeof (char));
    unsigned int *dist   = calloc (N, sizeof(int));
    unsigned int i, u, v;
    for (i=0;i<N;i++)
        visit[i] = 0;
    
    for (i=0;i<N;i++)
        dist[i] = 0xfffff;

    Q *q = initQ(N+1);
    
    visit[source] = 1;
    enQ(q, source); 

    while (!isEmpty(q))
    {
        u = deq(q);
        printf (" %d",u);
        listNode *temp = g->adjList[u];
        // visit all neighbors
        while (temp)
        {
            if (visit[temp->v] == 0)
            {
                visit[temp->v] = 1;
                enQ(q, temp->v); 
            }       
            temp = temp->next;
        }
    }
    delQ (q);
}

void main ()
{
    G *g = initGraph(4);
    addEdge(g, 0, 1);
    addEdge(g, 0, 2);
    addEdge(g, 1, 2);
    addEdge(g, 2, 0);
    addEdge(g, 2, 3);
    addEdge(g, 3, 3);
    bfs (g, 4, 2);
    return 0;
}   
