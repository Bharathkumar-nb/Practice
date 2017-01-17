#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
void foo(int x)
{
	cout << x << "\t";
}
template<typename T>
void foo_g(T x)
{
	cout << x << "\t";
}
template<typename InputIterator, typename UnaryOp>
void my_for_each(InputIterator begin, InputIterator end, 
		UnaryOp op)
{
	while(begin != end)
		op(*begin++);
}
struct MyOp
{
	void operator()(int x)
	{
		cout << x << "\t";
	}
};
template<typename T>
struct MyOp_g
{
	void operator()(T x)
	{
		cout << x << "\t";
	}
};

int main()
{
	int a[] = { 25, 5, 333, 9, 111 };
	for_each(a, a + 5, foo);
	cout << "\n";
	//for_each(a, a + 5, foo_g); // NO
	for_each(a, a + 5, foo_g<int>);
	cout << "\n";
	my_for_each(a, a + 5, foo_g<int>);
	cout << "\n";
	my_for_each(a, a + 5, MyOp());
	cout << "\n";
	my_for_each(a, a + 5, MyOp_g<int>());
	cout << "\n";

	//	sort(a, a + 5);

}