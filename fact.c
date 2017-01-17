#include <stdio.h>

int main()
{
    int N, n;
    long double fact=1;
    scanf("%d",&N);
    for(int i=0; i<N; ++i)
    {
        scanf("%d",&n);
    	for(long j=n; j>0; --j)
    	{
    		fact = fact * j;
    	}
    	printf("%Lf\n",fact);
        fact = 1;
    }
}