#include "splayTree.h"

spNode* new (unsigned int key)
{
	spNode *temp = calloc (1, sizeof (spNode));
	temp->left =  temp->right = NULL;
	temp->key = key;
	return temp;
}

spNode* rightRotate (spNode *x)
{
	spNode *y = x->left;
	x->left   = y->right;
	y->right  = x;
	return y;
}

spNode* leftRotate (spNode *x)
{
	spNode *y = x->right;
	x->right  = y->left;
	y->left   = x;
	return y;
}

void preOrder (spNode *root)
{
	if ( ! root) return;
	
	printf ("%d ", root->key);
	preOrder (root->left);
	preOrder (root->right);
} 

spNode* splay (spNode *root, unsigned int key)
{
	if ( ! root || root->key == key) return root;

	if (root->key > key )
	{
		if (root->left->key > key)
		{
			root->left->left = splay (root->left->left, key);	
			root = rightRotate (root);
		}
		else if (root->left->key < key )
		{
			root->left->right =  splay (root->left->right, key);
			if (root->left->right != NULL)
				root->left  = leftRotate (root->left);
		}
		
		return (root->left == NULL) ? root : rightRotate (root);
	}
	else 
	{
		if (root->right == NULL ) return root;	
	
		if (root->right->key < key)
		{
			root->right->right = splay (root->right-right, key);
			root = leftRotate (root);
		}
		else if (root->right->key >  key )
		{
			root->right->left = splay (root->right->left, key);
			if (root->right->left != NULL)
				root = 
		}
	}
}

spNode* insert (spNode *root, unsigned int key)
{

}

main ()
{}
