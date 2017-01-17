#include <iostream>
using namespace std;
#include <set>
#include <algorithm>
#include <typeinfo>
template<typename ptr_t>
void disp(ptr_t begin, ptr_t end)
{
		while(begin != end)
		{
			cout << *begin++ << "\t";
		}
		cout << "\n";
}
int main()
{
	// put numbers from 2 to n into a sieve
	int n = 48615;
	set<int> s;
	set<int> p;
	set<int>::iterator it;
	for(int i = 2; i <= n; ++i)
		s.insert(i);
	// repeat until sieve becomes empty
	while (! s.empty())
	{
		// find the smallest element and call it a prime
		int prime = *s.begin();
		//cout << prime << "\t";
		p.insert(prime);
		// remove its multiples
		for(int j = prime; j <= n; j += prime)
		{
			s.erase(j);
		}
	}
	cout << p.size() << endl;
//	disp(p.begin(), p.end());

}