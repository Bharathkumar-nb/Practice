#include <stdio.h>
#include <stdlib.h>

struct Queue
{
	int* arr;
	int front;
	int back;
	int size;
};

typedef struct Queue Queue_t;

void queue_init(Queue_t*, int);
void enqueue(Queue_t*, int);
int dequeue(Queue_t*);
int isQueueEmpty(Queue_t*);
int isQueueFull(Queue_t*);

void disp_queue(Queue_t*);