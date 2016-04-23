#include <stdio.h>
#include <stdlib.h>

typedef struct qNode {
	struct qNode *prev, *next;
	int pageNumber;
} qNode;

typedef struct Q {
	struct qNode *head, rear*;
	int size;
	int currSize;
} Q;

typedef struct hash {
	int size;
	Q* *array;  // array of pointers 
} hash;

void createQ (int size)
{
	Q *temp = NULL;
	if (NULL == (temp = calloc(1,sizeof (Q))))
		perror ("calloc error");

	Q->head = Q->rear = NULL;
	Q->size = size;
	Q->currSize = 0;
}

qNode *addNewNode (int pageNumber)
{
	qNode *temp = NULL;
	
	if (NULL == (temp = calloc (1, sizeof(qNode))))
		perror ("calloc error");

	temp->pageNUmber = pageNumber;
	temp->next = temp->prev = NULL;
	
	return temp;
}

hash *createHash (int size)
{
	hash *temp = NULL;
	Q **temp = NULL;
	if (NULL == (temp = calloc (1, sizeof(hash))))
		perror ("calloc error ");

	temp->size = size;

	if (NULL == (temp = calloc (size, sizeof(char*))))
		perror ("calloc error ");

 	temp->array = temp;
	
	int i;
	for (i=0;i<hash->size;i++)
		hash->array[i] = NULL;

	return temp;	
}

bool isQFull (Q *q)
{
	return (q->count == q->size);
}

bool isQEmpty (Q  *q)
{
	return (q->count == 0);
}

void deQ (Q *q)
{
	/** while deq, always check for emptyQ , single node in Q */
	if (isQEmpty (q))	
		return;

	if (q->rear == q->front)
		q->front = NULL;
	
	qNode *temp = q->rear;
	q->rear = temp->prev;

	/** make the next pointer of new rear node as null , no circular */
	free (temp);
	q->count--;
}

void enQ (Q *q, hash *table, int pageNum)
{
	if (isQFull(q))
	{
		/** empty put hash */
		table->array[q->rear->pageNumber] = NULL;

		/** empty out rear of Q*/
		deQ(q);
	}
	
	/** create new node and add it to front */
	qNode *temp = addNewNode (int pageNum);

	/** even if q is empty, then this would create a circular dll */
	temp->next     = Q->front;
	
	/** check if Q is empty , this is the first node */
	if (isQEmpty(q) )
	{
		q->front = q->rear =  temp;
	}
	else
	{
		Q->front->prev = temp;
		Q->front       = temp;
	}
	
	table->array[temp->pageNumber] = temp;
	q->count++;
}

void main ()
{

}
