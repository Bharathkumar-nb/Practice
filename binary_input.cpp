#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, result;
	cin >> n;
	long total, temp;
	total = 1<<n;

	for (long i = 0; i < total; ++i)
	{
		result = 0xffffffff;
		temp = i;
		for (int j = 0; j < n; ++j)
		{
			if (temp&1)
			{
				cout << "1 ";
			}
			else
			{
				cout << "0 ";
			}
			result &= (temp&1);
			temp >>= 1;
		}
		cout << " = " << result << endl;
	}
	return 0;
}