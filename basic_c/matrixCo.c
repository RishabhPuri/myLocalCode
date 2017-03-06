#include <stdio.h>

int arr[1000][1000];
int aux[1000][1000];

int main()
{
    int row, col, i, j, q, qrow, qcol;
    
    scanf ("%u %u", &row, &col);
    
    for (i=0;i<row;i++)
        for (j=0;j<col;j++)
            aux[i][j] = 0;
    
    /** preprocess */
    for (i=0;i<row;i++)
        for (j=0;j<col;j++)
        {
            scanf ("%u",&arr[i][j]);
            if ((i>0)&&(j==0))
                aux[i][j] = aux[i-1][col] + arr[i][j];
            else
                aux[i][j] += arr[i][j];
        }

    
    scanf ("%u", q);   
    while (q--)
    {   
        scanf ("%u %u", qrow, qcol);
        printf ("%u", aux[qrow][qcol]);
    }   
 
}


