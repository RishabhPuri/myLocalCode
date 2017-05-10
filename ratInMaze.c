#include <stdio.h>

/*
 * Input: 2,1,6,5  
 * Output: 4
 * (2,1)->(4,2)->(6,3)->(8,4)->(6,5)
 * (2,1)->(4,2)->(6,3)->(4,4)->(6,5)
 * (2,1)->(1,3)->(3,4)->(4,6)->(6,5)
 * (2,1)->(3,3)->(4,5)->(5,7)->(6,5)
 *
 * 8
 * 7
 * 6
 * 5          x
 * 4          |
 * 3          |
 * 2          |
 * 1  x       | 
 *  1 2 3 4 5 6 7 8  
 * 
 * Input: 6,6,5,5
 * output: 2
 * (6,6)->(4,7)->(5,5)
 * (6,6)->(8,7)->(6,8)->(4,7)->(5,5)
 * (6,6)->(7,4)->(5,5)
 * (6,6)->(4,5)->(5,3)->(7,4)->(5,5)
 *
 * */

int getStepCount (int currRow, currCol, int destRow, int destCol)
{
    solveKtUtil (currRow, currCol, dest);
}

// driver program
void main ()
{
    int output = 0;
    int ip1, ip2, ip3, ip4;
    scanf("%d", &ip1);
    scanf("%d", &ip2);
    scanf("%d", &ip3);
    scanf("%d", &ip4);

    printf ("%d", getStepCount(ip1, ip2, ip3, ip4);
    return;
}
