#include <stdio.h>
#include "tree.h"

Node_t* clone(Node_t* t2, Node_t* t1)
{
	if(t1)
	{
		t2 = (Node_t*)malloc(sizeof(Node_t));
		t2->key = t1->key;
		t2->left = clone(t2->left, t1->left);
		t2->right = clone(t2->right, t1->right);
	}
	return t2;
}

void clone_trees(Tree_t* t2, Tree_t* t1)
{
	init(t2);
	t2->root = clone(t2->root, t1->root);
}

int main(int argc, char const *argv[])
{
	Tree_t t1;
	Tree_t t2;
	init(&t1);
	create_tree(&t1);
	clone_trees(&t2, &t1);
	inorder_disp(t2.root);
	printf("\n");
	del(t1.root);
	del(t2.root);
	return 0;
}