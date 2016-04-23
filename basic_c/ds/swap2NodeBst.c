#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	struct node *left;
	struct node *right;
	int data;
} node;

node *insert (node *root, int data);
void correctBstUtil (node *root);

node *newNode (int data)
{
	node *temp = NULL;
	if (NULL == (temp = calloc (1, sizeof(node))))
		perror ("calloc error");
	
	temp->left = temp->right = NULL;
	temp->data = data;
	
	return temp;
}

node *insert (node *root, int data)
{
	if (!root)
		return newNode(data);
	
	if (data < root->data)
		root->left = insert (root->left, data);
	if (data > root->data)
		root->right = insert (root->right, data);
	
	return root;
}

void correctBst (node *root)
{
	node *first, *last, *middle, *prev;
	correctBstUtil (root, &first, &middle, &last, &prev);
	
	if (middle && last)
		swap (middle, last);
}

void InOrder (node *root)
{
	if (!root) return;
	
	InOrder (root->left);
	printf ("%d ",root->data);
	InOrder (root->right);
}

void main ()
{
	
}
