#include <stdio.h>

void merge (int *a, int l, int m, int h);
void mergeSort (int *a, int low, int high);
void printSortArray (int *a, int len);

void printSortArray (int *a, int len)
{
	int i;
	for (i=0; i< len;i++)
		printf ("%d ",a[i]);
}

void mergeSort (int *a, int low, int high)
{
	if (high > low)
	{	
		int m = (low + (high-low))/2;

		mergeSort (a, low, m);
		mergeSort (a, m+1, high);
		merge (a, low, m, high);
	}

}

void merge (int *a, int low, int middle, int high)
{
	// calculate 2 lenghts
	int n1 = middle-low+1;
	int n2 = high - (middle);

	// create 2 temp arrays
	int r1[n1], r2[n2];
	int i= 0, j = 0, k = low;

	for (i=0; i<n1;++i)
		r1[i] = a[low+i];

	for (j=0; j<n2;++j)
		r2[i] = a[middle+1+j];

	i=0; j = 0;

	while (i < n1 || j < n2)
	{
		if (r1[i] < r2[j])
		{
			a[k] = r1[j];
			i++;
		}
		else 
		{
			a[k] = r2[j];
			j++;
		}
		k++;
	}

	// any pending in r1 ?
	while (i < n1)
	{
		a[k] = r1[i];
		k++; i++;
	}

	// any pending in r2 
	while (j < n2)
	{
		a[k] = r2[j];
		k++; j++;
	}
}

void main ()
{
	int a[] = { 12, 11, 13, 5, 6, 7 };
	int len =  sizeof(a)/sizeof(a[0]);

	printf ("Before merging \n");
	printSortArray (a, len);
	
	mergeSort (a, 0, len-1);

	printf ("After merging \n");
	printSortArray (a, len);
		
}
