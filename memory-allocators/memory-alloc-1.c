#include "memory-alloc-1.h"

static size_t page_size;

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

  unsigned int count = ( numOfElem * size ) + sizeof (MEMPOOL_T);
  printf ("Required mem %u kb \n", count/1000);

  MEMPOOL_T *ep = sbrk (poolSize );

  if (!ep)
    printf ("sbrk () error errno:%d",errno);
  
  /** we have the chunk , lets initialize the control block and then list */ 
  ep->numUsed  = 0;
  ep->maxCount = numOfElem;
  ep->head = ep->tail = 0x0;

  /** Init head */
  ep->head = 

  for (count=0; count<numOfElem; count++)
 
    
}
