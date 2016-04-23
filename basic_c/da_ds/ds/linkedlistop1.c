#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct _list
{
  int data;
  struct _list *next;  
} list;

void insertNode (list **head, int data);
void printList (list **head);

/* node is inserted at the beginning */
void insertNode (list **head, int data)
{
  list *temp = NULL;
  temp = calloc (1, sizeof (list));
  temp->data = data;
  temp->next = *head;
  *head = temp;
}

void printList (list **head)
{
  list *temp = NULL;
  temp = *head;
  printf ("%d ",temp->data);
  if (temp->next)
  {
    printList (&temp->next);
  }
}

void printListRev (list **head)
{
  list *temp = NULL;
  temp = *head;
  if (temp->next)
   printListRev (&temp->next);
  printf ("%d ",temp->data);
}

void deleteNode(list **head)
{

  /* head is the pointer to the node previous to node we will delete */
  list *node2BDel = NULL;
  list *next = NULL;
  list *prev = NULL;

  prev = *head;
  node2BDel = prev->next;
  if (node2BDel)
   next  = prev->next->next;
  else next = NULL;

  prev->next = next;
  free (node2BDel);
  node2BDel = NULL;
}

void skipNdeleteM (list **head, char n, char m)
{
  struct mallinfo info;
  info = mallinfo ();
  printf("Memory in use: %d bytes\n",
        info.usmblks + info.uordblks);
  printf("Total heap size: %d bytes\n", info.arena);
  list *temp = NULL;
  temp = *head;
  int skipCount = n;
  int deleteCount = m;
  
  for (;temp;temp=temp->next)
  {
    printList (head);  printf ("\n");
    if (skipCount == 1)
    {
      skipCount = n;
      while (deleteCount)
      {
        deleteNode (&temp); 
        deleteCount--;
      }
      deleteCount = m;
    }
    if (skipCount > 1)
      skipCount--;
  }
}

void main ()
{
  list *head = NULL;
  int data;
  /* skipNdeleteM () */
  char m,n = 0;
   
  struct mallinfo info;
  info = mallinfo (); 
  printf ("implementing skipNdeleteM () \n");
  printf (" Enter N and M \n");
  scanf ("%d %d ",&n, &m);
  if (m==0 || n == 0)
  {
    printf ("not cool ! Exiting");
    return;
  }
  while (1)
  {
    if (scanf ("%d",&data) == 1)
    {
      if (data == 0)
        break;
      else insertNode (&head, data);
    }
  }
  printf ("Reverse Printing the list \n");
  printListRev (&head); 
  printf ("\n");
  printf ("Printing the list \n");
  printList (&head); 
  printf ("\n");
  
  skipNdeleteM (&head, n, m);
  printf ("Printing the list \n");
  printList (&head); 
  printf ("\n");

  printf("Memory in use: %d bytes\n",
        info.usmblks + info.uordblks);
  printf("Total heap size: %d bytes\n", info.arena);

}

