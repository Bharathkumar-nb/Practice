#include<stdio.h> 

int searchPair(int inputArray[], int arraySize, int key)
{
  int i = 0, j = arraySize-1, count = 0;
  while(i<j)
  {
    if((inputArray[i]+inputArray[j] == key))
    {
      ++count; ++i; --j;
    }
    else if((inputArray[i]+inputArray[j]) > key)
    {
      --j;
    }
    else
    {
      ++i;
    }
  }
  return count;
}

void main()
{   
  int T;
  scanf("%d",&T);
  int i, arraySize, key;
  int inputArray[100];
  for(i = 0; i<T; ++i)
  {
    scanf("%d", &arraySize);
    scanf("%d", &key);
    int j;
    for(j=0; j<arraySize; ++j)
    {
    	scanf("%d", &inputArray[j]);
    }
    printf("%d\n", searchPair(inputArray, arraySize, key));
  }
} 