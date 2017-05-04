
#include <stdio.h>
#include <stdlib.h>

typedef  enum{true, false}bool;

// q - front rear ptr
//
typedef struct _QNode {
  unsigned int data;
  struct _QNode *next;
}qNode;

typedef struct _Q {
  qNode *front, *rear;
  unsigned int maxCap;
  unsigned int currCount;
} Q; 



Q* initQ(unsigned int );
void enQ (Q *, unsigned int);
unsigned int deQ (Q *q);
bool isEmpty (Q *q);
void delQ (Q *q);
qNode *newNode (unsigned int );
