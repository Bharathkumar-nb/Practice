#include <iostream>
using namespace std;
#include <algorithm>
#include <climits>

void print(int x)
{
	cout << x << "\t";
}
void disp(int* begin, int* end)
{
	for_each(begin, end, print);
	cout << "\n";

}
void swap(int& p, int& q)
{
	int t = p; p = q; q = t;
}
int partition(int a[], int l, int r)
{
	int i; int j;
	int p = a[l];
	i = l; j = r + 1;
	do
	{
		do i = i + 1; while(a[i] < p);
		do j = j - 1; while(a[j] > p);
		swap(a[i], a[j]);
	}
	while (i < j);
	swap(a[i], a[j]);
	swap(a[l], a[j]);
	return j;
}

void qsort(int a[], int l, int r)
{
	if(l < r)
	{
	//		cout << "l : " << l << " r : " << r << "\n";
			int m = partition(a, l, r);
			qsort(a, l, m - 1);
			qsort(a, m + 1, r);
	}
}
int main()
{
//	int a[] = {4, 8, 3, 12, 5, 1, 7, 6, INT_MAX};
//	int a[] = { 8, 7, 6, 5, 4, 3, 2, 1, INT_MAX };
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, , INT_MAX};
	int n = 8;
	
//	random_shuffle(a, a + 8);
	disp(a, a + 8);
	qsort(a, 0, n - 1);
	disp(a, a + 8);

	return 0;
}