#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
};
typedef struct Node Node_t;

struct Tree
{
	Node_t* root;
};
typedef struct Tree Tree_t;

void init(Tree_t* );
int create_tree(Tree_t*);
Node_t* insert(Node_t *, Node_t* );
void inorder_disp(Node_t*);
void del(Node_t* );
