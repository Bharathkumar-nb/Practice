#include <stdio.h>
#include <string.h>

void add(char str1[], char str2[], char result[])
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int bit1 = 0;
	int bit2 = 0;
	int carry = 0;
	int len3 = (len1 > len2) ? len1 : len2;
	int i, j, k;
	result[len3+1] = '\0';
	for (i=len1-1, j=len2-1, k=len3; i>=0 && j>=0; --i, --j, --k)
	{
		bit1 = str1[i] - '0';
		bit2 = str2[j] - '0';
		result[k] = (char)((bit1 ^ bit2 ^ carry) + '0');
		carry = (bit2 && bit1) || (bit1 && carry) || (bit2 && carry);
	}
	while(i>=0)
	{
		bit1 = str1[i]-'0';
		result[k] = (char)((bit1 ^ carry)+'0');
		carry = bit1 && carry;
		--i;
		--k;
	}
	while(j>=0)
	{
		bit1 = str1[j]-'0';
		result[k] = (char)((bit1 ^ carry)+'0');
		carry = bit1 && carry;
		--j;
		--k;
	}
	result[k] = (char)(carry + '0');

}

int main(int argc, char const *argv[])
{
	char str1[] = "1111";
	char str2[] = "1111";
	char result[10];
	add(str1, str2, result);
	printf("%s\n", result);
	
	return 0;
}