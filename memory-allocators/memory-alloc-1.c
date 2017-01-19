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

  printf ("Required mem %u kb \n", count/1000);

  char *pChunk = sbrk (count);

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
  ep->tail = ep->head = (MEMPOOL_NODE *)(pChunk + sizeof(MEMPOOL_T));

  for (count = 0, np = ep->head; count < size; count++)
  {
    np->next =  np + sizeof(MEMPOOL_NODE);
    addToFreePool (ep, np);
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
   return ep;
}

void free_mem (MEMPOOL_T *pPool, MEMPOOL_NODE *pNode)
{
  pPool->tail = pNode->next;
  pNode->next = pPool->head;
  pPool->head = pNode;
  pPool->numUsed--;
}

int main ()
{
  return 0;
}
