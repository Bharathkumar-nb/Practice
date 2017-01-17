#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int **matrix1, **matrix2;
	int n = 3, m = 5;
	matrix1 = (int**)malloc(sizeof(int*)*n);
	matrix2 = (int**)malloc(sizeof(int*)*m);

	for (int i = 0; i < n; ++i)
	{
		matrix1[i] = (int*)malloc(sizeof(int*)*n);
	}
	for (int i = 0; i < m; ++i)
	{
		matrix2[i] = (int*)malloc(sizeof(int*)*m);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			matrix1[i][j] = j;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		memcpy ( matrix2[i], matrix1[i], n*sizeof(int));
	}
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%d\t", matrix2[i][j]);
		}
		printf("\n" );
	}

	return 0;
}