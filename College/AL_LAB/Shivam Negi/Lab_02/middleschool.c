#include <stdio.h>

int counter = 2;

int gcd(int no1, int no2)
{
 int res = 1, i = 2;
 while(no1 > i && no2 > i)
	{
		counter++;
		if(no1 % i == 0 && no2 % i == 0)
			{
				res *= i;
				no1 /= i;
				no2 /= i;
			}
 		else
			i++;
	}
 return res;
}


int main()
{
 int no1, no2;
 scanf(" %d %d", &no1, &no2);

 printf("The gcd is: %d\n", gcd(no1, no2));
 printf("The Operation Count is: %d\n", counter);
 return 0;
}

