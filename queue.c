#include "queue.h"

void queue_init(Queue_t* q, int n)
{
	q->size = n;
	q->front = q->back = 0;
	q->arr = (int *)malloc(sizeof(int)*n);
}

void enqueue(Queue_t* q, int val)
{
	if(!isQueueFull(q))
		q->arr[q->back++] = val;
}

int dequeue(Queue_t* q)
{
	if(!isQueueEmpty(q))
		return q->arr[q->front++];
	else
		return -1;
}
int isQueueEmpty(Queue_t* q)
{
	return q->front == q->back;
}

int isQueueFull(Queue_t* q)
{
	return q->back == q->size;
}

void disp_queue(Queue_t* q)
{
	if(isQueueEmpty(q))
	{
		printf("Empty queue\n");
	}
	else
	{
		for (int i = q->front; i < q->back; ++i)
		{
			printf("%d ", q->arr[i]);
		}
		printf("\n");
	}

}