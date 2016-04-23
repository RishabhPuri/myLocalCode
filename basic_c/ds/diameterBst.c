#include <stdio.h>
typedef struct node {
	int data;
	struct node *left, *right;
} node ;

int max(int a, int b)
{
	return a>b?a:b;
}

int height (node *root)
{
	if (!root) return;
		
	int lht, rht;
	lht = height (root->left);
	rht = height (root->right);

	return 1+max(lht,rht);	
}

int diameter (node *root)
{
	if (!root) return;
	
	int lht  = height(root->left);
	int rht  = height(root->right);
	
	printf ("max ht %d\n", lht+rht);

	int ldia = diameter(root->left);
	int rdia = diameter(root->right);
	
	return max(1+rht+lht, max(ldia, rdia));

}

node *newNode (int data)
{
	node *temp = calloc (1, sizeof(node));
	temp->data = data;
	temp->right = temp->left = NULL;

	return temp;
}




void main ()
{
	node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf ("diameter is %d",diameter(root));
}
