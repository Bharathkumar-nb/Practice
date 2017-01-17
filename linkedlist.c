#include "linkedlist.h"

/*			// Takes &l as param where l is ptr
void insert(List_t **l, int data)
{
	Node* tmp = (*l)->head;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	if(tmp == NULL)
	{
		(*l)->head = n;
	}
	else 
	{
		while(tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = n;
	}
}

void disp ( List_t** l)
{
	if((*l)->head == NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		Node* tmp = (*l)->head;
		while(tmp)
		{
			printf("%d\n", tmp->data);
			tmp = tmp->next;
		}
	}
}

*/

/*				// Takes l as param where l is ptr 

void insert(List_t *l, int data)
{
	Node* tmp = (l)->head;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	if(tmp == NULL)
	{
		(l)->head = n;
	}
	else 
	{
		while(tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = n;
	}
}

void disp ( List_t* l)
{
	if((l)->head == NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		Node* tmp = (l)->head;
		while(tmp)
		{
			printf("%d\n", tmp->data);
			tmp = tmp->next;
		}
	}
}
*/



// Takes &l as param where l is not ptr 

void insert(List_t *l, int data)
{
	Node* tmp = (l)->head;
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	if(tmp == NULL)
	{
		(l)->head = n;
	}
	else 
	{
		while(tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = n;
	}
}

void disp ( List_t* l)
{
	if((l)->head == NULL)
	{
		printf("Empty List\n");
	}
	else
	{
		Node* tmp = (l)->head;
		while(tmp)
		{
			printf("%d\n", tmp->data);
			tmp = tmp->next;
		}
	}
}

void del(List_t* l, int data)
{
	Node *prev = l->head, *cur = l->head;
	while(cur)
	{
		if(cur->data == data)
		{
			if(prev == l->head)
				l->head = cur->next;
			else
				prev->next = cur->next;
			free(cur);
			cur = NULL;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	printf("%d not found\n", data);
}

