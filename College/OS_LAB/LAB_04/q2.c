#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
	int status;
	pid_t pid;
	pid=fork();
	if(pid==-1)
	printf("\n Error child not created");
	else if (pid==0)
	{
		printf("Im the child\n");
		exit(0);
	}
	else
	{
		wait(&status);
		printf("Im the parent\n");
		printf("Child returned: %d",status);
	}
}
