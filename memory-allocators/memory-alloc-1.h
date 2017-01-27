/** this is a fixed size free list based allocators  */
/** free-list : |hdr| -> |node1| -> |node2| -> |NULL| 
 *  Each node : next, prev, size, used / unused , *mem block 
 *  Each used node shall be removed and appended to back 
 *  head , tail shall point to free list head and tail 
 *  header : ptr to first node, #usedcount, ( a lock ??) */

/**  Most important concept of memory pool  is that a big chunk is reserved of off heap
 *   and then its divided in bins of fixed ( or varying) bins ( list)
 *   Sort of allocating a big chunk for 2d array 
 *
 * Step 1: Init a memory pool 
 *          donot want to use malloc ( as its already a memory allocator 
 *          use sbrk () / brk () system call to initialize
 * Step 2: Check and take care of alignment requirements 
 *          <unistd.h>
 *          getpagesize ()   -- number of bytes in a page  - non portable
 *          sysconf (_SC_PAGESIZE) - portable 
 * Step 3: Mempool and the nodes need to be in shared memory ( for now )
 *
 * Step 4: Make pool nodes 
 *
 * Step 5: Alloc() and free ()
 *
 * Step 6: bookkeeping and stats 
 *    
 *  */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>

#define True  1
#define False 0


typedef struct __MEMPOOL_NODE {
  unsigned int size;   // not needed if fixed ?
  bool bUsed;
  struct __MEMPOOL_NODE *next;
  void **data;  // dont add anything below this 
} MEMPOOL_NODE;

typedef struct __MEMPOOL_T { 
  unsigned int numUsed;
  unsigned int maxCount;
  MEMPOOL_NODE *head, *tail;
} MEMPOOL_T;

#define MP_ALIGN_OF(x,a)  (((x)+(a))-1UL)&(~((a)-1UL))

MEMPOOL_T *mem_pool_init (size_t , unsigned int );
MEMPOOL_NODE *alloc_mem (MEMPOOL_T *) __attribute__((nonnull));
void free_mem (MEMPOOL_T *, MEMPOOL_NODE *ptr)__attribute__((nonnull));



void inline addToFreePool (MEMPOOL_T *, MEMPOOL_NODE *) __attribute__((nonnull, always_inline));



