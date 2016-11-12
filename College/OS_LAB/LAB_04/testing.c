#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
 pid_t pid = fork();
 if(pid == 0)
	printf("Child process created\n");
 else
	printf("Parent process remains\n");
 return 0;
}
