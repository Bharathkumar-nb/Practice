#include <stdio.h>
#include "tree.h"

Node_t* convert(Node_t* node, Node_t* par)
{
	if(node)
	{
		node->left = convert(node->left, node);
		if(!node->right)
		{
			node->right = par;
		}
		node->right = convert(node->right, node);
		if(!node->left)
		{
			node->left = pa
		}
	}
	return node;
}

void convert_to_dllist(Tree_t* t)
{
	convert(t->root, NULL);
}


int main(int argc, char const *argv[])
{
	Tree_t t;
	init(&t);
	create_tree(&t);
	convert_to_dllist(&t);
	return 0;
}