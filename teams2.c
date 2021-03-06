#include <stdio.h>

int partition(int a[] , int start , int end)
{
        int i = start , j = end;
        int pivotElement = a[start];
        int temp;
        do
        {
                while((a[i] <= pivotElement) && i<=j)
                        ++i;
                while((a[j] >  pivotElement) && i<=j)
                        --j;
                temp = a[i];                
				a[i] = a[j];
				a[j] = temp;

        }while(i<=j);
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        temp = a[start];
        a[start] = a[j];
        a[j] = temp;
        return j;
}

void quickSort(int a[] , int start , int end)
{
        if(start < end)
        {
                int pivotPos = partition( a , start , end);
                quickSort( a , start , pivotPos-1);
                quickSort( a , pivotPos+1 , end);
        }
}

int main(int argc, char const *argv[])
{
	int t, n, high, low;
	scanf("%d",&t);
	for (int i = 0; i < t; ++i)
	{
		scanf("%d",&n);
		int a[n];
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&a[j]);
		}
		quickSort(a,0,n-1);
		int teams = n/2;
		int sum[teams];
		for (int j = 0, k=n-1; j < teams; ++j,--k)
		{
			sum[j] = a[j]+a[k];
		}
		high = low = sum[0];

		for (int j = 1; j < teams; ++j)
		{
			if(sum[j] > high)
				high = sum[j];
			if(sum[j] < low)
				low = sum[j];
		}
		printf("%d\n",high-low);
	}
	return 0;
}