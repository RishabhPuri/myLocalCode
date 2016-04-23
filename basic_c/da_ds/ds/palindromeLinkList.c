#include <stdio.h>

typedef struct _list 
{
  char c;
  struct _list *next;
} llist;

printList (llist *temp)
{
  while (temp)
  {
    printf ("%c",temp->c);
    printList (temp->next);
  }
}

void AddNode (llist *node, char *str, int index, int end)
{
  if (index == end) return ; 
  else 
  {
    if (!node)
    {
      node = calloc (1, sizeof(llist));
      node->c = str[index];
      node->next = NULL;
      AddNode (node->next, str, index+1, end);
    } 
  }
}

void AddtoList ( llist **head, char *str, int start)
{
  llist *temp = *head;
  int len = strlen (str)-1;
  AddNode (temp, str, start, len); 
}

int isPalindrome (llist *node)
{


}

void main ()
{
  int ret = 0;
  llist *head = NULL;
  char str[] = "badab";
  AddtoList (&head, str, 0);
  printList (head);
#if 0
  if ((ret = isPalindrome (listHead))==1)
    printf ("%m");
  else printf ("Fail \n");
#endif
}
