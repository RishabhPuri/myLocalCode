#include<stdio.h>

// This line forces the compiler to generate a warning 
// to the user that the two variables of different types 
// are compared. for typesafety ...
//(void *)(&__var1 == &__var2); \

#define max(x,y)  ({ \
		typeof(x) __var1 = x; \
		typeof(y) __var2 = y; \
		(void *)(&__var1 == &__var2); \
		__var1 > __var2 ? __var1 : __var2 ; \
		})

#define max3(x,y,z) ({  \
		typeof(x) __var1 = x ; \
		typeof(y) __var2 = y ; \
		typeof(z) __var3 = z ; \
		(void *)(&__var1 == &__var2); \
		(void *)(&__var1 == &__var3); \
		(__var1 > __var2) ? ((__var1 > __var3) ? __var1 : __var3) : ((__var3 > __var2) ? __var3 : __var2); \
		})	


void main()
{
int a = 15;
int b = 11;
int c = 9;

int j = 5;
int i[10] = {1,2,3,4,5,6,7,8,9};

printf("result %d",max(a,b));
printf("result %d",max3(a,b,c));

printf("\n first sol%a",i[j]);
printf("\n seccond sol%a",j[i]);
}
