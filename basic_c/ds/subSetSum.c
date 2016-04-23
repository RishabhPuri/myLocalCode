#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static int total_nodes ;

/** this is NP-complete problem and running time complexity is exponential N 
 *  We are going to solve this problem by Backtracking , generating all possible candidates for evaluation 
 *  Then we will optimize it with Branch & Bound or Pruning */

void printSubSet (int *tempArr, int tempArrIndex)
{
	int i = 0;
	for (i = 0; i < tempArrIndex;++i)
		printf ("%d ",tempArr[i]);
	printf ("\n");
}

void subSet_sum (int *arr, int size, int arrIndex, int *tempArr, int tempArrIndex, int currSum, int targetSum)
{
	total_nodes++;
	if (currSum == targetSum)
	{
		printSubSet (tempArr, tempArrIndex);

		if (arrIndex +1 < size && currSum - arr[arrIndex] + arr[arrIndex+1] <= targetSum)	
			subSet_sum (arr, size, arrIndex+1, tempArr, tempArrIndex-1, currSum-arr[arrIndex], targetSum);
	}
	else
	{
		int i = 0;
		if ((arrIndex < size) && (currSum <= targetSum))
		{
			for (i = arrIndex; i < size ; ++i)
			{
				tempArr[tempArrIndex] = arr[i];

				if (currSum + arr[i] <= targetSum)
					subSet_sum (arr, size, arrIndex+1, tempArr, tempArrIndex+1, currSum+arr[i], targetSum);
			}
		}
	}
}

void generateSubSet (int *arr, int size, int targetSum)
{
	int *tempArr = calloc(size, sizeof(int));
	int tempArrIndex = 0;
	int currSum  = 0;
	int arrIndex = 0;

	subSet_sum (arr, size, arrIndex, tempArr, tempArrIndex, currSum, targetSum);
}


void main ()
{
	int arr[23] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23};
	int size    = 23;
	int targetSum = 23;
#if 0
	int arr[5] = {1,2,3,4,5};
	int size    = 5;
	int targetSum = 5;
#endif

	generateSubSet (arr, size, targetSum);
	printf ("\ntotal nodes generated %d\n",total_nodes);
}
