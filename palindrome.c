#include<stdio.h> 
#include<string.h>

int isPalindrome(char* inputStr)
{
  int i, j;
  int length = strlen(inputStr);
  int max = length/2;
  int isPal = 1;
  printf("%d\n", length);
  for( i=0,j=length-1; isPal && i<max ; --j,++i)
  {
    if(inputStr[i] != inputStr[j])
      isPal = 0;
  }
  return isPal;
}


void main()
{   
  int n, i;
  char inputStr[100];
  scanf("%d",&n);
  for( i=0; i<n; ++i)
  {
    scanf("%s",inputStr);
    if(isPalindrome(inputStr))
    {
      printf("YES\n");
    }
    else
      printf("NO\n");
  }
    
} 
