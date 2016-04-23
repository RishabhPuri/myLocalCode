#include <stdio.h>

void main ()
{
  char str1[10] = "01010";
  //char *str1 = NULL;
  //str1 = _str1;
  int len = strlen (str1);
  int i;
  printf ("%s   ",str1);
  for (i=0;i<len+3;i++)
     str1[i] = '0'+ str1[i];
 
  char *p = "27";
  int k=0;
  char c = 27;
  while (*p)
  {
     k = (k<<3)+(k<<1) + (*p) - '0';
     printf ("%d\n",k);
     p++; 
  }
  printf ("%s   %d",str1, k);
}
