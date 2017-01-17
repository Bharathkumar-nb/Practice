#include<stdio.h> 
#include<string.h>

int findPalLength(int* curPos, char* inputStr, int strLength)
{
	int PalLength = 1;
	int i, j;
	i = j = *curPos;
	
	while((j + 1 < strLength) && inputStr[j + 1] == inputStr[*curPos])
	{
		++PalLength;
		++j;
	}
	if (j-i > 0)
	{
		*curPos = j+1;
	}
	else
	{
		++(*curPos);
	}
	while( (--i>=0) && (++j<strLength) && (inputStr[i] == inputStr[j]))
	{
		PalLength += 2;
	}
	return PalLength;
}

int findLargestPal(char* inputStr)
{
	int i = 0;
	int maxPalindromeLength = 1;
	int strLength = strlen(inputStr);
	while ( i < strLength)
	{
		int palindromeLength = findPalLength(&i, inputStr, strLength);
		if(palindromeLength > maxPalindromeLength)
			maxPalindromeLength = palindromeLength;
	}
	return maxPalindromeLength;
}


int main()
{   
  int n, i;
  char inputStr[100];
  scanf("%d",&n);
  for( i=0; i<n; ++i)
  {
    scanf("%s",inputStr);
    printf("%d\n", findLargestPal(inputStr));
  }
  return 0;	
} 