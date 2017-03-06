#include <stdio.h>
#include <stdlib.h>

typedef struct qNode {
    int key;
    void *data;
    struct qNode *next;
} qNode;

typedef struct _queue {
    qNode *front, *rear;
    unsigned int maxSize;
    unsigned int count;
} Q;


Q *createQ (int size)
{
    Q *temp = calloc (1, sizeof (Q));
    if (temp == 0x0)
        return temp;
    
    temp->rear = temp->front = 0x0;
    temp->count = 0;
    temp->maxSize = size;
    return temp;
}

/** enQ adds to rear */
unsigned int enQ (Q* q, void *node, int data)
{
    if (q->count == q->maxSize)
    {
        printf ("Q full \n");
        return 0;
    }
    
    qNode *temp = calloc (1, sizeof (qNode));
    if (temp == 0x0)
        return 0;    
    
    temp->key = data;
    temp->data = node;

    if (q->rear == 0x0)
    {
        q->rear = q->front = temp;
    }
    else    
    {
        q->rear->next = temp;
        q->rear = temp;
    }
    
    q->count++;
    return 1;
}

/** deQ removes from the front , but doesnt free up memory*/
void * deQ (Q *q)
{
    if (q->count == 0)
    {
        printf ("Q underflow \n");
        return 0x0;
    }

    qNode *temp = q->front;
    q->front  = temp->next;
    if (q->front == 0x0)
        q->rear = 0x0;
    q->count--;
    return temp;
}

void deleteQ (Q *q)
{
    qNode *temp =  0x0;

    while (q->front)
    {
        temp = q->front ;
        q->front  = temp->next;
        free (temp);
    }
}

int main ()
{
    Q *q = createQ(10);
    enQ(q, 0x0, 10);
    enQ(q, 0x0, 20);
    deQ(q);
    deQ(q);
    enQ(q, 0x0, 30);
    enQ(q, 0x0, 40);
    enQ(q, 0x0, 50);
    struct qNode *n = deQ(q);
    if (n != NULL)
      printf("Dequeued item is %d", n->key);
    return 0;
}

