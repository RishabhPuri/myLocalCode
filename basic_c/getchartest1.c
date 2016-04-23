#include <stdio.h>

void main ()
{
	printf ("EOF: %d\n", EOF);
	/** ctrl-d prints EOF */
	int nb = 0, nl = 0, nt = 0;
	char c;
	while (( c = getchar()) != EOF)
	{
		if (c == ' ')
			nb++;
		else if (c == '\t')
			nt++;
		else if (c == '\n')
			nl++;
	}
	printf ("\n blanks %d, lines %d, tabs %d", nb, nt, nl);
}
