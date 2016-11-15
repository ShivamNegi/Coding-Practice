#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int counter = 0;
bool isprime(int no);

void get100prime(int a[])
{
 int counter = 0, i = 2;

 while(counter <= 100)
	{
		if(isprime(i))
			a[counter++] = i;
		i++;
	}
}

bool isprime(int no)
{
 int i = 2;
 for(i; i <= sqrt(no); i++)
	if (no % i == 0)
		return false;
	return true;
}

void primescount(int primes[], int a[], int no)
{
 int i = 0;
 while(no  > 1)
	{
		 while(no % primes[i] == 0)
			{
				counter ++;
				a[primes[i]]++;
				no /= primes[i];
			}
		i++;
	}
}

void clear(int a[], int size)
{
 int i = 0;
 for(i; i < size; i++)
	a[i] = 0;
}

int main()
{
 int no1, no2;
 scanf(" %d %d", &no1, &no2);

 int primes[100], no1_fac[1000], no2_fac[1000];

 get100prime(primes);
 clear(no1_fac, 1000);
 clear(no2_fac, 1000);	

 int save_counter = 0;

 primescount(primes, no1_fac, no1);
 // if(no1 > no2)
	// save_counter = counter;
 // counter = 0;
 primescount(primes, no2_fac, no2);
 // if(save_counter)
	// counter = save_counter;

 int i = 2;
 long int mul = 1;
 for(i; i < 1000; i++)
	{
	 int minno;
  	 if(no1_fac[i] < no2_fac[i])
		minno = no1_fac[i];
	 else
		minno = no2_fac[i];
	 mul = mul * (pow(i, minno));
	}

 printf("%ld\n", mul);
 printf("The Operation Count is: %d\n", counter);
 return 0;
}

