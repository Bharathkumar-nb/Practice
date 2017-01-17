#include <stdio.h>
#include "queue.h"


void bfs_traversal(int n, int a[][n])
{
	int visited [n];
	Queue_t q;
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
	queue_init(&q, n*n);
	enqueue(&q, 0);
	visited[0] = 1;
	while(!isQueueEmpty(&q))
	{
		int t = dequeue(&q);
		printf("%d ", t);
		for (int i = 0; i < n; ++i)
		{
			if(a[t][i] && !visited[i])
			{
				visited[i]=1;
				enqueue(&q, i);
			}
		}
	}
	printf("\n");
}

void dfs(int n, int a[][n], int vertex, int *visited)
{
	for (int i = 0; i < n; ++i)
	{
		if(a[vertex][i] && !visited[i])
		{
			printf("%d ", i);			
			visited[i] = 1;
			dfs(n, a, i, visited);
		}
	}
}

void dfs_traversal(int n, int a[][n])
{
	int visited [n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			printf("%d ", i);
			dfs(n, a, i, visited);
		}
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int a[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&a[i][j]);
		}
	}

	bfs_traversal(n, a);
	dfs_traversal(n, a);
	
	return 0;
}