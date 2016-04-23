#include <stdio.h>


// using a reentrant version of strtok_r 
// strtok returns a null terminated string of tokens including token
char *strtok_r (char *src, char *tokenSet, char **savePtr);


unsigned int inet_pton4 (const char *str)
{
	char t = 0, *s=str ;

	unsigned int ip; unsigned int flag = 0;

	if (!str) return 0;

	if (strlen(str)) return 0;

	while (*s++ != '\0')
	{
		if (*s >= '0' && *s <= '9')	
		{
			if (flag == 0)
				t = 0;
	
			t = (t * 10) + (*s - '0');

			flag = 1;	
		}
		else if (*s == '.')
		{
			flag  = 0;
		}
	}

}

void main ()
{

}
