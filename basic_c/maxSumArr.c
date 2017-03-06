#include <stdlib.h>
#include <stdio.h>

int maxSubArrSum (int *arr, int count)
{
    int currMax = 0, finalMax = 0, start = 0, end = 0, i, j = 0, finalSum = 0;
    
    for (i=0;i<count;i++)
    {
        currMax += arr[i];

        if (finalMax < currMax)
        {
            finalMax = currMax;
            start = j;
            end = i;
        }
        else  if (currMax < 0)
        {
            j = i+1;
            currMax = 0;
        }
    }
    
    printf ("Max Sum %d, start %d, end %d\n", finalMax, start, end);
    return 0;
}


void main ()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
 
    maxSubArrSum (arr, sizeof(arr)/sizeof(arr[0]));   
}
