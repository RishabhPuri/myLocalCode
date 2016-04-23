#include <stdio.h>

void main ()
{
   int d = 8000;
   int a  = 0;
   a = d & 0xfffe000;
   printf ("[%s] a %d \n",__FUNCTION__ , a);

}
