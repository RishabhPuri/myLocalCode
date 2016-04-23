#include <stdio.h>

void swap (int *a, int *b)
{
	int temp;
	temp = *a; *a = *b; *b = temp;
}

void main ()
{
	int a[] = {4, 3, 7, 8, 6, 2, 1};
	//int a[] = {1,4,3,2};
	int len = sizeof(a)/sizeof(a[0]);
	int i = 0; 
	while (len-1 > i)
	{
		if (0 == i%2)
		{
			if (a[i] > a[i+1])
				swap (&a[i], &a[i+1]);
		}
		else 
		{
			if (a[i] < a[i+1])
				swap (&a[i], &a[i+1]);
		}
		i++;
	}

	i = 0;
	while (len > i)
	{
		printf ("%d ",a[i]);
		i++;
	}
}
