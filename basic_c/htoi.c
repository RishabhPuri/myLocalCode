#include <stdio.h>

void htoi (char *s)
{
	int digit = 0;
	char isHex =  1, hexDigit = 0;
	int i = 0;
	
	if (s[i] == '0')
	{
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
		else 
		{
			printf ("not a hex string ! \n");
			exit (0);
		}
	}

	for (; isHex == 1; ++i)
	{
		if (s[i] >= '0' && s[i] <= '9')
			hexDigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexDigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexDigit = s[i] - 'A' + 10;
		else 
			isHex = 0;

		if (isHex == 1)
			digit =  digit * 16 + hexDigit;
	}
	
	printf ("%s \t %d\n",s, digit);
}


void main (int argc, char **argv)
{
	if (argc > 2 || argc < 2)
	{
		printf ("Error: Correct format is htoi <hex-string> \n");
		exit (0);
	}
	
	htoi (argv[1]);
}
