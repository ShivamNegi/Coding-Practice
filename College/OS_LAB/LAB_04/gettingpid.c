#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
 pid_t pid;
 pid = fork();
 if(pid == 0)
	{
	printf("Child process ID=%d\n", getpid());
	 return 0;
	}
 printf("The Parent process ID=%d\n", pid);
 return 0;
}
