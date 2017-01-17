#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_function(const void *a,const void *b) {
	char *x = (char *) a;
	char *y = (char *) b;
	return *x - *y;
}

void disp(char a[], int n, int count)
{
	int i;
	for(i = 1; i <= n; ++i)
		printf("%c", a[i]);
	printf(" ");
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

int main()
{
	int T, n, i;
	char a[7];
  
  	scanf("%d", &T);
  	for(i = 0; i<T; ++i)
    {
      int count = 0;
      scanf("%s", a+1);
      n = strlen(a+1);
      qsort(a+1, n, sizeof(char), compare_function);
      disp(a, n, ++count);  
      while(gen_next(a, n))
      {
          disp(a, n, ++count);  
      }
      printf("\n");
    }
	return 0;

}