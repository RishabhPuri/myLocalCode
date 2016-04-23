#include <stdio.h>

void main () 
{
  char a[6] = {1,2,3,4,5,6};
  char b[6] = {0};
  int i;
#if 0
  int *d = NULL;
  d = a;
  int *target = NULL; 
  target = b;
  *target = *d;
  b[4] = a[4];
  b[5] = a[5];
  for (i=0; i<6; i++) 
     printf ("[%s] %d \n",__FUNCTION__, b[i]);
#endif
  *(int *)b = *(int *)a;
#if 0
  b[4] = a[4];
  b[5] = a[5];
#endif
  *(unsigned short *)&b[4] = *(unsigned short *)&a[4];
  for (i=0; i<6; i++) 
     printf ("[%s] %d \n",__FUNCTION__, b[i]);
}
