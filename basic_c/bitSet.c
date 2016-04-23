#include <stdio.h>

void main ()
{
	int a = 67;
	cnt i, count=0;
	while (1)
	{
		if (a = (a & (a-1)) ==0)
			break;
		else count++;
	}
	printf ("bitset %d", count);	
}
