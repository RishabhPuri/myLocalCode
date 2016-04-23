#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** 
 * A Threaded Binary search tree is used for inorder recursion
 * Inorder recursion take a lot of space (on stack) and using 
 * Auxilliary ds like stack again takes some space.  == height of tree 
 * Threaded Binary tree doesnt take up space during inorder traversal
 * Its of 2 types 
 * 1. Single threaded binary tree -  NULL right child pointers point to inorder successor.
 * 2. Double threaded binary tree -  NULL right child pointers point to inorder successor 
 *								  -  NULL left child pointers point to inorder predecessor.
 * Now we can in while loop calculate inorder successor , but then that defeats the purpose of doing everything in O(1) space.
 * So we first parse the tree and create a threaded binary tree and once created inorder traversal takes O(1) space complexity.
 * */

#define True   1
#define False  0

typedef  struct node {
	struct node *left;
	struct node *right;
	int data;
	bool bThread;
} node ;

typedef struct q {
	void **info;
	int front , rear ;
	int size;
} Q;

void createThreadBst (node *root, Q *q);
node* leftMost (node *root);
void InOrderFillQ (node *root, Q *q);
int countTreeNode (node *root);

void enQ (void *root, Q *q);
void* deQ (Q *q);
Q *initQ (int size);
bool isQFull (Q *q);
bool isQEmpty (Q *q);

bool isQFull (Q *q)
{
	return (((q->rear+1)%q->size) == q->front);
}

bool isQEmpty (Q *q)
{
	return (q->rear == q->front);
}
 
Q* initQ(int size)
{
	Q* qtemp = NULL;

	if (NULL == (qtemp = (calloc (size, sizeof (char *))))) { printf ("calloc error \n"); return;}
	
	*(qtemp->info) = qtemp;

	qtemp->front = qtemp->rear = -1;	

	qtemp->size = size+1;
}

void enQ (void *node, Q* q)
{
	if ( isQFull (q)) return ;

	q->rear = (q->rear+1) % q->size;

	q->info[(q->rear)] = node;
}

void *deQ (Q *q)
{
	void *node = NULL;

	if ( isQEmpty (q)) return;

	q->front = (q->front+1) % q->size;

	node  = q->info[q->front] ;
}

node* leftMost (node *root)
{
	if (!root) return;
	
	while (root->left)
		root = root->left;

	return root;
}

int countTreeNode (node *root)
{
	if (!root) return 0;
	
	return (countTreeNode (root->left) + countTreeNode (root->right) + 1);
}

void InOrderFillQ (node *root, Q *q)
{
	if (! root) return;
	
	InOrderFillQ (root->left, q);
	enQ (root, q);	
	InOrderFillQ (root->right, q);	
}

void createThreadBst (node *root, Q *q)
{
	if ( !root) return;
	
	createThreadBst (root->left, q);

	deQ (q);

	if (root->right)
		createThreadBst (root->right, q);
	else 
	{
		root->right = q->info[q->front];
		root->bThread = True;
	}
}

void InOrderThread (node *root)
{
	if (!root) return;

	root = leftMost (root);

	while (root)
	{
		if (root->bThread)
			root = root->right;
		else 
			root =  leftMost (root->right);
	}
}

void main ()
{


}
