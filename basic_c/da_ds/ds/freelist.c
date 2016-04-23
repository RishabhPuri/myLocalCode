#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u32;

typedef struct {
	u32 id;
	u32 next;   
}  freeNode ;

typedef struct freeList {
	u32 maxNodes;
	u32 head;
	u32 tail;
	u32 count;
	freeNode *fNode;
}freeList;

freeList *InitFreeList (int size)
{
    freeList *ptr;
    freeNode *ptr1;
    u32 i;

    if (NULL == (ptr = calloc (1, sizeof ptr)))
	return NULL;
    
    if (NULL == (ptr1 = calloc (size, sizeof (freeNode))))
    {
	free (ptr);
	return NULL;
    }
 
    /** Loop till one node before last */ 
    for (i=0;i<(size-1);i++)
    {
	ptr1[i].id = i;
        ptr1[i].next = i+1;
    }
    /** mark the last node */
    ptr1[i].id = i;
    ptr1[i].next = 0xffffffff;
   
    ptr->maxNodes = size;
    ptr->head     = 0;
    /** Tail points to the end of the list, but the node to which it points is marker node*/
    ptr->tail     = size-1;
    ptr->count    = 0;
    ptr->fNode    = ptr1;
    return ptr;
}

u32 FreeNodeAlloc (freeList *ptr)
{
   u32 ret = 0xffffffff;
   if (ptr->count < ptr->maxNodes)
   {
     /** Get head */
     ret = ptr->fNode[ptr->head].id;
    
     /** address if head == tail */
     if (ptr->head == ptr->tail)
	ptr->tail = ptr->fNode[ret].next; 

     /** Update new head */
     ptr->head = ptr->fNode[ptr->head].next;
    
     /** Inc legit count */
     ptr->count++;
   
   }
   return ret;
}

void FreeNodeFree (freeList *ptr, u32 id)
{
  if (ptr->count !=0 )
  {
    if (ptr->tail != 0xffffffff)
    {
      ptr->fNode[ptr->tail].next = 0xffffffff;  
    }
    ptr->fNode[id].next = 0xffffffff;
    ptr->tail = id;

    if (ptr->head == 0xffffffff)
      ptr->head = id;

    ptr->count--;
  }
}

void main ()
{
    u32 id;
    freeList *list = NULL ; 
    u32 temp;
  
    for (;;)
    { 
	    printf ("\n Enter the op code for list \n");
	    puts ("1. Create list ");
	    puts ("2. Allocate Id ");
	    puts ("3. Free Id");
	    scanf ("%d",&temp);
	    getchar ();

	    switch (temp)
	    {
		    case 1:
		    {
			    if (list)
			    {
				puts ("List exists already \n");
				break;
			    }
			    printf ("Enter the size of list \n");
			    scanf ("%d",&temp);
			    getchar ();

			    list = InitFreeList (temp);
			    continue;
		    }
		    break;

		    case 2: 
			    id = 0;
			    printf ("\n before allocation id %d, curr head %d, curr tail %d, curr count %d, max %d\n",
					    id, list->head, list->tail, list->count, list->maxNodes);
			    id = FreeNodeAlloc (list);
			    if (id != 0xffffffff ) {
				    printf ("\n Allocated id %d, curr head %d, curr tail %d, curr count %d max %d\n",
						    id, list->head, list->tail, list->count, list->maxNodes);
			    }
			    else 
			    { puts ("\n Id Store empty, exhausted \n"); }
			    continue;
			    break;

		    case 3:
			
			    printf ("Enter the id to be freed \n");
			    scanf ("%d",&id);
			    getchar ();

			    printf ("\n before freeing id %d, curr head %d, curr tail %d, curr count %d, max %d\n",
					    id, list->head, list->tail, list->count, list->maxNodes);

			    FreeNodeFree (list, id);

			    printf ("\n freeing id %d, curr head %d, curr tail %d, curr count %d max %d\n",
					    id, list->head, list->tail, list->count, list->maxNodes);
			    continue;
			    break;

		    default :
			    printf ("\n no such option exiting ... \n"); 
			    
	    }
	    if (temp > 3) break;	
    }
}
