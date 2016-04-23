#include <stdio.h>

void main()
{
// if char s[] is declared
// ERROR : empty character constant
char s[] = "Rishabh";
int i, n = 0;

for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
n = 10 * n + (s[i] - '0');

printf("return n is %d",n);
}
