#include "rbtree.h"

Status rbtreeCreate (rbtree **rbtHandle)
{
	Status rc = Error;
	rbtree *temp = NULL;
	rbtNode *tempNode = NULL;

	if (NULL == (temp = calloc (1, sizeof temp)))
	{
		perror ("Error: no memory for treehandle \n");
		return rc;
	}
	
	if (NULL == (tempNode = calloc (1, sizeof *tempNode)))	
	{
		perror ("Error: no memory for sentinel tree node\n");
		return rc;
	}

	/** sentinel node init */	
	/** all pointers (l,r,p) point to sentinel node */
	temp->nil = tempNode->left = tempNode->right = tempNode->parent = tempNode;
	tempNode->key = 0;
	
	if (NULL == (tempNode = calloc (1, sizeof *tempNode)))	
	{
		perror ("Error: no memory for root tree node\n");
		return rc;
	}

	/** root node init */	
	/** all pointers (l,r,p) point to sentinel node */
	tempNode->left = tempNode->right = tempNode->parent = temp->nil;
	tempNode->key = 0;
	temp->root = tempNode;
	
	*rbtHandle = temp;
		
	rc = Ok;
	return rc;
	
}

void rbLeftRotate (rbtree *rbtHandle, rbtNode *node)
{}

void rbRightRotate (rbtree *rbtHandle, rbtNode *node)
{}

void *rbtreeInsertNode (rbtHandle *rbtH, const void *key, const void* data)
{

}

void main ()
{
	rbtNode *root = NULL;

}
