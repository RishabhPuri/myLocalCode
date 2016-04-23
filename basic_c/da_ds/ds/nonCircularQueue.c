#include <stdio.h>
#include <stdlib.h>

/*
 * a QUEUE is a FIFO
 *
 * a queue is always imagined as a horizontal line unlike 
 * a stack which is always imagined as a vertical line
 *
 *    ----------------------------------
 *    front                        rear
 *
 * a queue is always operated from both ends unlike 
 * a stack which is always operated from a single end 
 *
 * a queue restricts access to middle elements unlike 
 * an array where we can access any element based on the 
 * index
 *
 * a queue is commonly used in places where fairness is required
 * like in a grocery shop where you come first and then you need
 * to be served first , which is fair.
 *
 * */

#define MAX 128
#define IsEmpty front==-1?1:0

/* queue interfaces */
int insert (int element);
int delete ();
void display ();
/* queue interfaces */

int size;
int q[MAX];
int front = -1;
int rear = -1;

int insert (int value)
{
  /*
   * while inserting we take care of q overflow 
   */
  if (rear == size-1)
  {
 	printf ("[%s] QUEUE full: Overflow Error  \n",__FUNCTION__ );
	return 0;
  }
  
  if (front == -1)
  {
    /* if q is uninitialized then we initialize the front */
    front++;
  }

  /* actual q operation */
  rear++;
  q[rear] = value;
  
  return 1;
}

int delete ()
{
  /*
   * while deleting we take care of the q underflow condition 
   */
  if (IsEmpty || front > rear )
  {
    printf ("[%s] QUEUE empty: underflow Error ! \n",__FUNCTION__ );
    return 0;
  }
  printf ("[%s] Element %d deleted !\n",__FUNCTION__, q[front] );
  q[front] = 0;
  front++;
}

void display ()
{
  int i= 0;
  while (i<size)
  {
    printf (" %d",q[i]);
    i++;
  }
}

void main ()
{
  char choice;
  int sizeLocal;
  int value;
  printf ("Enter the size of the queue \n");
  scanf ("%d",&sizeLocal);
  size = sizeLocal;
  
  while (1)
  {
    printf ("\nEnter your choice \n");
    printf ("1. Insert an element \n");
    printf ("2. Delete an element \n");
    printf ("3. Display the Queue \n");
    printf ("4. exit \n");
    if (1 == scanf ("%d",&choice))
    {
       switch (choice)
       {
         case 1:
	  {
            printf (" Enter an element: \n");
	    scanf ("%d",&value);
	    insert (value);
	  }
	   break;
	 case 2:
	   delete ();
           break;
	 case 3:
	  display ();
	   break;
	 case 4:
	   exit (1);
	   break;
	 default:
	     printf ("[%s]Invalid option ! \n",__FUNCTION__ );
       } /* end if switch (choice) */
    } /* end of if (scanf ...)*/
  }
}

