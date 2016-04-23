#include<stdio.h>

void insert_sort (int *);

void main ()
{
	int a[10] = {4,0,9,6,3,1,2,8,5,7};
	insert_sort(a);
}

void insert_sort (int *a)
{
	int i,j = 0;

	for (j = 1; j < 10; j++)
	{
		i = j;
		while ((i > 0) && (a[i] < a[i-1])) // i will always be greater than 0 as we start from index = 1
		{
			//2nd element is less so swap it
			int temp = 0;
			temp = a[i-1];
			a[i-1] = a[i];
			a[i] = temp;
			i--;
				
		}
	}
	// print your sorted list
	for (i = 0; i < 10 ; i++)
	printf("\n Soreted list is %d",a[i]);
}
