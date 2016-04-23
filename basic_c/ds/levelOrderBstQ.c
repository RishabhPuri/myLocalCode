#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/** Q - level order 
 * Idea is enQ root->left and root->right , since its a  Q
 * we deQ left child , print it and then enQ its children
 * something like 
 *
 * level 1    left ---- right 
 * 			  (front)   (rear)
 * level 2    x(l1) ---- right(l1) ---- left(l2) ---- right(l2)
 * 			  deQed      (front)                      (rear) */

typedef struct _node {
    struct _node *left, *right;
    int data;
} node;

struct node** createQueue(int *, int *);
void enQueue(struct node **, int *, struct node *);
struct node *deQueue(struct node **, int *);

/*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear)
{
  struct node **queue =
   (struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);  
 
  *front = *rear = 0;
  return queue;
} 
 
void enQueue(struct node **queue, int *rear, struct node *new_node)
{
  queue[*rear] = new_node;
  (*rear)++;
}     
 
struct node *deQueue(struct node **queue, int *front)
{
  (*front)++;
  return queue[*front - 1];
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

void printLevelOrder (node *root)
{
	if (!root) return;

	int rear, front;
  	struct node **queue = createQueue(&front, &rear);		

	node *temp = root;

	printf ("%d ",root->data);

	while (temp)
	{
		if (temp->left) 
			enQueue (queue, &rear, temp->left);
	
		if (temp->right)
			enQueue (queue, &rear, temp->right);

		temp =  deQueue (root, &front);
	}
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

