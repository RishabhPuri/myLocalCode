#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct queue {
	int rear;
	int front;
	int max_size;
	int *data;
} Q;

void qInit (struct queue **q, int qSize);
void enQ (int data, struct queue *q);
int deQ  (struct queue *q);
bool isQFull  (struct queue *q);
bool isQEmpty (struct queue *q);
int qSize (struct queue *q);

void qInit (struct queue **q, int qSize)
{
	struct queue  *temp = NULL;
	if (NULL == (temp = calloc(1, sizeof (struct queue))))
	{
		perror ("calloc error");	
		return;
	}
	
	temp->rear 	   = 0;
	temp->max_size 	   = qSize+1;
	temp->front	   = 0;
	if (NULL == (temp->data = calloc(qSize+1, sizeof (int))))
	{
		perror ("calloc error");
		return;
	}	
	
	*q = temp;
	return;
}

/**  make a circ q, better */
void enQ (int data, struct queue *q)
{
	if (!q) return;

	if (isQFull(q)) 
	{
		printf ("Q overflow \n");
		return;
	}
	
	q->data[q->rear] = data;
	q->rear = (q->rear+1)%q->max_size;
}

int deQ (struct queue *q)
{
	int data;
	if (!q) return 0;

	if (isQEmpty(q))
	{
		printf ("Q underflow \n");
		return 0;
	}
		
	data = q->data[q->front];
	q->front = (q->front+1)%q->max_size;
	return data;
}

bool isQFull (struct queue *q)
{
	return ((q->rear+1)%q->max_size == q->front);
}

bool isQEmpty (struct queue *q)
{
	/** if both are init at zero*/
	return q->rear ==  q->front;
}

void main ()
{
	int count, i;
	scanf("%d", &count);

	int givenOrder;
	int requiredOrder[count];

	struct queue *q = NULL;
	qInit (&q, count);

	if (!q) { printf ("Q malloc error "); return ;}
	for (i=0;i<count;++i)
	{
		scanf("%d",&givenOrder);
		enQ(givenOrder, q);
	}
	for (i=0;i<count;++i)
		scanf("%d",&requiredOrder[i]);
	
	int timeCount = 0;
	int item; i = 0;

	while (i<count)	
	{
		item = deQ (q);
		if (requiredOrder[i] != item)
		{
			enQ (item, q);
			timeCount++;
		}
		else 
		{
			timeCount++;
			i++;
		}
	}

	printf ("%d",timeCount);
	
}
