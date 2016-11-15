#include <stdio.h>

int fib(int no)
{
 if(no <= 1)
	return 1;
 else
	return fib(no - 1) + fib(no - 2); 
}

int main()
{
 int i = 1;
 for(i; i < 20; i++)
	printf("%d\n", fib(i));
 return 0;
}
