#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
int main()
{
	int pid=fork();
	if(pid==-1)
	printf("Error\n");
	else if(pid==0)
	{
		exit(0);
	}
	else
	{
		sleep(5);
		printf("Parent awake\n");
	}
return 0;
}
