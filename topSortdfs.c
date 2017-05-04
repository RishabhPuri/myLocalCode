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

void topSortDfsUtil (G *g, int v, int *visit, stack *s)
{
  qNode *temp = g->alist[v];
  visit[v]  = 1;
  
  if (temp)
    while (temp->next)
    {
      if (visit[temp->next->data] == 0)
        topSortDfsUtil(g, temp->next->data, visit, s); 
      temp = temp->next;
    }
  
  push(s, v); 
}

void topSort (G *g)
{
  int *visit  =  calloc (g->N, sizeof (int));
  unsigned int i;
  for (i=0;i<g->N;i++)
    visit[i] = 0;

  stack *s = initStack ();

  for (i=0;i<g->N;i++)
  {
    if (visit[i] == 0)
      topSortDfsUtil (g, i, visit, s);
  }

  while (false == isStackEmpty (s))
    printf ("%d ", pop(s));
}


void main ()
{
  G *g = initGraph (6);
  addEdge(g, 5, 2);
  addEdge(g, 5, 0);
  addEdge(g, 4, 0);
  addEdge(g, 4, 1);
  addEdge(g, 2, 3);
  addEdge(g, 3, 1);

  topSort(g);
}
