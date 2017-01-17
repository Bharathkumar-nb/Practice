#include "tree_traversal.h"

void bfs_traversal(Node_t* t, int n)
{
	Queue_t q;
	queue_init(&q, n);
	enqueue(&q, t);
	while(!isQueueEmpty(&q))
	{
		Node_t* temp = dequeue(&q);
		printf("%d ", temp->key);
		if(temp->left)
			enqueue(&q, temp->left);
		if(temp->right)
			enqueue(&q, temp->right);
	}
	printf("\n");
}

void zigzag_traversal(Node_t* t, int n)
{
	ZQueue_t q;
	ZQueue_t final;
	zqueue_init(&q, n);
	zqueue_init(&final, n);
	Enc_t * capsule = (Enc_t*)malloc(sizeof(Enc_t));
	capsule->node = t;
	capsule->order = 'R';
	zenqueue(&q, capsule);
	while(!isZQueueEmpty(&q))
	{
		Enc_t* temp = zdequeue(&q);
		zenqueue(&final, temp);
		if(temp->node->left)
		{
			Enc_t* temp1 = (Enc_t*)malloc(sizeof(Enc_t));
			temp1->node = temp->node->left;
			temp1->order = (temp->order == 'R') ? 'L' : 'R';
			zenqueue(&q, temp1);
		}
		if(temp->node->right)
		{
			Enc_t* temp1 = (Enc_t*)malloc(sizeof(Enc_t));
			temp1->node = temp->node->right;
			temp1->order = (temp->order == 'R') ? 'L' : 'R';
			zenqueue(&q, temp1);
		}
	}
	disp_zqueue(&final);
}

void dfs_traversal(Node_t* t) // preorder traversal
{
	if(t)
	{
		printf("%d ", t->key);
		dfs_traversal(t->left);
		dfs_traversal(t->right);
	}
}

int main(int argc, char const *argv[])
{
	Tree_t t;
	int no_of_nodes;
	init(&t);
	no_of_nodes = create_tree(&t);
	printf("\nbfs_traversal :\n");
	bfs_traversal(t.root, no_of_nodes);
	printf("\nzigzag_traversal :\n");
	zigzag_traversal(t.root, no_of_nodes);
	printf("\ndfs_traversal :\n");
	dfs_traversal(t.root);
	printf("\n");
	printf("\n");
	return 0;
}