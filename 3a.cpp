#include <iostream>

using namespace std;

void disp(int n, int a[][n])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> a[i][j];
		}
	}

	//disp(n, a);

	for (int i = 0; i < n/2; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int temp = a[i][j];
			a[i][j] = a[n-1-i][n-1-j];
			a[n-1-i][n-1-j] = temp;
		}
	}
	if(n%2 == 1)
	{
		int i = 0 ;
		int j = n-1 ;
		while(i < j)
		{
			int temp = a[n/2][i];
			a[n/2][i] = a[n/2][j];
			a[n/2][j] = temp;

			i++ ;
			j-- ;
		}
	
	}
	//disp(n, a);

	return 0;
}