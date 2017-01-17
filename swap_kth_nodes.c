#include "linkedlist.h"

void swap_kth_node(List_t* l, int k)
{
	// to be implemented

	
/*	Node_t *n1, *p1, *n2, *p2, *runner, *tmp;
	runner = l->head;
	if(l->head == NULL)
		return;
	if(k == 1)
	{
		while(runner->next)
		{
			p2 = runner;
			runner = runner->next;
		}
		if(n1 != runner)
		{
			runner->next = l->head->next;
			l->head->next = NULL;
			p2->next = l->head;
			l->head = runner;
		}
	}
	else
	{

	}*/

}

int main(int argc, char const *argv[])
{
	List_t l;
	l.head = NULL;
	int n, k, val;
	scanf("%d",&n);    // no_of_nodes
	scanf("%d",&k);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&val)
		insert(&l, val);
	}
	disp(&l);

	swap_kth_node(&l, k);
	return 0;
}