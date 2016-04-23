#include <stdio.h>
#include <limits.h>

int bin_seq (int *fib, int size, int key)
{
  int start, end, middle;
  start = 0;
  end   = size;
  middle = (start + end )/2;
  while (start < end)
  {
    if (fib[middle] < key)
    { 
      start = middle+1;
      middle = (start+end)/2;
    }
	else if (fib[middle] > key)
	{
      end = middle;
	  middle = (start+end)/2;
	}
	else return middle;
  }
}

int fib_s (int *arr, int size, int key)
{
  int k; 
  const static int Fib[47+1]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
             10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578,
             5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296,
             433494437, 701408733, 1134903170, 1836311903, INT_MAX};
  k = bin_seq (Fib, sizeof(Fib)/sizeof(Fib[0]), size);
  printf ("fib k is %d \n",k);

  int offs, idx;
  for (offs=0;k>0;)
  {
    idx = offs+Fib[--k];
    if (idx>=size|| key<arr[idx])
    {
      printf ("Out of bounds index %u\n",idx);
      continue;
    }
	else if (key>arr[idx]) 
    {
      offs=idx;
      --k;	
      printf ("new offs %d and k %d \n",offs, k);
    }
	else
	{
      printf ("found offs %d k %d  idx %d \n",offs, k, idx);
	  return idx;
    }
  }
  
}


void main ()
{
  int arr[] = {1, 4, 5, 7, 9, 11, 13, 16, 18, 20, 25, 27, 30, 32, 33, 36, 39, 41, 44, 47, 51, 53, 55};
  int size  = sizeof(arr)/sizeof(arr[0]);
  int key   = 18;
  int index = fib_s (arr, size, key);
}
