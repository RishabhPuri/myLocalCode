#include <stdlib.h>
#include <stdio.h>

typedef struct _bt {
   int data;
   struct _bt *left;
   struct _bt *right;
}bt; 

typedef struct slist {
   bt* node;
   struct slist *next;
}list;

typedef struct  _Q {
  list *head;
  list *tail; 
  list *ll;
}Q;
 
bt* addNode (int data);
void InOr (bt *root);
void rotate (bt *root);  

void initQ (Q **q);
void enqueue (Q *q, bt *data);
list* dequeue (Q *q);

void initQ (Q **q)
{
  if (*q) 
    (*q)->head = (*q)->tail = (*q)->ll  = NULL;  
  else
    *q = calloc (1, sizeof (q));
  return;
}

void enqueue (Q *q, bt* data)
{
  if (!data)  return;
  list *temp = NULL;
  temp  = calloc (1, sizeof (temp));
  //printf ("allocated %d bytes at address %p \n",sizeof(temp), temp);
  temp->node = data;
  temp->next = NULL;

  if (!q->ll) 
  {
    q->head = q->tail =  q->ll = temp;
  }
  else 
  {
    if (!q->head) 
      q->head = temp;

    q->tail->next = temp; 
    q->tail = q->tail->next;
  }
}

list* dequeue (Q *q)
{
  if (!q) return;
  
  list *temp = NULL;
  temp = q->head;
  if (q->head && q->head->next)
    q->head = q->head->next; 
  else
    q->head = NULL;
  return temp;
}

void BFS (bt *root, Q *q) 
{
  list *dq = NULL; 
  bt *temp = NULL;
  if (!root) return;

  enqueue (q, root);
  while (dq = dequeue (q))
  {
    temp = dq->node;
    printf ("%d ", temp->data); 
    enqueue (q, temp->left);
    enqueue (q, temp->right); 
    //printf ("Free %d bytes at address %p \n",sizeof (dq), dq);
    free (dq);
    dq = NULL;
  }
}

bt * addNode (int data)
{
  bt *temp = NULL;
  temp = calloc (1, sizeof (bt));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

void InOr (bt *root)
{
  if (!root) return;
  
  InOr(root->left);
  printf ("%d ",root->data);
  InOr(root->right);
}

bt *rotateLeft (bt *root) 
{ 
   bt *y = NULL;
   y = root->right;
   root->right = y->left;
   y->left = root; 
   return y;
}

void main ()
{
   bt *root = NULL; 
   Q *q = NULL;
   initQ (&q);
   root = addNode (4);
   root->left = addNode (3);
   root->right = addNode (6);
   root->right->left = addNode (5);
   root->right->right = addNode (7); 
   
   InOr (root);
   puts ("\n");
   BFS (root, q);
   root  = rotateLeft (root);
   puts ("\n");
   InOr (root);  
   puts ("\n");
   initQ (&q);
   BFS (root, q);
}
