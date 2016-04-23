#include <stdio.h>
#include <stdlib.h>

typedef struct llist {
   int data;
   struct llist *next;
} llist;

void CreateList (llist **head, int a)
{
   if (!*head)
   {
      *head = calloc (1, sizeof (llist));
      (*head)->data = a;
      return;
   }
  
   /* tempHead is simply pointing to NULL */ 
   llist *tempHead = NULL;
   tempHead = calloc (1, sizeof (llist)); 
   (tempHead)->data = a;
  
   llist *last = *head;
   while (last)
   {
      if (last->next)
          last = last->next;
      else { last->next = tempHead; return;}
   }
}

void PrintList (llist *head)
{
   if (!head) return; 
   printf ("%d ",head->data);
   PrintList (head->next);
}

llist *mergeList (llist head1, llist head2)
{}

void main ()
{
  llist *head1 = NULL;
  llist *head2 = NULL;

  CreateList (&head1, 1);
  CreateList (&head1, 2);
  CreateList (&head1, 3);
  PrintList (head1);

  CreateList (&head2, 4);
  CreateList (&head2, 5);
  CreateList (&head2, 6);
  PrintList (head2);
   
#if 0
  head1 = mergeList (head1, head2); 
  printList (head1);
#endif
}
