#include "stack.h"

void stack_init(Stack_t *s, int n)
{
	s->arr = (int*)malloc(sizeof(int)*n);
	s->top = 0;
	s->size = n;
}

void push(Stack_t *s, int val)
{
	if(!isStackFull(s))
		s->arr[s->top++] = val;
}

int pop(Stack_t* s)
{
	if(!isStackEmpty(s))
		return s->arr[--s->top];
	else
		return -1;
}

int isStackEmpty(Stack_t *s)
{
	return s->top == 0;
}

int isStackFull(Stack_t *s)
{
	return s->top == s->size;
}

void disp_stack(Stack_t* s)
{
	if(isStackEmpty(s))
		printf("Stack Empty\n");
	for (int i = 0; i < s->top; ++i)
	{
		printf("%d ", s->arr[i]);
	}
	printf("\n");
}