#include <stdio.h>
#include <malloc.h>

typedef struct _list {
  int data;
  struct _list *next;
} llist;

void InsertNode (llist **, int);
void printList (llist **);
void printRevList (llist **);
void swapUtil (llist **);
void swap (llist **, llist **prev);
//void swap (llist **);

void InsertNode (llist **head, int data)
{
  llist *temp, *newNode = NULL;
  temp = *head;
  newNode = (llist*)calloc (1, sizeof (llist));
  if (newNode)
  {
    newNode->data = data;
    if (!temp)
      newNode->next = NULL;
    else 
      newNode->next = temp;
  }
   /* new head */
  *head = newNode;
}

void printList (llist **head)
{
  llist *temp = NULL;
  temp = *head;
  if (!temp)
    return;
  
  printf ("%d ",temp->data);
  printList (&temp->next);
}

void printRevList (llist **head)
{
  llist *temp = NULL;
  temp  = *head;
  if (!temp)
    return;

  printRevList (&temp->next);
  printf ("%d ",temp->data);
}

void swapUtil (llist **head)
{
  llist *temp, *prev = NULL;
  temp = *head;
  if (temp->next)
    *head = temp->next;

  /* 1->2->3*/ 
  for (;temp; temp = temp->next)
  {
 /*
  *  while swapping two nodes , the idea is 
  *
  *  prev->curr->next
  *
  *  if curr and next are to be swapped then
  *  apart from changing the links of curr/next 
  *  the prev->next link also needs to be changes
  *  otherwise this happens
  *
  *  prev->curr
  *  next->curr
  *
  *  AND the list is broken , so we always carry the previous pointer.
  *
  *  Also for a list 3->2->1
  *  for the last node 1 , we return from swap but after coming out we
  *  increement temp again without checking for null cases 
  *  THIS IS THE CORNER CASE WHEN THE LIST HAS ODD NUMBER OR A SINGLE NODE.
  * */
     swap(&temp, &prev);
     prev = temp->next;
     temp = temp->next;
     /* in case of odd # nodes */
     if (!temp) return;
  }
}

void swap (llist **node, llist **prev)
{
  /* we take temporaray pointers as
   * 1. We need to do pointer manipulation which becomes complicated with "**" 
   * 2. We need the original node and node->next pointer of the node 
   * */
  llist *currNode, *nextNode = NULL;
  currNode = *node;
  if (currNode->next)
    nextNode = currNode->next;
  else return;
  
  /* 1->2->3->NULL
   * p  c  n
   * we do normal pointer manipulation here 
   * but after that we update the "**" variable
   * with the address of the newly udpated node. 
   *  */
  if (*prev)
    (*prev)->next = nextNode;
  
  currNode->next = nextNode->next;
  nextNode->next = currNode;
  *node = nextNode;
}

void main ()
{
  llist *head = NULL;
  int data;
  printf ("swap every 2 nodes of the list \n");
  while (1)
  {
    printf ("Enter numbers:");
    if (scanf ("%d",&data) != 1)
      break;

    if (data == 0)
      break; 

     InsertNode (&head, data);
  };
  printf ("print list ");
  printList (&head);
  printf (" \n Reversing ");
  printRevList (&head);
  printf ("\n");
  
  swapUtil (&head); 

  printf ("print list ");
  printList (&head);
  printf (" \n Reversing ");
  printRevList (&head);
  printf ("\n");

}
