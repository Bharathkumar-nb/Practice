#include <stdio.h>

int myatoi(char* str)
{
	int ret = 0, val;
	while((*str) && (*str >= '0')  && (*str <= '9'))
	{
		val = *str - 48;
		ret = ret*10 + val;
		str++;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	char str[] = "123abc123";
	printf("%d\n", myatoi(str));
	//printf("%d %d\n", '0','9');
	return 0;
}