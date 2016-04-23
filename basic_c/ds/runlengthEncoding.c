#include <stdio.h>

char *rle(char *str1)
{
	char *dest =  calloc (1, 2*strlen(str1));
	char *src = str1;

	int len = strlen(str1); int i;

	char lookup[255];

	for (i=0; i < len ; i++)
	{
		int subs = *str1;
		lookup[subs];
		str1++;
	}
	
	for (i=0; i< len; i++)
	{
		*(dest)=*(src);
		int subs = *dest;
		dest++;
		dest = lookup[subs];
	}	
	return dest;
}

void main ()
{
	char *str1 = "GeeksForGeeks";
	printf ("rle %s",rle(str1));
}

