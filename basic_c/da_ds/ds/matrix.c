#include <stdio.h>
#include <stdlib.h>

#if 0
void printArray (int **a, int r, int c)
{
  int i,j;
  for (i=0;i<r;i++)
  {
    for (j=0;j<c;j++)
      printf("%d ",a[i][j]);
  }
  printf ("\n");
}
#endif

void main ()
{
  int r1,c1,r2,c2,r3,c3 = 0;
  int i,j,k, sum;
  int a[10][10], b[10][10], result[10][10], transpose[10][10];
  
  printf ("Enter the first matrix row and column \n");
  scanf ("%d  %d", &r1, &c1);
  printf ("Enter the second matrix row and column \n");
  scanf ("%d  %d", &r2, &c2);

  if (c1!=r2)
  {
    printf ("Matrix Multiplication is not possible \n"); 
    return ;
  }
 
  printf ("Enter elements for first matrix\n");
  for (i=0;i<r1;i++)
  {
    for (j=0;j<c1;j++)
    {
      scanf ("%d",&a[i][j]);
    }
  }
  
  printf ("Enter elements for second matrix\n");
  for (i=0;i<r2;i++)
  {
    for (j=0;j<c2;j++)
    {
      scanf ("%d",&b[i][j]);
    }
  }
 
  printf ("Firs matrix is \n"); 
  for (i=0;i<r1;i++)
  {
    for (j=0;j<c1;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf ("\n");
  }
  
  printf ("second matrix is \n"); 
  for (i=0;i<r2;i++)
  {
    for (j=0;j<c2;j++)
    {
      printf ("%d ",b[i][j]);
    }
    printf ("\n");
  }

  /* matri multiplication rule is 
 *  A (first row) * b (first column)
 *  A (first row) * b (second column)
 *  
 *  for columns !=0 A[frstRow] * b(columns--)*/  
  for (i=0;i<r1;i++)     // ----> first matrix row 
  {
    for (j=0;j<c2;j++)   // ---> second matrix column
    {
      result[i][j] = 0; 
      for (k=0;k<r2;k++)  // ----> second matrix row 
        result[i][j]+= (a[i][k] * a[k][j]);
    }
  }

  printf ("Third Matrix is \n");
  for (i=0;i<r1;i++)
  {
    for (j=0;j<c2;j++)
    {
      printf ("%d ",result[i][j]);
    }
    printf ("\n");
  }
  
  printf ("Transpose of final matrix is \n");
  for (i=0;i<r1;i++)
  {
    for (j=0;j<c1;j++)
    {
      transpose[j][i] = result[i][j];
    }
  }
  for (i=0;i<r1;i++)
  {
    for (j=0;j<c1;j++)
    {
      printf ("%d ",transpose[i][j]);
    }
    printf ("\n");
  }
}
