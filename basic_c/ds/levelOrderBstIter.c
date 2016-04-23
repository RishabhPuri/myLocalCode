#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** level order traversal of bst 
 * 2 methods 
 * 1. iterative 2. use Q  */

/** iterative 
 * 1. get the height of the tree 
 * 2. api to print nodes at each level */

#define max(a,b)  a>b?a:b

typedef struct _node {
	struct _node *left, *right;
	int data;	
} node;

int getHeight (node *root)
{
	int leftHeight, rightHeight;	

	if (!root) return 0;

	leftHeight = getHeight (root->left);
	rightHeight = getHeight (root->right);

	return (1 + max (leftHeight, rightHeight));
}

void printLevel (node *root, int level)
{
	if (!root) return ;	
	
	if (level==1)
		printf ("%d ",root->data);

	printLevel (root->left, level-1);
	printLevel (root->right, level-1);
}

void printLevelOrderIter (node *root)
{
	int level =  getHeight (root);
	
	int i;
	
	for (i=0;i<level;i++)
		printLevel (root, i);
}

#include <stdio.h>
#include <stdlib.h>
 
/* A binary tree node has data, pointer to left child
 *    and a pointer to right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
/*Function protoypes*/
void printGivenLevel(struct node* root, int level);
int height(struct node* node);
struct node* newNode(int data);
 
/* Function to print level order traversal a tree*/
void printLevelOrder(struct node* root)
{
  int h = height(root);
  int i;
  for(i=1; i<=h; i++)
    printGivenLevel(root, i);
}     
 
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
  if(root == NULL)
    return;
  if(level == 1)
    printf("%d ", root->data);
  else if (level > 1)
  {
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
  }
}
 
/* Compute the "height" of a tree -- the number of
 *     nodes along the longest path from the root node
 *         down to the farthest leaf node.*/
int height(struct node* node)
{
   if (node==NULL)
       return 0;
   else
   {
     /* compute the height of each subtree */
     int lheight = height(node->left);
     int rheight = height(node->right);
 
     /* use the larger one */
     if (lheight > rheight)
         return(lheight+1);
     else return(rheight+1);
   }
} 
 
/* Helper function that allocates a new node with the
 *    given data and NULL left and right pointers. */
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
  printf("Level Order traversal of binary tree is \n");
  printLevelOrder(root);
 
  getchar();
  return 0;
}



