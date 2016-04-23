#include <stdio.h>

typedef struct __foo{
	int a;
	int b;
	char c;
}foo;

typedef struct __foo1{
	int a;
	char c;
	int b;
}foo1;





void main ()
{
struct __foo foo; struct __foo1 foo1;
printf("sizeof struct foo is %3d\n",sizeof(foo));
printf("sizeof struct foo1 is %3d\n",sizeof(foo1));
printf("align of struct foo1 is %3d\n",(__alignof__ (foo)));
}
