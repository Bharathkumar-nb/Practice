#include <stdio.h>
void init(int a[], int n)
{
	int i;
	for(i = 0; i < n; ++i)
	{
		a[i] = i;
	}
}
void disp(int a[], int n, int x, int count)
{
	int i;
	printf("%4d : ", count);
	for(i = 0; i  < n; i ++)
  {
		if(x & (1 << i))
			printf("%3d ", a[i] + 1);
  }
	printf("\n");
}
int main()
{
	int n  = 3;
	int max = 1 << n;
	int i = 0;
	int a[10];
	int count = 0;
	init(a, n);
	while(i < max)
	{
		disp(a,  n, i, ++count);
		++i;
	}
	return 0;

}
// gen all powersets
