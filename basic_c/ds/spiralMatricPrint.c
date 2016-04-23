#include <stdio.h>

void main ()
{
	a[4][4] = { 1  2  3  4
			    5  6  7  8
			    9 10 11 12
			   13 14 15 16};
	
	for (i=0; i<4; i++)
		printf ("%d ",a[0][i]);
	for (i=1; i<4; i++)
		printf ("%d ",a[i][4]);
	for (i=3; i>0; i++)
		printf ("%d ",a[4][i]);
	for (i=3; i>1; i++)
		printf ("%d ",a[i][0]);
	for (i=2;i<4;i++)
		printf ("%d ",a[2][i]);
	
}
