#include <stdio.h>

static int IntToHex(int* a);

void main ()
{
int a = 0;
puts("\n Enter a number :");
scanf("%d",&a);

IntToHex(&a);
}



// the problem here is that you can't use % on a pointer variable ..

int IntToHex(int *a)
{
printf("number is %d",*a);
int ret = *a%16;
printf("ret %d",ret);


}
