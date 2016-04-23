#include <stdio.h>
#include <stdlib.h>

typedef struct sn{
	struct sn *left, *right;
	unsigned int key;
} spNode;

typedef struct {
	spNode *root;
	unsigned int count;	
} splayTree;

spNode* new (unsigned int key);
spNode* rightRotate (spNode *x);
spNode* leftRotate  (spNode *x);
spNode* splay (spNode *root, unsigned int key);
spNode* insert (spNode *root, unsigned int key);
void preorder (spNode *root);

