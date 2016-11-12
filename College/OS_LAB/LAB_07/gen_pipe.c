#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int isprime(int no)
{
 int i = 2;
 for(i; i <= sqrt(no); i++)
 	{
 		if(no % i == 0)
 			return 0;
 	}
 return 1;
}

void fibonacci(int * a, int n)
{
 int i = 2;

 a[0] = 0;
 a[1] = 1;
 for(i; i < n; i++)
 	{
 	 a[i] = a[i - 1] + a[i - 2];
 	}
}

int main()
{
 int fd[2];
 int out[25];
 
 pipe(fd);
 
 if(fork() > 0)
 	{
 	  int in[25];
 	  read(fd[0], in, sizeof(int) * 25);
 	  
 	  int i = 0;
 	  for(i = 0; i < 25; i++)
 	  	{
 	  		if(isprime(in[i]) > 0 && in[i] > 1)
 	  			printf("%d ", in[i]);
 	  	}
 	}
 else
 	{
 		fibonacci(out, 25);
 		write(fd[1], &out, sizeof(int) * 25);
 		exit(0);
 	}
 printf("\n");
 return 0;
}
