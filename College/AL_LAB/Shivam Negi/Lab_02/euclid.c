#include<stdio.h>
int count;
int euclidGcd(int m, int n)
{
	int r;
	while(n!=0)
	{
		count++;		
		r=m%n;
		m=n;
		n=r;
	}
	return m;
}
int main()
{
	int m,n,r;
	printf("Enter two numbers:\n");
	scanf("%d %d",&m,&n);
	r = euclidGcd(m,n);
	printf("The GCD of %d and %d is: %d\n",m, n, r);
	printf("Program counter is: %d\n", count);
}
