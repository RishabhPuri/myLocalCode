#include <stdio.h>
struct emp {
   int a;
   char x[0];
   int c;
};

void main ()
{
  struct emp e;
  printf ("%d",sizeof (e));   
}
