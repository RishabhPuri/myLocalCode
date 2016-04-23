#include "test.h"

void main ()
{
  foo ();
  a++;
  printf ("a %d\n",a); 
  printf ("[%s]b %c\n", __FUNCTION__, b);
  printf ("[%s]b %p\n", __FUNCTION__, &b);
}
