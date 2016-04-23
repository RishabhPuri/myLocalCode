#include <stdio.h>

int findMin (int *a, int start, int end)
{
   if (start > end ) return a[0];
   if (start == end) return a[start];
   

}

void main()
{
   int a[] = {2,1};
   int len  = sizeof a / sizeof (int);
   int min = 0;
   min = findMin (a, 0, (len-1));
   printf ("min element is %d",min);  
}
