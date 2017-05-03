#include "Qlist.h"

typedef struct _G {
  unsigned int N;
  qNode **alist;
} G;

unsigned int countIndeg (qNode *ptr)
{
  if ( !ptr)
    return 0;

  return 1 + countIndeg(ptr->next);
}

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

void topSort (G *g)
{
  int *inDeg = calloc (g->N, sizeof(int));

  unsigned int i;
 
  Q *q = initQ(g->N);
  Q *topSort = initQ(g->N);

  qNode *temp = 0;
   
  for (i=0;i<g->N;i++)
  {
    temp  = g->alist[i];
    while (temp)
    {
      inDeg[temp->data]++;
      temp = temp->next;
    }
  }

  for (i=0;i<g->N;i++)
  {
    if (inDeg[i] == 0)
      enQ (q, i);
  }

  unsigned int u = 0, v = 0, count = 0;
  while ( false == isEmpty (q))
  {
    u = deQ (q);
    enQ(topSort, u);
    printf ("Process %d \n",u);
    
    qNode *temp = g->alist[u];
    while (temp)
    {
      if (0 == --inDeg[temp->data])
        enQ(q, temp->data);
      temp = temp->next;
      count++; 
    }
  
  }

  if (count != g->N)
  {
    printf ("we have a cycle \n");
    return ;
  }

  for (i=0;i<g->N;i++)
    printf (" %d", deQ(topSort));
}


void main ()
{
  G *g = initGraph (6);
  addEdge (g,5 ,2 );
  addEdge (g,5 ,0 );
  addEdge (g,4 ,0 );
  addEdge (g,4 ,1 );
  addEdge (g,2 ,3 );
  addEdge (g,3 ,1 );
  topSort (g);
}
