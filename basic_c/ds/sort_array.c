#include <stdio.h>
/* My Global Stuff */
	int a[6] = {0};
	int i,len = 0;
/* My Global Stuff */

int print_array(int *a)
{
int len = 6;
printf("a has address %p\n",a);
	while(len)
	{
		printf("Inside While for printing \n");
		printf("%d",a[len]);
		len--;
	}
return 1;
}

int user_input ()
{

	printf("How many numbers do you want to enter? \n");
	 scanf("Old fashined scanf always Rox .. enter karo bhai %d",a);
	printf("Enter any 6 numbers \n ");
	printf("Address of A %p\n",a);
	while (i < 6)
	{
		scanf("%d",a);
		//a++;i++;
		printf("U entered %dth number as %%d",i,a[i]);
	}
	return 1;
}

void main ()
{
int ret =0;
printf("\t\t  Inside Main \n ");
ret = user_input();
ret = print_array(a);  
}
