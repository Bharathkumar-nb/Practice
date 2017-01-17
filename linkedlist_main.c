#include "linkedlist.h"

int main(int argc, char const *argv[])
{
	List_t l;
	l.head = NULL;
	insert(&l, 5);
	insert(&l, 6);
	insert(&l, 7);
	insert(&l, 8);
	disp(&l);
	del(&l,5);
	printf("\nAfter removin 5\n");
	disp(&l);
	del(&l,6);
	printf("\nAfter removin 6\n");
	disp(&l);
	del(&l,7);
	printf("\nAfter removin 7\n");
	disp(&l);
	del(&l,8);
	printf("\nAfter removin 8\n");
	disp(&l);
	return 0;
}