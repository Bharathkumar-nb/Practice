#include "tree.h"

void init(Tree_t* t)
{
	t->root = NULL;
}

int create_tree(Tree_t* t)
{
	int n, val;
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&val);
		Node_t* temp = (Node_t*)malloc(sizeof(Node_t));
		temp->key = val;
		temp->left = temp->right = NULL;
		t->root = insert(t->root, temp);
	}
	return n;
}

Node_t* insert(Node_t *root, Node_t* temp)
{
	if(root == NULL)
	{
		root = temp;
	}
	else if(temp->key < root->key)
	{
		root->left = insert(root->left, temp);
	}
	else
	{
		root->right = insert(root->right, temp);
	}
	return root;
}

void inorder_disp(Node_t* root)
{
	if(root)
	{
		inorder_disp(root->left);
		printf("%d ", root->key);
		inorder_disp(root->right);
	}
}

void del(Node_t* root)
{
	if(root)
	{
		del(root->left);
		del(root->right);
		free(root);
	}
}