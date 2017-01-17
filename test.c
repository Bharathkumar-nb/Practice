#include "stack.h"

int main(int argc, char const *argv[])
{
	Stack_t q;
	stack_init(&q, 5);
	disp_stack(&q);
	push(&q, 1);
	push(&q, 2);
	push(&q, 1);
	push(&q, 2);
	push(&q, 1);
	disp_stack(&q);
	pop(&q);
	disp_stack(&q);
	pop(&q);
	disp_stack(&q);
	pop(&q);
	disp_stack(&q);
	pop(&q);
	disp_stack(&q);
	pop(&q);
	disp_stack(&q);
	pop(&q);
	disp_stack(&q);
	return 0;
}