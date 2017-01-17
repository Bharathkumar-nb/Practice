#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	int c = 6;
	const int a  = 5;
	//a = 10;
	
	const int* b;
	b = &c;
	b = &a;
	//*b = 8;		- Error
	//*b = 8;
	
	// int *d = &a;  //- warning
	//*d = 7;
	//cout << a << " " << *d; - prints 5 7

	int const* e = &a;
	// *e = 10;

	//int *const f = &a; //-error
	//f = &a;
	//*f = 7;
	//cout << a << " " << *f;	- prints 5 7
	
	switch(5);

	return 0;
}