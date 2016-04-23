#include <stdio.h>
void reverse (char *start, char *end);

reverseUtil (char *str)
{
	char *temp = str;
	char *s = str;
	while (*temp)
	{
		temp++;
		if (*temp == '\0')	
		{
			reverse (s, temp-1);
		}
		else if (*temp == ' ')
		{
			reverse(s, temp-1);
			s = temp++;
		}
	}
	reverse (s, temp-1);
}

void reverse (char *start, char *end)
{
	char temp;
	while (start < end)
	{
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
}


void main ()
{
	char str[] = "My name is Rishabh";
	reverseUtil (str);

	printf ("string after reversal: %s \n",str);
}
