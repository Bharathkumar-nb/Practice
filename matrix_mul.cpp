#include<iostream> 
#include<cstdio>
#include<cmath> 

using namespace std; 
int main()
{   
  int T, i, j, k, sum;
  int r1, r2, c1, c2;
  int a[50][50] = {0}, b[50][50]={0};
  
  cin >> T;
  for(i=0; i<T; ++i)
  {
    cin >> r1 >> c1;
    for(j=0; j<r1; ++j)
      for(k=0; k<c1; ++k)
        cin >> a[j][k];
    cin >> r2 >> c2;
    for(j=0; j<r2; ++j)
      for(k=0; k<c2; ++k)
        cin >> b[j][k];
    

    for(j=0; j<r1; ++j)
    {
        
      for(k=0; k<c2; ++k)
        {
          sum = 0;
          for(int p=0; p<r2; ++p)
            {
              sum += a[j][p] * b[p][k];
            }
            cout << sum;
            k!=c2-1 ? cout << " " : cout << endl;
        }
    }
    
  }
} 
