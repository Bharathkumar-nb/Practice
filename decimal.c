#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nth_digit(int N,int D,int R)
{
	int i=-1;
	int Q, rem;
	do
	{
		
		{
			if(N == 0 || i == R)
			{
				printf("N=0 %d ", i);
				return 0;
			}
			++i;
			N *= 10;
		}while(N<D);
		Q = N/D;
		N = N%D;
		++i;
	} while(i<R);
	printf("i=R %d ", i);
	return Q;
}


int main(int argc, char const *argv[])
{
	
	FILE* fp = fopen("testcases.txt", "r");

	char temp[25];
	int N, D, R;
	int num_of_tc = atoi(fgets(temp,10,fp));
	printf("%d\n", num_of_tc);

	for (int i = 0; i < num_of_tc; ++i)
	{
		fgets(temp,24,fp);
		sscanf(temp,"%d %d %d",&N,&D,&R);
		printf("%d\n", nth_digit(N, D, R));
	}
	fclose(fp);
	return 0;
}