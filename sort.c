#include <stdio.h>

void swap(int *x, int* y)
{
	int temp = *x;
	 *x = *y;
	 *y = temp;
}

void bubble_sort(int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void selection_sort(int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		int pos = i;
		for (int j = i+1; j < n; ++j)
		{
			if(a[pos] > a[j])
			{
				pos = j;
			}
		}
		if(i != pos)
		{
			int temp = a[pos];
			a[pos] = a[i];
			a[i] = temp;
		}
	}
}

void insertion_sort(int *a, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int temp = a[i];
		int j = i-1;
		while((j <= 0) && (a[j] < temp))
		{
			a[j+1] = a[j];
		}
	}
}

void merge(int* a, int low, int mid, int high)
{
	int i = low;
	int j = mid+1;
	int k = 0;
	int b[100];
	while(i<=mid && j<=high)
	{
		if(a[i] < a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while(i<=mid)
	{
		b[k++] = a[i++];
	}
	while(j<=high)
	{
		b[k++] = a[j++];
	}
	for (int i = low, k=0; i <= high ; i++,k++)
	{
		a[i] = b[k];
	}
}

void merge_sort(int *a, int low, int high)
{
	if(low < high)
	{
		int mid = (low + high)/2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

int partion(int* a, int low, int high)
{
	int pivot = a[low];
	int i = low;
	int j = high+1;
	do
	{
		do
		{
			i++;
		}while(a[i] < pivot);
		do
		{
			j--;
		}while(a[j] > pivot);
		swap(&a[i], &a[j]);
	}while(j>=i);
	swap(&a[i], &a[j]);
	swap(&a[low], &a[j]);
}

void quick_sort(int *a, int low, int high)
{
	if(low < high)
	{
		int pivot = partion(a, low, high);
		quick_sort(a, low, pivot);
		quick_sort(a, pivot+1, high);
	}
}

void heap_sort(int *a, int n)
{

}

void disp(int *a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main()
{
	int a[100];
	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}

	// bubble_sort(a, n);
	// selection_sort(a, n);
	// insertion_sort(a, n);
	 merge_sort(a, 0, n-1);
	// quick_sort(a, n);
	// heap_sort(a, n);

	disp(a, n);

	return 0;
}