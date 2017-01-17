#include <iostream>

using namespace std;

long a[10000001];

long find(long n)
{
  if(n>1 && !a[n])
  {
    cout << ((n+1)>>1) - 1 << " " << n - ((n+1)>>1) << endl;
    a[n] = n + find(((n+1)>>1) - 1) + find(n - ((n+1)>>1));
  }
  return a[n];
}

int main(int argc, char const *argv[])
{
  long n;
  int i = 1;
  a[1] = 1;
  while (cin >> n)
  {
    cout << "n = " << n << endl;
    cout << "Case " << i++ << ": " << find(n) << endl;
  }

  return 0;
}