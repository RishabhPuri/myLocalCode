#include <string.h>
#include <stdio.h>

void main ()
{
char *a = "Rishabh Puri";
int len = strlen(a);
int i=0;
char b[100] = {0};
a = a + len - 1;
printf("here- %s\n",a);
while (len--){
b[i] = *a;
i++;a--;
}

printf("First %s -after %s  \n  ",a,b);

}
