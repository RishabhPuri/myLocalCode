#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define max3(a,b,c)   (a>b?(a>c?a:c):(b>c?b:c))

int kadane (int *arr, int row)
{
  int curr = 0, max = 0, i;

  for (i=0;i<row;i++)
  {
    curr = curr ^ arr[i];
    max = (curr > max ) ? curr : max;
  }
  return max;
}

int main(void)
{
    unsigned int N, M, i, j, col;
    scanf ("%u %u",&N, &M);
    unsigned int **arr = calloc (N, sizeof(*arr));
    arr[0] = calloc (N*M, sizeof(unsigned int));
    for (i=0;i<N;i++)
      arr[i] = arr[0] + i*M;

    for (i=0;i<N;i++)
      for (j=0;j<M;j++)
        scanf ("%u",&arr[i][j]);
    
    unsigned int max =0, curr = 0;
    unsigned int xorRes[N];
  
    /**       
    *  . . . .
    *  . . . . 
    *  . . . .
    *  . . . .
    *  
    *    lets implement kadane's extension to 2d matrix
    *
    *
    *
    */
    for (i=0;i<N;i++)
      xorRes[i] = 0;
    for (col=0;col<M;col++)
    {
      memset (xorRes, 0, sizeof(xorRes));

      for (j=col;j<M;j++)
      {
        for (i=0;i<N;i++)
          xorRes[i] = xorRes[i]^arr[i][j];
    
        curr = kadane (xorRes, N);

        max = (curr > max) ? curr : max;
      }
    }

#if 0

    for (i=0;i<N;i++)
    {
      for (col=0;col<M;col++)
      {
        for (j=col;j<M;j++)
        {
          curr = curr ^ arr[i][j];
          //curr = curr * arr[i][j];
          max = max3(curr, max, arr[i][j]);
        }
        printf ("MAX-ROW%d:%d %u\n", i+1,j, max);
      }

      if ( i == 0)
        xorRes[i] = xorRes[i] ^ max;
      else
        xorRes[i] = xorRes[i-1] ^ max;
    
      max = (xorRes[i] > max) ? xorRes[i] :  max;

      curr = 0;
    }

    for (i=0;i<N;i++)
      xorRes[i] = 0;

    curr = 0;
    for (i=0;i<M;i++)
    {
      for (col=0;col<N;col++)
      {
        for (j=col;j<N;j++)
        {
          //curr = curr ^ arr[i][j];
          curr = curr ^ arr[j][i];
          max = max3(curr, max, arr[j][i]);
        }
        printf ("MAX-COL %u", max);
      }

      if ( i == 0)
        xorRes[i] = xorRes[i] ^ max;
      else
        xorRes[i] = xorRes[i-1] ^ max;
    
      max = (xorRes[i] > max) ? xorRes[i] :  max;

      curr = 0;
    }
   
#endif
    printf ("%u\n", max);
    free (arr[0]);
    free (arr);
    return 0;

}
