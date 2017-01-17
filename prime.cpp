#include<iostream> 
#include<cstdio>
#include<cmath> 

using namespace std; 
int main()
{   
  int N, j, sr;
  long num;
  cin >> N;
  for(int i=0; i<N; ++i)
  {
    bool isprime = true;
    cin >> num;
    if (num < 2)
    {
      cout << "NOT PRIME";
    }
    else
    {
      sr = sqrt(num);
      for(j=sr; isprime && j>=2;--j)
      {
        if(num % j == 0)
          isprime = false;
      }
      isprime ? cout << "PRIME" : cout << "NOT PRIME";
    }
    cout << endl;
  }
  
} 
