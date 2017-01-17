#include <stdio.h>
#include <stdlib.h>

struct Stack
{
	int* arr;
	int top;
	int size;
};

typedef struct Stack Stack_t;

void stack_init(Stack_t *, int);
void push(Stack_t *, int );
int pop(Stack_t*);
int isStackEmpty(Stack_t *);
int isStackFull(Stack_t *);

void disp_stack(Stack_t *);