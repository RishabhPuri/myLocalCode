#include <stdio.h>
#include <stdlib.h>

#define LEN 11
/* Merge sort: 
 * 1. Divide the array into left and right subarrays - Divide 
 * 2. Sort the 2 subarrays - Conquer 
 * 3. merge the sorted arrays back - merge 
 * 4. NOT IN-PLACE sorting 
 * 5. Good for large data structures such as file sorting in disks 
 * 6. Complexity : O(nlogn) 
 * */

void swap (int, int);
void mergeSort (int *, int , int);
void merge (int *, int, int, int);
void printArray (int *, int);

void swap (int a, int b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}

void mergeSort (int *a, int start, int end)
{
  if (start == end ) return;
  int middle  = (start + end )/2;
  if (start < end ) 
  { 
    mergeSort (a, start, middle);
    mergeSort (a, middle+1, end);
    merge (a, start, middle, end);
  }
}

void merge (int *a, int start, int bridge, int end)
{
  int len =  end - start ;
  int *tempArr = calloc (len, sizeof (int));
  int *tempArr2 = calloc (len, sizeof (int));
  /* counter used for final merge operation */
  int i, j = 0;
  
  /*Step 1. Create temp array left */
  /*Step 2. Create temp array right */
  /*Step 3. start merge into parent array */


  /* Step 1*/
  for (i=0; i<bridge ; i++) {
    tempArr[i] = a[i]; 
  }

  /* Step 2*/
  for (i=bridge; i<end ; i++) {
   tempArr2[i] = a[i];
  }

  i = start; j=bridge;
  /* compare and merge back to parent */ 
  while (i<bridge && j<end) 
  {
    if (tempArr[i] < tempArr2[j])
    {
      /* merge back to parent node */
      a[i] = tempArr[i];
      i++;
    }
    else 
    {
      a[i] =  tempArr2[j];
      j++;
    }
  }
 
#if 0 
    while (i++==end) 
    {
      a[i] = tempArr[i];
    }
#endif
}

void printArray (int *a, int len)
{
  int i = 0;
  printf ("\n");
  for (i=0; i< len; i++)  
   printf ("%d ",a[i]);
}

void main ()
{
  int a[LEN] = {5, 1, 60, 34, 80, 3, 6, 17, 2, 12};
  int size = sizeof (a) / sizeof (a[0]);
  printArray (a, size);
  mergeSort (a, 1, size-1);
  printArray (a, size);
  return ;
}

