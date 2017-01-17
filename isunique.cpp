#include <iostream> 
#include <cstdio>
#include <cstring> 

using namespace std; 
int main()
{   
  int T;
  char str[100];

  cin >> T;
  for(int i=0; i<T; ++i)
  {

    int charecters[256] = {0}, j=0;
    bool isunique = true ;
    cin >> str;
    int len = strlen(str);
    while(isunique && j<len )
    {
      ++charecters[str[j]];
      if(charecters[str[j]]>1)
      {
        isunique = false;
        break;
      }
      ++j;
    }
    if(isunique)
    {
      cout << "UNIQUE";
    }
    else
    {
      cout << "NOT UNIQUE";
    }
    cout << endl;
  }
} 
