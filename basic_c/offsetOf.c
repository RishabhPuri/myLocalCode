#include <stdio.h>

typedef struct node {
  int a;
  int b;
  int c:1;
  char d:5;
  float f;
  double e;
  char g:1;
} Node;

#define mysizeof(n)  (char*)(&n+1)-(char*)&n
#define myOffset(type, var)  ((size_t) ((char*)&((type*)0->var)-(char *)((type*)0)))

void main ()
{
   Node *n = NULL;
   Node nd;
   printf ("My sizeof the struct node is %d", mysizeof(n));
   printf ("sizeof the struct node is %d", sizeof(n));
   printf ("My sizeof the struct node is %d", mysizeof(nd));
   printf ("sizeof the struct node is %d", sizeof(nd));
   printf ("offset of c in the struct node is %d", myOffset(n, a));
}
