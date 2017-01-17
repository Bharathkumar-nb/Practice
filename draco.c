#include <stdio.h>
#include <tgmath.h>

int main()
{
	int t;
	long n;
	scanf("%d",&t);
	for (int i = 0; i < t; ++i)
	{
		  scanf("%ld",&n);
		  
		  printf("%0.00f\n", n*(log(n)-1)/log(10));
	}
	return 0;
}