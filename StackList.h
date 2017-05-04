#include <stdio.h>
#include <stdlib.h>

typedef struct _stacknode {
  unsigned int data;
  struct _stacknode *next;
}sNode;

typedef struct _stack {
  sNode *top;  
}stack;

stack *initStack ();
void push (stack *s, int data);
int pop (stack *s);
int isStackEmpty(stack *);

