#include <stdio.h>

int same(int u[], int M)
{
	int ret = u[0];
	for (int i = 1; i < M; ++i)
	{
		if(u[i] != ret)
			return -1;
	}
	return ret;

}

int minimum(int u[], int M)
{
	int min = u[0];
	for (int i = 1; i < M; ++i)
	{
		if(min > u[i])
			min = u[i];
	}
	return min;
}

void ancestor(int u[], int p[], int M)
{
	int ca;
	if((ca = same(u, M)) != -1)
		printf("%d\n", ca);
	else
	{
		int min = minimum(u, M);
		for (int i = 0; i < M ; ++i)
		{
			if(u[i] > min)
			    u[i] = p[u[i]];
		}
		ancestor(u, p, M);
	}
}

int main(int argc, char const *argv[])
{
	int N, M;
	scanf("%d",&N);
	int p[N];
	p[0] = 0;
	for (int i = 1; i < N; ++i)
	{
		scanf("%d",&p[i]);
	}
	scanf("%d",&M);
	int u[M];
	for (int i = 0; i < M; ++i)
	{
		scanf("%d",&u[i]);
	}
	ancestor(u, p, M);

	return 0;
}