#include <stdio.h>
#include <string.h>
void main ()
{
	// char *s1 = "Rishabh Puri";
	// char *s2 = "sru";
	// can't modify individual indices 
	// so take char arrays ....
	char s1[20] = "Rishabh Puri";
	char s2[4] = "sru";
	int i,j = 0;
	int flag = 0;
	// algo 
	while (j != strlen(s1)) {
		if (s1[j] != s2[flag]) { j++; continue; } 	

		flag++;
		for (i=j;i<strlen(s1);i++) 
			s1[i] = s1[i+1];
		s1[i] = '\0';
		j=0;     // reset j to start scanning the whole string !
	}
	printf("Init strings were %s - %s \n",s1,s2);
	printf("Final string %s \n",s1);
}
