#include<stdio.h> 

int find1stOccurance(int inputArr[], int arrSize, int key)
{
	int l = 0, r = arrSize-1;
	int result = -1;
	while (l <= r) 
	{
		//Middle element
		int m = (l + r) / 2;
		
		//If the search key on the left half
		if (key < inputArr[m])
		{
			//Update right index
			r = m - 1;
		}
		//If the search key on the right half
		else if (key > inputArr[m])
		{
			//Update the left index
			l = m + 1;
		}
		//We found the key
		else
		{
			result = m;
			r = m - 1;
		}
	}

	//Key was not found
	return result;
}

void main()
{   
   int T, arrSize, key;
   scanf("%d", &T);
   int i, j;
   int inputArr[100];

   for (i = 0; i < T; ++i)
   {
   		scanf("%d", &arrSize);
   		scanf("%d", &key);
   		for (j = 0; j < arrSize; ++j)
   		{
   			scanf("%d", &inputArr[j]);
   		}
   		printf("%d\n", find1stOccurance(inputArr, arrSize, key));
   }
} 
