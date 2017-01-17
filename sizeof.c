#include <stdio.h>
#include <stdlib.h>

struct a
{
	short a;
	int b;
};

typedef struct a a_t;

void f(const char* x)
{
	x++ ;
	*x = 'a';
} 

int main(int argc, char const *argv[])
{
	short a[5] = {0};
	a_t* var = NULL;
	//var.a = a;
	//printf("%d\n", sizeof(a_t));
	//printf("%d\n", (char*)(var+1)-(char*)var);
	char* str = "hello";
	f(str);
	printf("%s\n",str);
	return 0;
}