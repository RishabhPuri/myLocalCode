#include <stdio.h>
#include <stdlib.h>


void swap (char *a, char *b)
{
  char temp ;
  temp = *a;
  *a = *b;
  *b = temp;
}

void permute (char *a, int i, int end)
{
  int j=0;
  if (i==end) 
    printf ("%s\n",a);
  else {
    for (j=i; j<=end; j++)
    {
      swap ((a+i), (a+j));
      permute (a, i+1, end);
      swap ((a+i), (a+j));
    }
  }
}

void main ()
{
  char str[] = "ABCD";
  int len  = strlen (str);
  permute (str, 0, len-1);
  return; 
}
