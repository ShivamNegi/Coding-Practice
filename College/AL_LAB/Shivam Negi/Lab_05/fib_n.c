#include <stdio.h>

int fib(int n)
{
 if(n <= 1)
 	return n;
 else
 	return fib(n - 1) + fib(n - 2);
}

int main()
{
 int n;
 printf("Enter the value of n: ");
 scanf(" %d", &n);
 
 printf("The nth fibo is %d.\n", fib(n));
 return 0;
}
