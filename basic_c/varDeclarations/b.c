#include "test.h"

int a;
void foo ()
{
  a++;
  printf ("[%s] &b %p \n",__FUNCTION__, b);
  printf ("[%s] b %c \n",__FUNCTION__, b);
  b = 'a';
  printf ("[%s] &b %p \n",__FUNCTION__, b);
  printf ("[%s] b %c \n",__FUNCTION__, b);
}
