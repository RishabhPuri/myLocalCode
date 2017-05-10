#include <stdio.h>

#define N 8
int sol[N][N];

void printSol ()
{
    unsigned int i,j;
    for (i=0;i<N;i++)
        for(j=0;j<N;j++)
            printf ("%d",sol[i][j]);
        printf ("\n");
}

unsigned int isSafe (int rowN, int colN, int sol[N][N])
{
    if ((rowN >= 0) && (rowN <N) && (colN >=0) && (colN <N) && sol[rowN][colN] == -1)
        return 1;
    else 
        return 0;
}

unsigned int solveKtUtil (unsigned int currRow, unsigned int currCol, unsigned int moveCount)
{
    unsigned int ri[]   = {1, -1, -2, -2, -1,  1, -2, 2};
    unsigned int coli[] = {2,  2,  1, -1, -2, -2, -1, 1};    
    
    if (moveCount == N*N)
        return 1;

    unsigned int i,j, rowN, colN;
    for (i=0;i<8;i++)
    {
        rowN = currRow + ri[i];
        colN = currCol + coli[i];
    
        if (isSafe (rowN, colN, sol) == 1)
        {
            sol[rowN][colN] = moveCount;
            if (solveKtUtil (rowN, colN, moveCount+1) == 1)
                return 1;
            else
                sol[rowN][colN] = -1;
        }
    }    
    return 0;
}

void solveKt ()
{
    unsigned int i,j;

    for (i=0;i<8;i++)
        for (j=0;j<8;j++)
            sol[i][j] = -1;

    if (solveKtUtil (0, 0, 0) ==  0)
    {
        printf ("no solution \n");
    }
    else
        printSol();
}


void main ()
{
    solveKt();
}
