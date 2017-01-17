#include <stdio.h>
#include "tree.h"


Node_t* arr_to_tree(Node_t* t, int *a, int low, int high)
{
	if(high >= low)
	{
		int mid = (high + low)/2;
		t = (Node_t*)malloc(sizeof(Node_t));
		t->key = a[mid];
		t->left = arr_to_tree(t->left, a, low, mid-1);
		t->right = arr_to_tree(t->right, a, mid+1, high);
		return t;
	}
	else
		return NULL;
}

int main(int argc, char const *argv[])
{
	Tree_t t;
	init(&t);
	int a[] = {1,2,3,4,5,6,7,8,9};
	t.root = arr_to_tree(t.root, a, 0, 8);
	inorder_disp(t.root);
	printf("\n");
	return 0;
}