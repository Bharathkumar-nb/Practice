#include "tree.h"

Node_t* inorder_convert(Node_t* cur, Node_t* prev, Node_t* next)
{
	if (cur == NULL)
	{
		return NULL;
	}
	cur->prev =  inorder_convert(cur->prev, cur, );

}

void TreeToDoublyLinkedList(Tree_t *t)
{
	if(t->head)
		t->head = inorder_convert(t->head, NULL, t->head->right);
}

int main(int argc, char const *argv[])
{
	Tree_t T;
	init(&T);
	create(&T);
	inorder_disp(T->root);
	TreeToDoublyLinkedList(&T);
	disp_list(T->root);
	return 0;
}