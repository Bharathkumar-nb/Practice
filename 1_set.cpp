// sorted associative container
//		elements are arranged based on some criterion
//		implementation : ht balanced binary search tree
//		not sequential container : concept of ith elem is not
//			meaningful
//		a) set
//				has keys
//				are unique
//		b) multiset
//				keys can repeat
//		c) map
//				has key value pairs
//				keys unique
//		d) multimap
//				keys can repeat
#include <iostream>
using namespace std;
#include <vector>
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
#if 0
// predicate class :  functor class returning a bool
struct MyLess
{
	bool operator()(int x, int y) { return x < y; }
};
#endif
template<typename T>
struct MyLess
{
	bool operator()(const T& x, const T& y) { return x < y; }
};

class MyDate
{
public:
	explicit MyDate(int dd = 1, int mm = 1, int yy = 1970)
		: dd_(dd), mm_(mm), yy_(yy)
	{
	}
	friend ostream& operator<<(ostream&, const MyDate&);
	friend bool operator<(const MyDate&, const MyDate&);
private:
	int dd_;
	int mm_;
	int yy_;
};
bool operator<(const MyDate& x, const MyDate& y)
{
	if(x.yy_ > y.yy_)
		return false;
	else if(x.yy_ == y.yy_ && x.mm_ > y.mm_)
		return false;
	else if(x.yy_ == y.yy_ && x.mm_ == y.mm_ && x.dd_ >= y.dd_)
		return false;
	else
		return true;
}
ostream& operator<<(ostream& o, const MyDate& d)
{
	return o << d.dd_ << "-" << d.mm_ << "-" << d.yy_ ;
}
struct MyPred
{
		bool operator()(int x, int y)
		{
			return x % 10 < y % 10;
		}
};
int main()
{
	 
	int a[] = { 11, 33, 22, 11, 44, 11, 22, 33, 55, 11};
	// a)  deduplication
	// b)  output is in order

	set<int> s1(a, a + 10);
	disp(s1.begin(), s1.end());
	cout << typeid(s1).name() << "\n";
//	set<int, MyLess> s2(a, a + 10);
	set<int, MyLess<int>> s2(a, a + 10);
	disp(s2.begin(), s2.end());
	cout << typeid(s2).name() << "\n";

	int a1[] = { 56, 213, 54, 9, 12, 43, 96, 13};
	set<int, MyPred> s3(a1, a1 + 8);
	disp(s3.begin(), s3.end());
	
	MyDate d[] = { 
		MyDate(15, 8, 1947),
		MyDate(1, 11, 1973),
		MyDate(1, 11, 1956),
		MyDate(16, 12, 1971),
		MyDate(26, 1, 1950)
	};
	disp(d, d + 5);
	vector<MyDate> v(d, d + 5);
	disp(v.begin(), v.end());

	cout << "\n set of dates \n";
//	set<MyDate>  sd1(d, d + 5);
//	set<MyDate, less<MyDate>>  sd1(d, d + 5);
	set<MyDate, MyLess<MyDate>>  sd1(d, d + 5);
	disp(sd1.begin(), sd1.end());

	MyDate d1[] = { 
		MyDate(15, 8, 1947),
		MyDate(16, 12, 1971),
		MyDate(15, 8, 1947),
		MyDate(1, 11, 1973),
		MyDate(15, 8, 1947),
		MyDate(16, 12, 1971),
		MyDate(1, 11, 1973),
		MyDate(1, 11, 1956),
		MyDate(15, 8, 1947),
		MyDate(1, 11, 1973),
		MyDate(16, 12, 1971),
		MyDate(26, 1, 1950)
	};
	set<MyDate>  sd2(d1, d1 + 12);
	disp(sd2.begin(), sd2.end());
	// find
	set<MyDate>::iterator it = sd2.find(MyDate(16, 12, 1971));
	if(it != sd2.end())
		cout << *it << "\n";

	// this would break the logical structure
	//*it = MyDate(21, 12, 2012);

//  requires equality operator in the compenent class
//	it = find(sd2.begin(), sd2.end(), MyDate(16, 12, 1971));

	sd2.insert(MyDate(21, 12, 2012));
	disp(sd2.begin(), sd2.end());
	it = sd2.find(MyDate(16, 12, 1971));
	if(it != sd2.end())
		sd2.erase(it);
	disp(sd2.begin(), sd2.end());
	sd2.erase(MyDate(21, 12, 2012));
	disp(sd2.begin(), sd2.end());
	sd2.erase(MyDate(21, 12, 2012));
	disp(sd2.begin(), sd2.end());
	return 0;
}

// functors :
//		header file called functional
