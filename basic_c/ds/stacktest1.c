#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define False 0
#define True 1
unsigned int candidateCount;
void push (int *top, int item, int *rStack);
int pop (int *top, int *rStack);
bool IsEmpty (int *top, int *rStack);
bool IsFull (int *top, int *rStack);

void push (int *top, int item, int *rStack)
{
	if (!top || !rStack)
	{
		printf ("push Stack uninit \n");
		return ;
	}
	
	if (IsFull (top, rStack))
		return ;
	
	(*top)++;
	rStack[*top] =  item;
	return;
}

int pop (int *top, int *rStack)
{
	int item = 0;
	if (!top ||  !rStack)
	{
		printf ("pop Stack uninit \n");
		return item;
	}
	
	if (IsEmpty (top, rStack))
		return item;
		
	item = rStack[*top];
	(*top)--;
	return item;
}

bool IsFull (int *top, int *rStack)
{
	if (!top || !rStack)
		return False;
	
	if (*top == (candidateCount-1))
	{
		printf ("Stack is full \n");
		return True;
	}
	else return False;
}

bool IsEmpty (int *top, int *rStack)
{
	if (!top || !rStack)
		return False;
		
		if (*top == -1)
			return True;
		else return False;
}

int main()
{
	unsigned int i;
	unsigned int *rating = NULL, sum=0;
	signed int top = -1;
	unsigned int *rStack = NULL;
	scanf("%u",&candidateCount);
	if (candidateCount > 5000)
	{
		printf ("0");
		return 0;
	}
	
	if (NULL == (rating = malloc(candidateCount*sizeof (int))))
	{
		perror ("malloc error");
		return;
	}
	
	if (NULL == (rStack = malloc(candidateCount*sizeof (int))))
	{
		perror ("malloc error");
		return;
	}
	
	i=0;
	while(i < candidateCount)
	{
		scanf("%u",&rating[i]);
		if (rating[i]>10)
			return 0;
		i++;
	}
	
	for (i=0; i< candidateCount; ++i)
	{
		if (i==0 && rating[i] == 0)
			continue;
		if (rating[i] !=0 )
			push(&top, rating[i], rStack);
		else
			pop(&top, rStack);
	}

	while (! IsEmpty(&top, rStack))	
		sum+=pop(&top, rStack);

	printf ("%u",sum);
	
}
