#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned int utop = -1;
int query  = 0;

void push (int cost, int *stack);
int pop (int *stack);
int top (int *stack);
bool isEmpty (int *stack);
bool isFull (int *stack);

void push (int cost, int *stack)
{
	if (!stack) return;
	
	if (isFull(stack)) { printf ("overflow \n"); return;}
	
	utop++;
	stack[utop]=cost;
}

int pop (int *stack)
{
	int item;
	if (!stack) return;
	
	if (isEmpty(stack)) {printf ("underflow \n"); return;}
	
	item = stack[utop];
	
	utop--;
	
	return item;
}

bool isFull (int *stack)

{
	if (!stack) return;
	
	return (utop == query);
}

bool isEmpty (int *stack)
{
	if (!stack) return;
	
	return (utop==-1);
}

int top (int *stack)
{
	if (!stack) return;
	
	if (isEmpty(stack)) return 0;
	
	return stack[utop];
}

int main()
{
    
    scanf ("%d",&query);
    int n, cost;
    int stack[query];
    int i;
    for (i=0;i<query;++i)
    {
    	scanf("%d",n);
    	if (n==1)
    	{
    		(0==top (stack))? printf("No Food\n"): printf ("%d\n",pop (stack));
    	}
    	else if (n==2)
    	{
    		scanf("%d",&cost);
    		push(cost, stack);
    	}	
  
    		
    }
    return 0;
}
