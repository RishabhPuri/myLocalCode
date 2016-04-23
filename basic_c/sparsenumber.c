#include <stdio.h>
#include <stdbool.h>

void checksparse1 (int digit)
{
	int i ;
	bool res = 0;
	for (; digit > 0; digit >>= 1)
	{
		if (digit & 0x1) 
		{
			if (res == 1)
			{
				printf ("Yes its sparse1 \n");
				return;
			}
			else res = 1;
		}
		else 
			res = 0;
	}
	printf ("no its not sparse2 \n");
	return;
}

void checksparse2(int digit)
{
	if (digit & (digit >> 1) ) 	
		printf ("yes its  sparse 2\n");
	else
		printf ("no its not sparse 2\n");
		
}

void main ()
{
	int digit = 12;
	checksparse1 (72);
	checksparse2 (72);
}
