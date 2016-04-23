#include <stdio.h>
#include <stdlib.h>

typedef signed int Status;

#define Ok 0
#define Error -1

typedef struct _rbtreeNode {
	struct _rbtreeNode *left;
	struct _rbtreeNode *right;
	struct _rbtreeNode *parent;
	void *key;
	void *info;
		
}rbtNode __attribute__((aligned(sizeof(long))));

typedef struct _rbtree {
	void (*cmp)(void *);
	void (*delNode)(void *);
	void (*delTree)(void *);
	rbtNode *nil;
	rbtNode *root;
 	int count;
	int depth;
} rbtree;

Status rbtreeCreate (rbtree **rbtHandle);
void *rbtreeInsertNode (rbtree *rbtHandle, const void *data, const void *key);
void *rbtreeDeleteNode (rbtree *rbtHandle, const void *key);
void *rbtreeDelete (rbtree *rbtHandle);

