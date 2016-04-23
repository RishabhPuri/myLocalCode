#include <stdio.h>
#include <stdlib.h>

typedef struct hashTable {
  void **bucket;
}hashTable;

typedef struct hashNode {
  struct hashNode *next;
  struct hashNode *prev;
  int data;
  int key;
  int hashValue;
}hashNode;

typedef struct linkedlist {
  struct linkedlist *next;
  struct linkedlist *prev;
  void *data;
}llist;

void hashTableInit (hashTable **table)
{
  void **temp;
  *table = (hashTable *)calloc (1, sizeof(hashTable));
  temp = (void **)calloc (100, sizeof (hashNode));
  (*table)->bucket = temp;
}

hashNode *getHash (hashNode **, int key);
hashNode *setHash (hashNode **, int key, int data);
hashNode *delHash (hashNode **, int key);
void addToList (llist *, llist **head);

void addToList (llist *newNode, llist **head)
{
    newNode->prev=NULL;
    newNode->next=*head;
   
    if (newNode->next!=NULL)
      newNode->next->prev = newNode;
    
    *head = newNode;
}

hashNode *getHash (hashNode **node, int key)
{
  hashNode *temp;
  temp = node[key];
  if (!temp) return NULL;
  while (temp)
  {
    if (temp->data == key)
      return temp;
    else temp=temp->next;
  }
  return NULL;
} 

hashNode *setHash (hashNode **node, int key, int data)
{
  hashNode *newNode = NULL;
  hashNode *temp = NULL;
  if (NULL == (temp = getHash(node, data)))
  {
    newNode = (hashNode *)calloc (1,sizeof (hashNode));
    newNode->data = data;
    newNode->key = key; 
    addToList ((llist*)newNode, (llist **)&node[key]);
    return newNode;
  } 
  
}

void main ()
{
  hashTable *head =  NULL;
  hashNode *temp = NULL;
  hashTableInit (&head);
  int sample [20] = {1,2,3,4,5,6,7,8};
  int i =0;
  if (NULL == (temp = setHash ((hashNode **)head->bucket, sample[i], sample[i])))
    printf ("Error");
  else printf ("%d \n",temp->data);

  if (NULL == (temp = setHash ((hashNode **)head->bucket, sample[i], 12)))
    printf ("Error");
  else printf ("%d \n",temp->data);
}
