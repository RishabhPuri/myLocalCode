#include "Qlist.h"
qNode *newNode (unsigned int key)
{
  qNode *temp = calloc (1, sizeof (qNode));
  temp->data  = key ;
  temp->next = 0x0;
  return temp;
}

Q* initQ(unsigned int capacity)
{
  Q * temp = calloc (1, sizeof (Q));
  temp->front = temp->rear = 0x0;
  temp->maxCap = capacity;
  return temp;
}

void enQ (Q *q, unsigned int data)
{
  if (q->rear == 0x0)
  {
    q->rear = newNode (data);
    q->front = q->rear;
    q->currCount++;
  } 
  else
  {
    if (q->currCount == q->maxCap)
      return ; //overflow
    
    q->rear->next = newNode (data);
    q->rear = q->rear->next;
    q->currCount++;
  }
  return ;
}

unsigned int deQ (Q *q)
{
  if (q->front == 0x0)
    return 0xffffffff;  // underflow
  
  unsigned int key  = q->front->data;
  qNode *tNode = q->front; 
  if (q->front == q->rear) // last node
    q->front = q->rear = 0x0;  
  q->front = tNode->next;
  free (tNode);
  tNode = 0x0;
  return key;
}

bool isEmpty (Q *q)
{
  return (q->rear == 0x0)?true:false;
}

void delQ (Q *q)
{
  if (q)
    free (q);
}

#if 0
void main ()
{
     Q *q = initQ(10);
    enQ(q, 10);
    enQ(q, 20);
    deQ(q);
    deQ(q);
    enQ(q, 30);
    enQ(q, 40);
    enQ(q, 50);
    printf("Dequeued item is %d", deQ(q));
    delQ(q);
    return ;

}
#endif
