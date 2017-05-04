#include "StackList.h"
#include "Qlist.h"

typedef struct _G {
  qNode **alist;
  unsigned int N;
} G;


G *initGraph (int n)
{
  G *temp = calloc (1, sizeof (G));
  temp->N = n;
  temp->alist = calloc (n, sizeof (void *));
  return temp;
}

void addEdge (G *g, int u, int v)
{
  qNode *temp = g->alist[u];
 
  if (g->alist[u] == 0x0)
    g->alist[u] = newNode (v);
  else
  { 
    while (temp->next)
      temp = temp->next;

    temp->next = newNode (v);
  }
}

void dfsUtil (G *g, int v, unsigned int *visit)
{
  qNode *temp = g->alist[v];
  visit[v] = 1;
  printf (" %d",v);

  if (!temp)
    return ;
  
  while (temp->next)
  {
    dfsUtil(g, temp->next->data, visit);
    temp = temp->next;
  } 
  return ;
}

void Dfs (G *g)
{
  unsigned int i;
  unsigned int *visit = 0x0;
  visit = calloc (g->N, sizeof(int));
  for (i=0;i<g->N;i++)  
    visit[i] = 0;

  for (i=0;i<g->N;i++)
    if (visit[i] == 0)
      dfsUtil (g, i, visit); 
}

void main ()
{
  G *g = initGraph (4);
  addEdge(g, 0, 1);
  addEdge(g, 0, 2);
  addEdge(g, 1, 2);
  addEdge(g, 2, 0);
  addEdge(g, 2, 3);
  addEdge(g, 3, 3);

  Dfs(g);
}
