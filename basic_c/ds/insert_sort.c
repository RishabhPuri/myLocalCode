#include <stdio.h>

void main ()
{
		int a[1000] = {0};
		int inNum = 0, i;
		printf ("Enter number: ");
		scanf  ("%d", &inNum);
		getch ();
		if (a[i] > inNum)
		{
				a[i] = inNum;
				shiftBy1 (a);
		}
        printArray (a);
}
