#include <stdio.h>
#include <stdlib.h>
/** a heap needs to be dynamic, at least officially */

typedef struct _mh {
	int size;
	/** root because min heap is a complete binary tree 
	 * though its left and right child are not relate to each other */
	struct node *root;
}minHeap;

typedef struct node {
	int data;
} node;

enum {
	INSERT=1,	
	DELETE,
	PRINT	
} op;

#define TRUE 				  1
#define ENTEROPERATTIONSTRING "Enter the operation code \n"
#define ENTERNUMBER			  "Enter the number to insert in heap \n"
#define TOHELL				  "Default case hit \n"
#define LEFT_CHILD(i)  		2(i) 	//2*(i)+1
#define RIGHT_CHILD(i) 		2*(i)+1
#define PARENT(i)      		(i)/2 	//((i)-1)/2
#define IS_HEAP_EMPTY(_x)  	((_x)->size==0)
#define	SWAP(a, b)			\
do { \
	(a) ^= (b);		\
	(b) ^= (a);		\
	(a) ^= (b);		\
}while(0);
						
minHeap *gHeap;

void initMinHeap();
void insertMHeap(int data);
void deleteMHeap();
void printMHeap();
void Heapify();

void initMinHeap()
{
	minHeap *temp = calloc (1, sizeof (minHeap));

	if (NULL == temp)
	{
		perror ("calloc \n");
		return;
	}
	
	temp->size = 0;
	temp->root = NULL;
	gHeap = temp;
	return;	
}

void insertMHeap(int data)
{
	if (IS_HEAP_EMPTY(gHeap))
	{
		node *temp = calloc (1, sizeof (node));
		if (NULL == temp)
		{
			perror ("calloc \n");
			return;
		}

		temp->data = data;
		gHeap->root = temp;
		gHeap->size++;
		return;		
	}
	else 
	{
		int i = ++gHeap->size;
		
		gHeap->root =  realloc (gHeap->root, (gHeap->size+1)	* sizeof(node));
		gHeap->root[i].data = data;
		while (i && data < gHeap->root[PARENT(i)].data)
		{
			SWAP(gHeap->root[i].data, gHeap->root[PARENT(i)].data);	
			i = PARENT(i);	
		}
	}
}

void deleteMHeap()
{

}

void Heapify()
{

}

void printHeap ()
{
	int  i = 0;
	while (i++ < gHeap->size)
		printf("%d \n",gHeap->root[i].data);
}


void main ()
{
	/** 1. int minHeap
	 *	2. take input from user and insert in heap
	 *	3. do get minHeap ()
	 *	4. delete and {heapify}  */
	unsigned int op, i;
	initMinHeap(0);
	do {
		printf (ENTEROPERATTIONSTRING);
		scanf ("%u",&op);
		switch (op)
		{
			case INSERT:
				printf (ENTERNUMBER);	
				scanf ("%u", &i);
				insertMHeap (i);
				break;
			case DELETE:
				deleteMHeap();
				break;
			case PRINT:
				printHeap();
				break;
			case GETOUT:
				return;
			default:
			{
				printf(TOHELL);		
				break;	
			}
		}
	}while (TRUE);
}
