#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition (int*a , int start, int end)
{
  /* select pivot 
   *   start i from first element ,same as pivot 
   *   start j = j + 1, i.e. pts outside the aray 
   * Algo:
   *   keep doing i=i++ as long as a[i] < pivot
   *   keep doing j=j-- as long as a[j] > pivot
   *   int a[] = {5,3,1,9,8,2,4,7,2};
   *          1 2 3 4 5 8 9 7 
   *   EG: if pivot is 3 and the other array elements is just 4
   *   so a[i] (3) <= 3 i++ becomes 4
   *      also a[j] (4) > 3 j-- becomes 3
   *      so swap j with pivot means 3 with 3 ... 
   *   so thats y in partition the input elements might change
   *  so save it and create new variables  
   * */
 

  int i=start; int j=end; 
  /* chose the first element as pivot */
  int pivot = a[i];
  /* start from the next element */
  while (i<j)
  {
    while (a[i] <= pivot) 
      i++;
    while (a[j] > pivot) 
      j--;
    
    if (i<j)
     swap ((a+i), (a+j));
  } 
  
  swap ((a+j), (a+start));
  return j;
}

void qSort (int *a, int i, int j)
{
  printArray (a,9);
  int m ;
  if (i<j)
  {
    m = partition (a, i, j);
    qSort (a, i, m-1); 
    qSort (a, m+1, j); 
  }
}

void printArray (int *a, int len)
{
  int i=0;
  for (i=0;i<len;i++)
  {
    printf ("%d ",a[i]);
  }
    printf ("\n ");
}

int kthMin (int *a, int start, int end, int k)
{
  int m;
  if (start < end)
  {
    m = partition (a, start, end);
    if ( m > k) 
    {
       printf ("m %d > k %d \n",m,k);
       /* k is in left subarray */
       kthMin (a, start, m-1, k);
    }
    else if (m < k)
    { 
       printf ("m %d < k %d \n",m,k);
       kthMin (a, m+1, end, k);
    }
    else if (m==k)
     return a[m];
  }
  return 0;
}

void main ()
{
  int a[] = {5,3,1,9,8,2,4,7,2};
  int size = sizeof (a)/sizeof (a[0]);
  int ret = 0;
  int k = 7;
  printArray (a,size);
#if 0
  qSort (a,0,size-1);
  printArray (a,size);
#endif
#if 1
  /* find kth(3) smallest element in array */
  ret = kthMin (a, 0, size-1, k-1); 
  printf ("Kth element is %d \n",ret);
#endif
}
