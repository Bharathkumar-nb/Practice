#include <stdio.h>

void foo(int size ,int a[][size])
{
	printf("%d\n", a[0][0]);
}

/*void bar(int a[][size], int size)
{
	printf("%d\n", a[0][0]);
}*/

int main(int argc, char const *argv[])
{
	int a[5][5] = {0};
	foo(5, a);
	//bar(a, 5);
	return 0;
}