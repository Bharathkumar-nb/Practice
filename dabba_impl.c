#include <stdio.h>
int is_all_neg(int a[] , int n)
{
	int i = 0;
	int is_all_neg = 1;
	for(i = 0; i < n && is_all_neg; ++i)
	{
		if(a[i]> 0) 
			is_all_neg = 0;
	}
	return is_all_neg;
}
int max_neg(int a[] , int n)
{
	int min = a[0];
	for(int i = 1; i <n; ++i)
	{
		if(a[i] >  min)
			min = a[i]; 
	}
	return min;
}
int max(int a[], int n)
{
	int i, sum = 0, max = 0;
	if(is_all_neg(a,n))
	{
		return max_neg(a,n);
	}
	if(a[0]<0)
		sum = 0;
	else
		sum = a[0];

	for (int i = 1; i < n; ++i)
	{
		sum += a[i];
		if(sum < 0 )
			sum = 0;
		else
		{
			if(sum > max)
				max = sum;
		}
	}
	return max;
}

int main(int argc, char const *argv[])
{
	int a[] = {-20,-20,-10,-6,-5};
	printf("%d\n", max(a,5));
	return 0;
}