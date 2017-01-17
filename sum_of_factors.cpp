#include<iostream> 
#include<cstdio>
#include<cmath> 

using namespace std; 

long sum_of_Factors(long n)
{
  long sum = 1;  
  int temp = 1;
  int sub = 0;
  int count = 0;
  while (n%2 == 0)
  {
    if(++count%2 == 0)
      sub += 2;
    temp += temp*2;
    n = n/2;
  }
  sum *= temp;
  cout << "2sum : " << sum ; 
  for (int i = 3; i <= sqrt(n); i = i+2)
  {
    int temp = 1;
    count = 0;
  	while (n%i == 0)
    {
      if(++count%2 == 0)
        sub += i;
      temp += temp*i;  
      n = n/i;
    }
    sum *= temp;
    cout << "sum : " << sum ; 
  }
  temp = 1;
  if (n > 2)
  {
    sum *= (n+1);
  }
  return sum-sub;
}



int main()
{   
  int T, power;
  long num;
  cin >> T;
  for(int i=0; i<T; ++i)
  {
    cin >> num;
    cout << " " << sum_of_Factors(num) << endl;
  }
} 
