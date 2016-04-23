#include <stdio.h>

typedef struct _node {
  int data;
  struct _node* left;
  struct _node* right;
} Node;

#define maxi(a,b) a>b?a:b
Node* newNode (int val);
Node* insertNode (Node* root, int val);
void printInorder (Node *root);
void sumAllNodeAdd (Node *node, int *pSum);
int height(Node *node);
int LeafLevel(Node *node);

int LeafLevel (Node *node)
{
  if (!node) return 0;
  int llevel = 0;
  llevel = LeafLevel (node->left);
  return llevel + 1;
}

int compareLevel

int height (Node *node)
{
  if(!node) return 0;
   
  int lsum =0, rsum = 0, max = 0;
  lsum = height(node->left);
  rsum = height(node->right);

  max =  maxi (lsum, rsum); 
  return max+1;
}

Node* newNode (int val)
{
  Node *new = calloc (1, sizeof (Node));
  if (!new) return NULL;
  new->data = val;
  new->left = new->right = NULL;
  return new;
}

Node *insertNode (Node *root, int val)
{
  if (!root) return newNode(val);

  if (root->data < val)
    root->right = insertNode (root->right, val); 
  else if (root->data > val )
    root->left = insertNode (root->left, val);

  return root;
  /* dont know about else part i.e when the value would be same */
}

void sumAllNodeAdd (Node *node, int *pSum)
{
   /* reverse inorder processing */
   if (!node) return ;
   
   sumAllNodeAdd (node->right, pSum);
   *pSum += node->data;
   node->data = *pSum;
  
   sumAllNodeAdd (node->left, pSum);
}

void printInorder (Node *root)
{
  if (!root) return ;
  printInorder (root->left);
  printf ("%d ", root->data);
  printInorder (root->right);
  return;
}

void main ()
{
  Node *root = NULL;
  int sum = 0;
  root = insertNode (root, 30);
  insertNode (root, 20);
  insertNode (root, 10);
  insertNode (root, 40);

  printInorder (root);
  printf ("\n");
  sumAllNodeAdd (root, &sum);
  printInorder (root);
  printf ("\n");
  printf ("Height of Tree %d \n",height(root));
   
}
