#include <stdio.h>

void main()
{
	unsigned int set, user, i = 0;
	printf("this is my insert sort test\n");
	printf("enter set size:");
	scanf("%d",&set);
	printf("you want to enter %d numbers\n",set);
	int *a = NULL;
	a = (int *)malloc(set); // this is equa; to a[11] 
	bzero(a, 11*sizeof(int));

	do {
		printf("enter number:"); 
		scanf("%d",&a[i]);
		i++;
		printf("usercount is\n %d",i);
	}while(set!=i);

	printf("you entered these numbers:\n");
	i = 0;
	do {
		printf("%d\t",a[i]);
		set--;i++;
	} while(set);

}
