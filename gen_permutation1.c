#include <stdio.h>
void init(int a[], int dir[], int n)
{
	int i;
	for(i = 0; i <= n; ++i)
	{
		a[i] = i;
		dir[i] = 0; // R to L
	}
}
void disp(int a[], int dir[], int n, int count)
{
	int i;
	printf("%4d : ", count);
	for(i = 1; i <= n; ++i)
		printf("%3d %c  ", a[i], dir[i]? '>' : '<');
	printf("\n");
}
int gen_next(int a[], int dir[], int n)
{
	int i;
	int k = 0;
	int temp;
	// find biggest k such that a[k] > a[k + 1] if dir[k] = 1
	//                          a[k] < a[k - 1] if dir[k] = 0
	for(i = 1; i <= n; ++i)
	{
		// right to left
		if(dir[i] == 0 && i > 1 && a[i] > a[i - 1] && a[i] > a[k])
			k = i;
		if(dir[i] == 1 && i < n && a[i] > a[i + 1] && a[i] > a[k])
			k = i;
	}
	if (k == 0)
		return 0;
	//printf("k : %d\n", k);
	for(i = 1; i <= n; ++i)
		if(a[i] > a[k])
			dir[i] = ! dir[i];
	if(dir[k] == 0)
	{
		temp = a[k]; a[k] = a[k - 1]; a[k - 1] = temp;
		temp = dir[k]; dir[k] = dir[k - 1]; dir[k - 1] = temp;
	}
	else
	{
		temp = a[k]; a[k] = a[k + 1]; a[k + 1] = temp;
		temp = dir[k]; dir[k] = dir[k + 1]; dir[k + 1] = temp;
	}
	return 1;
}
int main()
{
	int n = 4;
	int a[10];
	int dir[10]; // RtoL : 0; LtoR : 1
	int count = 0;
	init(a, dir, n); disp(a, dir, n, ++count);
	while(gen_next(a, dir, n))
	{
		disp(a, dir, n, ++count);
	}
	return 0;

}
// Johnson Trotter
// while last permutation has a mobile element
//		find the largest mobile element k
//		swap k and its adjacent element based on direction
//		reverse the direction of elements greater than k
//		add this permutation to the result
