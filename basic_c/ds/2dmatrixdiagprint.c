 : 2D integer array 
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 * 
 * @Output 2D int array. You need to malloc memory. Fill in len1 as row, and first entry in result array must be size of that row.  
 */
int ** diagonal(int** A, int n11, int n12, int *len1) 
{
    int *arr = malloc (n11*n12*sizeof(int));
    *A = arr;
    int i, j, row, col;
    for (i=0;i<n11;i++)
    {
        for (j=0;j<n12;j++)
        {
            if (j==0 && i==0)
            {
                //printf ("%d\n",*(*(A+i)+j));
                printf ("%d\n",A[i][j]);
            }
            else if (i==0 && j>0)
            {
                row = i; col = j;
                for (row = 0; row <=j && col >=0 ; row ++)
                {
                    //printf ("%d ",*(*(A+row)+col));
                    printf ("%d ",A[row][col]);
                    col--;
                }
                printf ("\n");
            }
            else if (i>0 && j==(n12-1))
            {
                row = i; col = j;
                for (row = 0; row <=j && col >= 0; row ++)
                {
                    //printf ("%d",*(*(A+row)+col));
                    printf ("%d",A[row][col]);
                    col--;
                }
                printf ("\n");
            }
            
        }
    }
    return A;
}

