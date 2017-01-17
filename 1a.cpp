#include<iostream>
using namespace std ;

int binary(int a[] , int i , int n , int val)
{
	if(i<=n)
	{
		int mid = (i+n)/2;
		if(a[mid] == val)
			return mid;
		if(a[mid] < val)
			return binary(a, mid+1, n, val);
		else
			return binary(a, i, mid-1, val);
	}
	return -1;
}

int main()
{
	int n ;
	cin >> n ;
	int val;
	cin >> val;
	int a[100];
	
	int sum =0 ;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	int pos = sum % n;

	cout << "pos = " << pos << endl ;
	int search = binary(a , pos , n-1 , val) ;
	if(search == -1)
	{
		search = binary(a , 0 , pos-1 , val) ;
		
	}
		cout << "position -1 indicates not found.." << endl ;

		cout << "search element found at " << search << endl ;
}
