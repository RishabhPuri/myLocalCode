#include <stdio.h>

void swap (char *a, char *b)
{
	char c;
	c = *a;
	*a = *b;
	*b = c;
}


void permute (char *str, int s, int e)
{
	// print on the end condition , to get out of recursion
	if (s == e)
		printf ("%s \n",str);
	else 
	{
		int i;
		for (i=s; i<e; i++)
		{
			// swap 0th char with first char , second char ...
			swap (str+s, str+i);
			permute (str, s+1, e);
			// swap the char back in place , so that i increments and next swap is 'c'
			swap (str+s, str+i);
		}
	}
}


void main ()
{
	char str[] = "ABC";
	int len =  strlen(str);
	
	permute (str, 0, len);
}
