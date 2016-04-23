#include<stdio.h>
#include<stdlib.h>

void main ()
{
#if 0
	char c =getchar();
	while(c != EOF) {
		putchar(c);
	c = getchar();
	}
#endif
int *i = 0;
int a=(void *)0;
int b=NULL;


i = malloc(4);

*i = 4;

printf("i = %d\n",*i);
printf("i = %x\n",i);
printf("a %p",&a);
printf("\n a %d",a);
printf("\n pointa %d",(int*)a+1);
printf("\n a %p",a);
printf("\n a %p",&a);

free(i);

}
