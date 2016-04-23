#include <stdio.h>
#include <stdlib.h>

typedef struct _btreeNode 
{
  int data;
  struct _btreeNode *left;
  struct _btreeNode *right;
  /*add the operate functions here */
  int (*search) (const void *data, const void *key);
} btreeNode;

typedef struct _btree
{
  btreeNode *root;
  int size;  // no of nodes in a btree , can maintain depth/height
  /* operations */
  //int  (*destroyTree) (void *data);
} btree;

/* Interfaces for a binary tree */
void btree_init (btree *tree);
int btree_insert_left (btree *tree, btreeNode *node, int *data);
int btree_insert_right (btree *tree, btreeNode *node, int *data);
int btree_rem_left (btree *tree, btreeNode *node);
int btree_rem_right (btree *tree, btreeNode *node);
btreeNode* btree_search_key (btree *tree, btreeNode *node, int *key);
int  btree_depth (btreeNode *node);

/* tree traversals */
void preorder (btreeNode *node);
void postorder (btreeNode *node);
void inorder (btreeNode *node);

void btree_init (btree *tree) 
{
  tree->size  = 0;
  tree->root = NULL;
  return;
}

int btree_insert_left (btree *tree, btreeNode *node, int *data)
{
  btreeNode *newNode = NULL;
 
  if (node)
  {
    /* empty tree problem */  
    if (tree->size == 0) return -1;
 
    /* must never happen */
    if ( node->left !=NULL ) return -1 ;
  
    if (NULL == (newNode = calloc (1, sizeof (btreeNode))))
      return -1;
   
    newNode->data = *data;
    newNode->left = NULL;
    newNode->right = NULL;
  
    /* link to the left of parent */
    node->left = newNode;
  }
  else return 0;
    /* the concept of passing the tree is to maintain the size */
    tree->size++;
    return 0;
}

int btree_insert_right (btree *tree, btreeNode *node, int *data)
{
  btreeNode *newNode = NULL;
  
  if (node)
  {
    /*empty tree / null tree problem */
    if (tree->size == 0)  return -1; 
    if (node->right !=NULL) return -1;

    if (NULL == (newNode = calloc (1, sizeof (btreeNode))))
      return -1;
  
    newNode->data = *data;
    newNode->left = NULL;
    newNode->right = NULL;
 
    /* link to the right of the node */ 
    node->right = newNode;
  }
  else return 0;
  
  /* maintain the tree size */ 
  tree->size++;
  return 0;
}

int btree_rem_left (btree *tree, btreeNode *node)
{
  btreeNode *leftNode =  NULL;
  /* check for empty tree problem */
  if (tree->size == 0)   return -1;
  
  if (node == NULL) return -1;
  
  leftNode = node->left;

  if (leftNode)
  {   
    /*recursively remove the whole subtree for that node */ 
    /* postOrder traversal */
    btree_rem_left (tree, leftNode->left);
    btree_rem_right (tree, leftNode->right); 
  }
  
  free (leftNode);
  
  tree->size--;
}

int btree_rem_right (btree *tree, btreeNode *node)
{
  btreeNode *rightNode = NULL;
  
  /* empty tree problem */
  if (tree->size == 0 ) return -1;

  if (node == NULL) return -1;

  rightNode = node->right;

  if (rightNode) 
  {
    btree_rem_left (tree, rightNode);
    btree_rem_right (tree, rightNode);
  }

  free (rightNode);
  
  tree->size--;
}

btreeNode* btree_search_key (btree *tree, btreeNode *node, int *key)
{ 
  if (node)
  {
    if (node->data < *key)
    {
      if (btree_search_key (tree, node->right, key) == NULL)
        if (btree_insert_right (tree, node, key) == -1)
        {
          printf ("Error inserting node in left \n");
          return NULL;
        }
    }
    else if (node->data >  *key) 
    {
      if (btree_search_key (tree, node->left, key) == NULL)
        if (btree_insert_left (tree, node, key) == -1 ) 
        {
          printf ("Error inserting node in left \n");
          return NULL;
        }
    }
    else if (node->data == *key) 
    {
      printf ("Key found %d \n",node->data);
      return node; 
    } else 
      printf ("this is minimum key \n");
  }
  return node;
}

void printInorder (btreeNode *node)
{
  if (node)
  {
    printInorder (node->left);
    printf ("%d\t",node->data);
    printInorder (node->right);
  }
}

void printInorderIterative (btreeNode *node)
{
  /* we use stack to push and pop the elements */
}

void printPreorder (btreeNode *node)
{
  if (node)
  {
    printf("%d\t",  node->data);
    printPreorder (node->left);
    printPreorder (node->right);
  }
}

void printPostorder (btreeNode *node)
{
  if (node)
  {
    printPostorder (node->left);
    printPostorder (node->right);
    printf ("%d\t",node->data);
  }
}

int InsertNode (btree *tree, int data)
{
  if (tree->size == 0 && tree->root == NULL)
  {
    btreeNode *newNode = calloc (1, sizeof (btreeNode)); 
    newNode->data = data;
    newNode->left=NULL;
    newNode->right=NULL;    
   
    tree->root = newNode;
    tree->size++;
    return 0; 
  }
  else 
    btree_search_key (tree, tree->root, &data);
}

int  btree_depth (btreeNode *node)
{
  if (!node) return 0;
   
  int leftDepth, rightDepth;
  if (node)
  {
    leftDepth = btree_depth (node->left); 
    rightDepth = btree_depth (node->right);
  }

  if (leftDepth > rightDepth)
    return leftDepth + 1;
  else return rightDepth + 1;
}

void printAllPath (btreeNode *root, int *a, int index)
{
  if (root)
  {
    a[index] = root->data;
    printAllPath (root->left, a, index+1);
    printAllPath (root->right, a, index+1);
  }
  else 
  {
    int i =0;
    while (i <= index )
    {
      printf ("%d ",a[i]);
      i++;
    }
    printf ("\n"); 
  }
}

void main ()
{
  char c;
  int key, depth, i = 0;
  int a[20];
  btree maintree;
  btree *tree = NULL;
  tree = &maintree; 
  btree_init (tree);
  while (1) {
    printf ("\n\nEnter your choice \n");
    puts (" 1. Insert a Node ");
    puts (" 2. print Inorder ");
    puts (" 3. print Postorder ");
    puts (" 4. print Preorder");
    puts (" 5. print ALLorder ");
    puts (" 6. Inorder Iteratively ");
    puts (" 7. Preorder Iteratively ");
    puts (" 6. Search a key ");
    puts (" 7. Depth of tree ");
    puts (" 8. path of a tree ");
    if (scanf ("%d",&i) == 1 ) 
    {
    switch (i)
    {
      case 1:
        printf ("Enter a number:");
        scanf ("%d",&key);
        printf ("\n you entered %d",key);
        InsertNode (tree, key);
        break;
      case 2:
        printInorder (tree->root);
        break;
      case 3: 
        printPostorder (tree->root);
        break;
      case 4:
        printPreorder (tree->root);
        break;
      case 5:
        puts("\nInorder");
        printInorder (tree->root);
        puts("\nPreorder");
        printPreorder (tree->root);
        puts("\nPostorder");
        printPostorder (tree->root);
        break;
      case 6:
        printf ("Enter key value to be searched ");
        scanf ("%d",&key);
        btree_search_key (tree, tree->root, &key);
        break;
      case 7:
        depth = btree_depth (tree->root);
        printf ("Depth of tree is %d\n", depth);
        break;
      case 8:
        printAllPath (tree->root, a, 0);
	break;
      default:
        puts("Error \n");
    }
  } 
} 
}
