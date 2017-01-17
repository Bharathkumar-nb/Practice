#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int key;
	struct Node *prev;
	struct Node *next;
};

typedef struct Node Node_t;

struct List
{
	Node_t *head;
};

typedef struct List List_t;

void init(List_t *l)
{
	l->head = NULL;
}

Node_t* convert(Node_t *begin)
{

}

void listToBST(List_t *l)
{
	
	l->head = convert(l->head);
}

void inorder_disp(Node_t *root)
{
	inorder_disp(root->prev);
	printf("%d\n", root->key);
	inorder_disp(root->next);
}

void addNodeAtBeginning(List_t *l, int key)
{
	Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));
	newNode->key = key;
	newNode->prev = newNode->next = newNode;
	if (l->head == NULL)
	{
		l->head = newNode;
	}
	else
	{
		newNode->next = l->head;
		newNode->prev = l->head->prev;
		l->head->prev = l->head->prev->next = newNode;
		l->head = newNode;
	}
}

void removeNode(List_t *l, int key)
{
	if (l->head)
	{
		Node_t *temp = l->head;
		do
		{
			if (temp->key == key)
			{
				if (temp == l->head)
				{
					if (l->head == l->head->next)
					{
						l->head = NULL;	
					}
					else
					{
						l->head = temp->next;
					}
				}
				temp->next->prev = temp->prev;
				temp->prev->next = temp->next;
				free(temp);
				temp = NULL;
				break;
			}
			temp = temp->next;
		}while(temp != l->head);
	}
}

void disp(List_t *l)
{
	if(l->head)
	{
		Node_t* temp = l->head;
		do{
			printf("%d\n", temp->key);
			temp = temp->next;
		}while(temp != l->head);
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	List_t l;
	init(&l);
	for (int i = 5; i > 0; --i)
	{
		addNodeAtBeginning(&l, i);
	}
	disp(&l);
	removeNode(&l, 5);
	disp(&l);
	listToBST(&l);
	inorder_disp(l->head);

	return 0;
}