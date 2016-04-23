#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define uint8_t unsigned char

typedef struct _link {
	struct _link *pA;
	struct _link *pB;
} link; 

struct item {
	link slink;
	uint8_t c;
};

typedef void (*funcPt) (uint8_t *global, int *count, uint8_t data);


void print (uint8_t *global, int *gCount, uint8_t data)
{
	printf ("%d ",data);
}

void count(uint8_t *global, int *gCount, uint8_t data)
{
	*gCount += data;	
}

void occCount (uint8_t *global , int *gCount, uint8_t data)
{
	global[data]++;
}
 
void printOccCount (uint8_t* global, int *gCount, uint8_t data)
{
	printf ("%d %d \n",data, global[data]);
}

void InorderOccur (struct item* root, funcPt *fp, uint8_t *global, int *gCount)
{
	if ( !root) return;

	if (root->slink.pA)
		InorderOccur ((struct item *)root->slink.pA, fp, global, gCount);
	
	fp[3](global, gCount, root->c);
	
	if (root->slink.pB)
		InorderOccur ((struct item *)root->slink.pB, fp, global, gCount);

	return;
}

void InorderPrint (struct item *root, funcPt *fp, int *gCount, uint8_t *global)
{
	if ( !root) return;
	
	InorderPrint ((struct item *)root->slink.pA, fp, gCount, global);
	(fp[0])(NULL, NULL, root->c);	
	(fp[1])(NULL, gCount, root->c);	
	(fp[2])(global, NULL, root->c);	
	InorderPrint ((struct item *) root->slink.pB, fp, gCount, global);
	
}

struct item *createNewNode (uint8_t data)
{
	struct item *temp = NULL;
	if (NULL == (temp = calloc (1, sizeof(struct item))))
	{
		perror ("calloc error" );
		return NULL;
	}

	temp->slink.pA = temp->slink.pB = NULL;
	temp->c = data;

	return temp;
}

struct item *insert (struct item *root, uint8_t data)
{
	if (!root) 
		return createNewNode(data);
	if (data <= root->c)	
		root->slink.pA = (link *)insert ((struct item *) root->slink.pA, data);
	else if (data > root->c)
		root->slink.pB = (link *)insert ((struct item *) root->slink.pB, data);

	return root;
}

void main ()
{
	int gCount = 0;
	uint8_t global[255];
	memset (global, 0, 255);
	funcPt fp[4] = {print, count, occCount, printOccCount};

	struct item* root = NULL;
	root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

	InorderPrint (root, fp, &gCount, global);
	printf ("\ncount of nodes %d \n",gCount);
	InorderOccur (root, fp, global, &gCount);
}
