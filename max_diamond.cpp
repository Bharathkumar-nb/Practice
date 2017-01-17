#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef tuple<int, int, int> iii;

const int N = 100010;
int n, d, a[N];
ll t[N];
iii tr[N];
map<int, int> m;

void upd(int i, ll x)
{
  for (; i <= d; i += i & -i) t[i] = max(t[i], x);
}  

ll get(int i)
{
  ll s = 0;
  for (; i; i -= i & -i) s = max(s, t[i]);
  return s;
}

int main() {

  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
  {
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    a[i] = y;
    tr[i] = (iii) {x, y, z};
  }
  sort(a + 1, a + n + 1);
  m[a[1]] = d = 1;
  for (int i = 2; i <= n; i++)
    if (a[i] != a[i - 1]) m[a[i]] = ++d;

  sort(tr + 1, tr + n + 1);
  
  for (int k = 1; k <= n; ++k)
  {
    cout << get<0>(tr[k]) << " " << get<1>(tr[k]) << " " << get<2>(tr[k]) << endl; 
  }

  for (int k = 1; k <= n; ++k)
  {
    cout << a[k] << endl;
  }

  for (int i = 1; i <= n; i++)
  {
    cout << "Printing t[]" << endl;
    for (int j = 0; j < n; ++j)
    {
      cout << t[j] << endl;
    }
    cout << "End" << endl;
    int y = m[get<1>(tr[i])], w = get<2>(tr[i]);
    upd(y, get(y) + w);
  }
  printf("%lld", get(d));
  return 0;
}