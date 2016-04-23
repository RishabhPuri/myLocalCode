#include <stdio.h>

typedef struct btree {
  int a;
  struct btree *left;
  struct btree *right;
} bNode; 

typedef struct _stack {
   int a[10];
   int head;
} Stack;

Stack* stackInit (void);
void push (Stack*, int);
int pop (Stack *);
#define max(a,b)  a > b ? a : b

bNode* newNode (int a);
bNode* pruneUtil (bNode *, int);
bNode *pruneTree (bNode *, int , int *);
void printInorderTree (bNode *);
int sizeofTree (bNode *node);
int maxDepth (bNode *node);
int LCA (bNode *node, int n1, int n2); 
void LeftView (bNode *node, int, int*);
void LevelOrderTraversal (bNode *node, int, int*, Stack *s); 

Stack* stackInit (void )
{
  Stack* s = calloc (1, sizeof(Stack));
  s->head = -1;
  return s;
}

void push (Stack *s, int value)
{
    s->head++;
    s->a[s->head] = value; 
}

int pop (Stack *s)
{ 
   return s->a[s->head--];
}

void LevelOrderTraversal (bNode *node, int thisLevel, int* treeLevel, Stack *s)
{
  if (!node) return;

  if (thisLevel > *treeLevel)
  {
    push (s, node->a);
    printf ("%d ",pop (s));
    *treeLevel =  thisLevel;
  }
  
  LevelOrderTraversal (node->right, thisLevel+1, treeLevel, s);
  LevelOrderTraversal (node->left, thisLevel+1, treeLevel, s);
}

void LeftView (bNode *node, int thisLevel, int *treeLevel)
{
  if (!node) return;
  if (*treeLevel < thisLevel) 
  {
      printf ("%d ", node->a);
     *treeLevel = thisLevel;
  }
  LeftView (node->left, thisLevel+1, treeLevel);
  LeftView (node->right, thisLevel+1, treeLevel);
}
int LCA (bNode *node, int n1, int n2)
{
  if (!node) return 0;

  /* if node value is more than n1 , n2 then we go to left part 
   * of tree, gareeb part of the tree 
   * */
  int ret = 0;   
  if (node->a > n1 && node->a > n2)
     ret = LCA (node->left, n1, n2);
  
  if (node->a < n1 && node->a < n2)
     ret = LCA (node->right, n1, n2);
  
  if ((node->a < n1 && node->a > n2) 
        || (node->a > n1 && node->a < n2))
      ret = node->a;

  return ret;
}

int maxDepth (bNode *node)
{
  if (!node) return 0;
  int lDepth = 0, rDepth = 0;
  lDepth  = maxDepth (node->left);
  rDepth = maxDepth (node->right);

  return (lDepth > rDepth ? lDepth + 1 : rDepth + 1);
}

int sizeofTree (bNode *node)
{
  if (!node) return 0;
  return sizeofTree (node->left) + sizeofTree (node->right) + 1;
}

bNode * newNode (int a)
{
  bNode *new = NULL;
  new =  calloc (1, sizeof (bNode));
  if (new)
  {
    new->a = a;
    new->left = new->right = NULL;
  }
  return new;
}

bNode * pruneUtil (bNode *root , int sum)
{
  int k = 0;
  return pruneTree (root, sum, &k);
}

bNode * pruneTree (bNode* root, int sum, int *lrsum)
{
  if (!root) return NULL; 
 
  int lsum = 0, rsum = 0; 
  lsum = *lrsum + root->a; 
  rsum = lsum;
  root->left  = pruneTree (root->left, sum, &lsum);
  root->right = pruneTree (root->right, sum, &rsum); 
  
  *lrsum = max (lsum, rsum);

  if (sum > *lrsum)
  {
    free (root);
    root = NULL;
  }
  return root;
}

void printInorderTree (bNode *r)
{
  if (!r) return;
  printInorderTree (r->left);
  printf ("%d ", r->a);
  printInorderTree (r->right);
}

void printPreorder (bNode *r)
{
  if (!r) return;
  printf ("%d ", r->a);
  printPreorder (r->left);
  printPreorder (r->right);
}

void main ()
{
  int sum = 45;
  bNode *root = NULL;
#if 0
  root = newNode (1);
  root->left = newNode (2); 
  root->right = newNode (3); 
  root->left->left = newNode (4); 
  root->left->right = newNode (5); 
  root->right->left = newNode (6); 
  root->right->right = newNode (7); 
  root->left->left->left = newNode (8); 
  root->left->left->right = newNode (9);   
  root->left->right->left = newNode (10); 
  root->right->right->left = newNode (11); 
  root->right->right->left->right = newNode (12); 
  root->left->left->right->left = newNode (13); 
  root->left->left->right->right = newNode (14); 
  root->left->left->right->right->left = newNode (15); 
 
  printf ("\n Tree Before pruning "); 
  //printInorderTree (root);
  printPreorder (root);
  root  = pruneUtil (root, sum);
  printf ("\n Tree after pruning "); 
  //printInorderTree (root);
  printPreorder (root);
  printf ("\n");
#endif
  
  int treeLevel = 0;
  root = newNode (20);
  root->left = newNode (8);
  root->right = newNode (22);
  root->left->left = newNode (4);
  root->left->right = newNode (12);
  root->left->right->left = newNode (10);
  root->left->right->right = newNode (14);
  printf ("Size of Tree %d \n",sizeofTree (root));
  printf ("Depth of Tree %d \n",maxDepth(root));
  printf ("LCA of 10 & 14 %d \n",LCA (root, 10, 14));
  printf ("LCA of 14 & 14 %d \n",LCA (root, 14, 14));
  printf ("LCA of 10 & 22 %d \n",LCA (root, 10, 22));
  printf ("Left view \n");
  LeftView (root, 1, &treeLevel);
  printf ("\n Level Order \n");
  treeLevel = 0;
  Stack *s = NULL;
  s = stackInit ();  
  LevelOrderTraversal (root, 1, &treeLevel, s);
}
