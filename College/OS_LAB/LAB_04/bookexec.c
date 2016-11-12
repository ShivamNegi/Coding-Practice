#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
 pid_t pid;
 pid = fork();
 if(pid < 0)
	{
 	 printf("Fork Failed\n");
	 exit(-1);
	}
 else if(pid == 0)
	{
	 printf("I am good parent\n");
	 execlp("/bin/ls", "ls", NULL);
	}
 else
	{
 	 wait(NULL);
	 printf("Child dead.\n");
	 exit(0);
	}
 return 0;
}
