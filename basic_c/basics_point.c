#include<stdio.h>

#define SZ(var) 	sizeof(var)

int* func (int *);

void main()
{
	//points to nowhere ...
	char *a = NULL;
	int b[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	int *c = b;
	printf("\nsize of a %d",SZ(a));
	printf("\nsize of b %d",SZ(b));
	printf("\nsize of c %d",SZ(c));
	c++;
	printf("\nincreement by 1 %d ",*c);
	c = func (c);
	printf("\n value of c is in main%d ",*c);

}


int *func (int *c)
{
	int a =10;	
	printf("\n value of c %d",*c);
	c = &a;
	printf("\n value of c after %d",*c);
	return c ;
}
