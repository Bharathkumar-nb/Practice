#include <stdio.h>
#include <string.h>

void swap(char * char1, char *char2)
{
	char temp = *char1;
	*char1 = *char2;
	*char2 = temp;
}

void reverseStr(char* inputStr, int lowIndex, int highIndex)
{
	int mid = (highIndex + 1 + lowIndex)/2;
	while(lowIndex < mid)
	{
		swap(&inputStr[lowIndex++], &inputStr[highIndex--]);
	}
}

void reverseWords(char* inputStr)
{
	int strLength = strlen(inputStr)-1;
	

	// reverses the string completely

	reverseStr(inputStr, 0 , strLength);


	// reverses on space break

	int  lowIndex = 0, highIndex = 0;
	while(highIndex <= strLength+1)
	{
		if (inputStr[highIndex] == ' ' || inputStr[highIndex] == '\n' || inputStr[highIndex] == '\0')
		{
			reverseStr(inputStr, lowIndex, highIndex-1);
			lowIndex = highIndex + 1;
			while(inputStr[highIndex] == ' ' || inputStr[highIndex] == '\n' || inputStr[highIndex] == '\0')
				++highIndex;
		}
		else
			++highIndex;
	}

}

void main()
{   
	int T, i;
	scanf("%d", &T);
	char inputStr[100000];
	for (i = 0; i < T; ++i)
	{
		scanf("%s",inputStr);
		
		reverseWords(inputStr);
		printf("%s\n", inputStr);
	}   
}
 
