#include <stdio.h>
#include <stdlib.h>

int nth_digit(int N,int D,int R)
{
	int i=0;
	int Q, rem;
	do
	{
		do
		{
			if(N == 0 || i == R)
			{
				return 0;
			}
			++i;
			N *= 10;
		}while(N<D);
		Q = N/D;
		N = N%D;
	} while(i<R);
	return Q;
}


int main(int argc, char const *argv[])
{
	int N, D, R;
	int num_of_tc;
	scanf("%d",&num_of_tc);

	for (int i = 0; i < num_of_tc; ++i)
	{
		scanf("%d%d%d",&N,&D,&R);
		printf("%d\n", nth_digit(N,D,R));
	}
	return 0;
}