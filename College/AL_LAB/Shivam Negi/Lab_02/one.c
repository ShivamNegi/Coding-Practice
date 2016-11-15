#include <stdio.h>

int counter = 0;

int gcd(int no1, int no2)
{
 int i;
 if(no1 < no2)
	{
		i = no1;
	}
 else
		i = no2;
 for(i ; i > 0; i--)
	{
		counter++;
		if(no1 % i == 0 && no2 % i == 0)
			return i;
	}
}

int main()
{
 int no1, no2;
 
 scanf(" %d %d", &no1, &no2);

 printf("%d\n", gcd(no1, no2));
 printf("Operation Count: %d\n", counter);

 return 0;
}
