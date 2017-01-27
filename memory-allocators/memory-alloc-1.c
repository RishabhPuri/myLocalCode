#include "memory-alloc-1.h"

static size_t page_size;

/** add to head list */
void addToFreePool (MEMPOOL_T *pPool, MEMPOOL_NODE *pNode)
{
  
  pNode->next = pPool->head;
  pPool->head = pNode;
  if (!pPool->tail)
    pPool->tail = pNode;
}

/** 
 * Input  : size      - size of mempool_node
 *          numofElem - num od nodes in list 
 * Output : MEMPOOL_T *gPool - global pointer to this pool 
 * */

MEMPOOL_T *mem_pool_init (size_t size, unsigned int numOfElem)
{
  if (page_size==0)
    page_size = getpagesize ();

  /** need to check where I can use the align of 
   *  size = MP_ALIGN_OF (size, 8);
   */

  unsigned int count = (numOfElem * size) + 
                       (numOfElem * sizeof (MEMPOOL_NODE)) + 
                       sizeof (MEMPOOL_T);

  printf ("Required mem %u bytes \n", count);

  //char *pChunk = sbrk (count);
  char *pChunk = calloc (count, sizeof(char));
  char *pChunkCursor = 0x0;

  if (!pChunk)
  {
    printf ("sbrk () error errno:%d",errno);
    return 0x0;
  }

  MEMPOOL_T *ep = 0x0;
  MEMPOOL_NODE *np = 0x0;

    
  
  /** we have the chunk , lets initialize the control block and then list */ 
  ep = (MEMPOOL_T *)pChunk;
  ep->numUsed  = 0;
  ep->maxCount = numOfElem;
  ep->head = ep->tail = 0x0;

  /** Init tail / head */ 
  pChunkCursor = pChunk + sizeof(MEMPOOL_T); 

  np = (MEMPOOL_NODE *)pChunkCursor;
  np->size = 0;
  np->bUsed = False;
  np->next = 0x0;
  *(np->data) = (void *)(pChunkCursor + offsetof (MEMPOOL_NODE, data));
  
  ep->tail = ep->head = np;

#if 0
  ep->tail = (MEMPOOL_NODE *)(pChunkCursor);
  ep->head = (MEMPOOL_NODE *)(pChunkCursor);
  //pChunkCursor = pChunkCursor + offsetof (MEMPOOL_NODE, data);
  pChunkCursor = pChunkCursor + 16;
  ep->tail->data = pChunkCursor;
  ep->head->data = pChunkCursor;
#endif

  for (count = 0, np = ep->head; count < numOfElem; count++)
  {
    pChunkCursor += (sizeof(MEMPOOL_NODE) + 10);
    np = np->next;
    np = (MEMPOOL_NODE *)pChunkCursor;
    addToFreePool (ep, np);
    *(np->data) = (char *)(pChunkCursor + offsetof (MEMPOOL_NODE, data));
  }

  return ep; 
    
}

MEMPOOL_NODE *allocNode (MEMPOOL_T *pPool)
{
   /** start with boundary checks , we only allocate , if we can*/
   if (pPool->numUsed + 1 >= pPool->maxCount)
    return 0x0;
   
   /** unlink from head, add after tail */
   MEMPOOL_NODE *ep = pPool->head;

   pPool->head = pPool->head->next;
   ep->next = pPool->tail;
   pPool->tail = ep;
   pPool->numUsed++;
   ep->bUsed = True; 
   return ep;
}

void free_mem (MEMPOOL_T *pPool, MEMPOOL_NODE *pNode)
{
  pNode->bUsed = False;
  pPool->tail = pNode->next;
  pNode->next = pPool->head;
  pPool->head = pNode;
  pPool->numUsed--;
}

int main (void)
{
  char *cData[] = {"HELLO", "2HELLO", "3HELLO","4HELLO","5HELLO","6HELLO","7HELLO","8HELLO","9HELLO","10HELLO"};

  unsigned int i;
  MEMPOOL_T *pPool = mem_pool_init (40, 10);
  MEMPOOL_NODE *ep;
  for (i=0;i<10;i++)
  {
    ep = allocNode (pPool);
    strcpy ((char*)(ep->data), cData[i]);
  }

  ep = pPool->head;
  for (i=0;i<10;i++)
  {
   
    printf ("%d: %s\n",i, (char*)ep->data);
    free_mem (pPool, ep);
  }

  printf ("no of used entries in pool :%d", pPool->numUsed); 
  free (pPool);
  return 0;
}
