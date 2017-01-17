#include <stdio.h>
void init(int a[], int n)
{
	int i;
	for(i = 1; i <= n; ++i)
		a[i] = i;
}
void disp(int a[], int n, int count)
{
	int i;
	printf("%4d : ", count);
	for(i = 1; i <= n; ++i)
		printf("%3d", a[i]);
	printf("\n");
}
int gen_next(int a[], int n)
{
	int k = n - 1;
	int i; int j;
	int l = n;
	int temp;
	while (k >= 1 && a[k] > a[k + 1])
		--k;
	if(k == 0)
		return 0;
	while(a[k] > a[l])
		--l;
//	printf("k : %d l : %d\n", k, l);
	temp = a[k]; a[k] = a[l]; a[l] = temp;
	
	//reverse a[k + 1] to a[n]
	for(i = k + 1, j = n; i < j; ++i, --j)
	{
		temp = a[i]; a[i] = a[j]; a[j] = temp;
	}
	return 1;
}
int main()
{
	int n  = 5;
	int a[10];
	int count = 0;
	init(a, n); disp(a, n, ++count);  
	while(gen_next(a, n))
	{
		disp(a, n, ++count);  
	}
	return 0;

}
/*
The following algorithm generates the next permutation lexicographically after a given permutation. It changes the given permutation in-place.
Find the largest index k such that a[k] < a[k + 1]. 
If no such index exists, the permutation is the last permutation.
Find the largest index l such that a[k] < a[l].
swap a[k], a[l]
Reverse the sequence from a[k + 1] up to and including the final element a[n].
*/