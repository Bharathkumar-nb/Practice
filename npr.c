#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_function(const void *a,const void *b) {
	char *x = (char *) a;
	char *y = (char *) b;
	return *x - *y;
}

void disp(char a[], int n)
{
	int i;
	for(i = 1; i <= n; ++i)
		printf("%c", a[i]);
}

int gen_next(char a[], int n)
{
	int k = n - 1;
	int i; int j;
	int l = n;
	char temp;
	while (k >= 1 && a[k] >= a[k + 1])
		--k;
	if(k == 0)
		return 0;
	while(a[k] >= a[l])
		--l;
	temp = a[k]; a[k] = a[l]; a[l] = temp;
	
	for(i = k + 1, j = n; i < j; ++i, --j)
	{
		temp = a[i]; a[i] = a[j]; a[j] = temp;
	}
	return 1;
}

int fact(int n)
{
	if (n==0 || n==1)
	{
		return 1;
	}
	else
	{
		return n * fact(n-1);
	}
}

int main()
{
	int T, n, i, r;
	char a[7];
  
  	scanf("%d", &T);
  	for(i = 0; i<T; ++i)
    {
      int count = 1;
      scanf("%s", a+1);
      scanf("%d", &r);
      n = strlen(a+1);
      qsort(a+1, n, sizeof(char), compare_function);
      disp(a, r);  
      while(gen_next(a, n))
      {
        if(count++%(fact(n-r)) == 0)
        {
        	printf("\n");
        	disp(a, r); 
        }
      }
      printf("\n\n");
    }
	return 0;

}