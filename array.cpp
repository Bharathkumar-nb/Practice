#include <iostream>

using namespace std;

template <size_t size>
void disp(int a[][size])
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


template <size_t size>
void foo(int a[][size])
{
	cout << a[0][0] << endl;
}

int main(int argc, char const *argv[])
{
	int n = 3;
	int k = 0;
	int a[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = ++k;
		}
	}
	int size = 5;
	//foo(a);
	disp(a);
	//bar(a, size);
	return 0;
}