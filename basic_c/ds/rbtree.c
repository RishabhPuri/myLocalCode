#include <stdio.h>
#include <stdbool.h>

enum rbcolor{
	red, 
	black
};

typedef struct rbtreeNode {
	struct rbtreeNode *left, *right, *parent;
	int data;
	enum rbcolor color;
} node;

typedef struct rbtree {
	struct rbtreeNode *root;
	struct rbtreeNode *nil;
	int (*comp) (int *a, int *b);
} tree;
