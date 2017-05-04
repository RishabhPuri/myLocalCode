#include "StackList.h"

stack *initStack ()
{
  stack *temp = calloc (1, sizeof(stack));

  temp->top = 0x0;
  return temp;
}

sNode *newStNode (int data)
{
  sNode *temp = calloc (1, sizeof(sNode));
  temp->data = data;
  temp->next = 0x0;
  return temp;
}

void push (stack *s, int data)
{
  sNode *temp =  newStNode (data);
  sNode *pTop = s->top;
  temp->next = pTop;
  s->top = temp;
}

int pop (stack *s)
{
  if (s->top = 0x0)
    return -1 ;
  
  sNode *temp = s->top;
  s->top = temp->next;
  int key = temp->data;
  free (temp);
  return key;
}

int isStackEmpty (stack *s)
{
  return (s->top == 0x0) ? 1:0;
} 
