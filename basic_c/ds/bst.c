#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define TRUE   1
#define FALSE  0

typedef struct tree {
	struct tree_node *node;
	int max_nodes;
} tree;

typedef struct tree_node {
	struct tree_node *left;
	struct tree_node *right;
	int data;
} node;

node* insert (node *root, int data);
node* find (node *root, int data);
node* delete (node *root, node *n, int data);
node *new(int data);

node *new (int data)
{
	node *temp = NULL;
	if (NULL == (temp = calloc(1, sizeof (node))))
		perror ("calloc error");	
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}

node* insert (node *root, int data)
{
	if (!root)
		return new(data);
	else if (data < root->data)
		root->left = insert (root->left, data);
	else if (data > root->data)
		root->right = insert (root->right, data);

	return root;
}

node *find (node *root, int data)
{
	if (!root) return NULL;

	if (data < root->data)
		return find (root->left, data);
	else if (data > root->data)
		return find (root->right, data);
	else if (data ==  root->data)
		return root;
}

node *minNode (node *root)
{
	if (!root) return NULL;
	
	while (root->left)
		root = root->left;

	return root;
}

node *inorderSuccessor (node *root, node *n)
{
	/** inorder succe :
	 * 	if node->right then leftmost of right subtree min(root->right)
	 * 	else from start first node which is small then this node */
	node *temp = NULL;
	
	if (!n || !root) return temp;

	if (n->right)
	{
		temp =  minNode(n->right);
		return temp;
	}
	else
	{
		temp =  root;
		if (n->data < temp->data)
			temp = temp->left;

		return temp;
	}
}


/** need to pass actual root of the tree , for inorder successor, along with the node to be deleted  */
node* delete (node *root, node *n, int data)
{
	if (!n ) return FALSE;
	
	if (data < n->data)
		n->left = delete (root, n->left, data);
	else if (data > root->data)
		n->right = delete (root, n->right, data);
	else if (data ==  n->data)
	{
		if ((n->left) && (n->right))
		{
			/** find inorder successor , copy contents to current node and delete inord succ */
			node *temp = inorderSuccessor (root, n);
			n->data =  temp->data;
			n->right = delete (root, n->right, temp->data);
			
		}
		else if (n->left)
		{
			node *temp = n->left;
			free (n);
			return temp;
		}
		else if (n->right)
		{
			node *temp = n->right;
			free (n);
			return temp;
		}	
		else if (( !n->left) || (!n->right))
		{
			free (n);
			n = NULL;
		}
	}
	return n;

}

void inorder(node *root)
{
	if  (!root) return;
	
	inorder (root->left);
	printf ("%d ", root->data);
	inorder (root->right);
}

void main ()
{
	/* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
	node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

	printf ("Inorder tree \n");
	inorder (root);	

    printf("\n\n Delete 20\n");
	delete(root, root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\n\n Delete 30\n");
    delete(root, root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
 
    printf("\n\n Delete 50\n");
    delete(root, root, 50);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);
}
